
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Engine;

use Phalcon\Di\DiInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Html\Link\Link;
use Phalcon\Html\Link\Serializer\Header;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Exception;

/**
 * Designer friendly and fast template engine for PHP written in Zephir/C
 */
class Volt extends AbstractEngine implements EventsAwareInterface
{
    /**
     * @var Compiler
     */
    protected compiler;

    /**
     * @var ManagerInterface|null
     */
    protected eventsManager;

    /**
     * @var array
     */
    protected macros = [];

    /**
     * @var array
     */
    protected options = [];

    /**
     * Checks if a macro is defined and calls it
     *
     * @params string name
     * @params array arguments
     *
     * @return mixed
     */
    public function callMacro(string! name, array arguments = []) -> var
    {
        var macro;

        if unlikely !fetch macro, this->macros[name] {
            throw new Exception("Macro '" . name . "' does not exist");
        }

        return call_user_func(macro, arguments);
    }

    /**
     * Performs a string conversion
     *
     * @return string
     */
    public function convertEncoding(string text, string! from, string! to) -> string
    {
        /**
         * Try to use utf8_encode if conversion is 'latin1' to 'utf8'
         */
        if from === "latin1" || to === "utf8" {
            return utf8_encode(text);
        }

        /**
         * Try to use utf8_decode if conversion is 'utf8' to 'latin1'
         */
        if to === "latin1" || from === "utf8" {
            return utf8_decode(text);
        }

        /**
         * Fallback to mb_convert_encoding
         */
        if function_exists("mb_convert_encoding") {
            return mb_convert_encoding(text, from, to);
        }

        /**
         * There are no enough extensions available
         */
        throw new Exception(
            "'mbstring' is required to perform the charset conversion"
        );
    }

    /**
     * Returns the Volt's compiler
     *
     * @return Compiler
     */
    public function getCompiler() -> <Compiler>
    {
        var compiler, container, options;

        let compiler = this->compiler;

        if typeof compiler !== "object" {
            let compiler = new Compiler(this->view);

            /**
             * Pass the IoC to the compiler only of it's an object
             */
            let container = <DiInterface> this->container;

            if typeof container == "object" {
                compiler->setDi(container);
            }

            /**
             * Pass the options to the compiler only if they're an array
             */
            let options = this->options;

            if typeof options == "array" {
                compiler->setOptions(options);
            }

            let this->compiler = compiler;
        }

        return compiler;
    }

    /**
     * Returns the internal event manager
     *
     * @return ManagerInterface|null
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Return Volt's options
     *
     * @return array
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Checks if the needle is included in the haystack
     *
     * @param mixed needle
     * @param array|string haystack
     *
     * @return bool
     */
    public function isIncluded(var needle, var haystack) -> bool
    {
        if unlikely null === needle {
            let needle = "";
        }

        if typeof haystack == "array" {
            return in_array(needle, haystack);
        }

        if typeof haystack == "string" {
            if function_exists("mb_strpos") {
                return mb_strpos(haystack, needle) !== false;
            }

            return strpos(haystack, needle) !== false;
        }

        throw new Exception("Invalid haystack");
    }

    /**
     * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
     *
     * @param mixed item
     *
     * @return int
     */
    public function length(var item) -> int
    {
        if unlikely null === item {
            let item = "";
        }

        if typeof item == "object" || typeof item == "array" {
            return count(item);
        }

        if function_exists("mb_strlen") {
            return mb_strlen(item);
        }

        return strlen(item);
    }

    /**
     * Parses the preload element passed and sets the necessary link headers
     * @todo find a better way to handle this
     */
    public function preload(var parameters) -> string
    {
        var attributes, container, header, href, link, params, response;

        let params = [];

        if typeof parameters !== "array" {
            let params = [parameters];
        } else {
            let params = parameters;
        }

        /**
         * Grab the element
         */
        fetch href, params[0];

        let container = this->container;

        /**
         * Check if we have the response object in the container
         */
        if container->has("response") {
            if isset params[1] {
                let attributes = params[1];
            } else {
                let attributes = ["as" : "style"];
            }

            /**
             * href comes wrapped with ''. Remove them
             */
            let response = container->get("response"),
                link     = new Link(
                    "preload",
                    str_replace("'", "", href),
                    attributes
                ),
                header   = "Link: " . (new Header())->serialize([link]);

            response->setRawHeader(header);
        }

        return href;
    }

    /**
     * Renders a view using the template engine
     *
     * @param string path
     * @param mixed params
     * @params bool mustClean
     *
     * @return void
     */
    public function render(string! path, var params, bool mustClean = false) // TODO: Make params array
    {
        var compiler, compiledTemplatePath, eventsManager, key, value;

        if mustClean {
            ob_clean();
        }

        /**
         * The compilation process is done by Phalcon\Mvc\View\Engine\Volt\Compiler
         */
        let compiler      = this->getCompiler(),
            eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            if eventsManager->fire("view:beforeCompile", this) === false {
                return null;
            }
        }

        compiler->compile(path);

        if typeof eventsManager == "object" {
            if eventsManager->fire("view:afterCompile", this) === false {
                return null;
            }
        }

        let compiledTemplatePath = compiler->getCompiledTemplatePath();

        /**
         * Export the variables the current symbol table
         */
        if typeof params == "array" {
            for key, value in params {
                let {key} = value;
            }
        }

        require compiledTemplatePath;

        if mustClean {
            this->view->setContent(ob_get_contents());
        }
    }

    /**
     * Sets the events manager
     *
     * @param ManagerInterface eventsManager
     *
     * @return void
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Set Volt's options
     *
     * @param array options
     *
     * @return void
     */
    public function setOptions(array! options)
    {
        let this->options = options;
    }

    /**
     * Extracts a slice from a string/array/traversable object value
     */
    public function slice(var value, int start = 0, var end = null)
    {
        var length;
        array slice;
        int position;

        /**
         * Objects must implement a Traversable interface
         */
        if typeof value == "object" {
            if end === null {
                let end = count(value) - 1;
            }

            let position = 0,
                slice = [];

            value->rewind();

            while value->valid() {
                if position >= start && position <= end {
                    let slice[] = value->current();
                }

                value->next();

                let position++;
            }

            return slice;
        }

        /**
         * Calculate the slice length
         */
        if end !== null {
            let length = (end - start) + 1;
        } else {
            let length = null;
        }

        /**
         * Use array_slice on arrays
         */
        if typeof value == "array" {
            return array_slice(value, start, length);
        }

        /**
         * Use mb_substr if available
         */
        if function_exists("mb_substr") {
            if length !== null {
                return mb_substr(value, start, length);
            }

            return mb_substr(value, start);
        }

        /**
         * Use the standard substr function
         */
        if length !== null {
            return substr(value, start, length);
        }

        return substr(value, start);
    }

    /**
     * Sorts an array
     */
    public function sort(array value) -> array
    {
        asort(value);

        return value;
    }
}
