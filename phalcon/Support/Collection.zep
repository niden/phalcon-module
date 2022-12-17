
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support;

use ArrayAccess;
use ArrayIterator;
use Countable;
use IteratorAggregate;
use InvalidArgumentException; // @todo this will also be removed when traits are available
use JsonSerializable;
use Phalcon\Support\Collection\CollectionInterface;
use Serializable;
use Traversable;

/**
 * `Phalcon\Support\Collection` is a supercharged object oriented array. It implements:
 * - [ArrayAccess](https://www.php.net/manual/en/class.arrayaccess.php)
 * - [Countable](https://www.php.net/manual/en/class.countable.php)
 * - [IteratorAggregate](https://www.php.net/manual/en/class.iteratoraggregate.php)
 * - [JsonSerializable](https://www.php.net/manual/en/class.jsonserializable.php)
 * - [Serializable](https://www.php.net/manual/en/class.serializable.php)
 *
 * It can be used in any part of the application that needs collection of data
 * Such implementations are for instance accessing globals `$_GET`, `$_POST`
 * etc.
 *
 * @property array $data
 * @property bool  $insensitive
 * @property array $lowerKeys
 */
class Collection implements
    ArrayAccess,
    CollectionInterface,
    Countable,
    IteratorAggregate,
    JsonSerializable,
    Serializable
{
    /**
     * @var array
     */
    protected data = [];

    /**
     * @var bool
     */
    protected insensitive = true;

    /**
     * @var array
     */
    protected lowerKeys = [];

    /**
     * Collection constructor.
     */
    public function __construct(array data = [], bool insensitive = true)
    {
        let this->insensitive = insensitive;
        this->init(data);
    }

    /**
     * Magic getter to get an element from the collection
     */
    public function __get(string element) -> var
    {
        return this->get(element);
    }

    /**
     * Magic isset to check whether an element exists or not
     */
    public function __isset(string element) -> bool
    {
        return this->has(element);
    }

    /**
     * Magic setter to assign values to an element
     */
    public function __set(string element, value) -> void
    {
        this->set(element, value);
    }

    /**
     * Magic unset to remove an element from the collection
     */
    public function __unset(string element) -> void
    {
        this->remove(element);
    }

    /**
     * Clears the internal collection
     */
    public function clear() -> void
    {
        let this->data      = [],
            this->lowerKeys = [];
    }

    /**
     * Count elements of an object.
     * See [count](https://php.net/manual/en/countable.count.php)
     */
    public function count() -> int
    {
        return count(this->data);
    }

    /**
     * Get the element from the collection
     */
    public function get(
        string element,
        var defaultValue = null,
        string! cast = null
    ) -> var {
        var key, value;

        let element = this->processKey(element);

        /**
         * If the key is not set, return the default value
         */
        if unlikely true !== isset(this->lowerKeys[element]) {
            return defaultValue;
        }

        let key   = this->lowerKeys[element],
            value = this->data[key];

        /**
         * If the key is set and is `null` then return the default
         * value also. This aligns with 3.x behavior
         */
        if unlikely (null === value) {
            return defaultValue;
        }

        if unlikely cast {
            settype(value, cast);
        }

        return value;
    }

    /**
     * Returns the iterator of the class
     */
    public function getIterator() -> <Traversable>
    {
        return new ArrayIterator(this->data);
    }

    /**
     * Return the keys as an array
     */
    public function getKeys(bool insensitive = true) -> array
    {
        array collection;

        let collection = (insensitive === true) ? this->lowerKeys : this->data;

        return array_keys(collection);
    }

    /**
     * Return the values as an array
     */
    public function getValues() -> array
    {
        return array_values(this->data);
    }

    /**
     * Determines whether an element is present in the collection.
     */
    public function has(string element) -> bool
    {
        let element = this->processKey(element);

        return isset this->lowerKeys[element];
    }

    /**
     * Initialize internal array
     */
    public function init(array data = []) -> void
    {
        var key, value;

        for key, value in data {
            this->setData(key, value);
        }
    }

    /**
     * Specify data which should be serialized to JSON
     * See [jsonSerialize](https://php.net/manual/en/jsonserializable.jsonserialize.php)
     */
    public function jsonSerialize() -> array
    {
        var key, value;
        array records;

        let records = [];

        for key, value in this->data {
            if typeof value == "object" && method_exists(value, "jsonSerialize") {
                let records[key] = value->{"jsonSerialize"}();
            } else {
                let records[key] = value;
            }
        }

        return records;
    }

    /**
     * Whether a offset exists
     * See [offsetExists](https://php.net/manual/en/arrayaccess.offsetexists.php)
     */
    public function offsetExists(mixed element) -> bool
    {
        let element = (string) element;

        return this->has(element);
    }

    /**
     * Offset to retrieve
     * See [offsetGet](https://php.net/manual/en/arrayaccess.offsetget.php)
     */
    public function offsetGet(mixed element) -> mixed
    {
        let element = (string) element;

        return this->get(element);
    }

    /**
     * Offset to set
     * See [offsetSet](https://php.net/manual/en/arrayaccess.offsetset.php)
     */
    public function offsetSet(mixed element, mixed value) -> void
    {
        let element = (string) element;

        this->set(element, value);
    }

    /**
     * Offset to unset
     * See [offsetUnset](https://php.net/manual/en/arrayaccess.offsetunset.php)
     */
    public function offsetUnset(mixed element) -> void
    {
        let element = (string) element;

        this->remove(element);
    }

    /**
     * Delete the element from the collection
     */
    public function remove(string element) -> void
    {
        var key;
        array lowerKeys, data;

        if likely this->has(element) {
            let element   = this->processKey(element),
                data      = this->data,
                lowerKeys = this->lowerKeys,
                key       = lowerKeys[element];

            unset lowerKeys[element];
            unset data[key];

            let this->data      = data,
                this->lowerKeys = lowerKeys;
        }
    }

    /**
     * Set an element in the collection
     */
    public function set(string element, var value) -> void
    {
        this->setData(element, value);
    }

    /**
     * String representation of object
     * See [serialize](https://php.net/manual/en/serializable.serialize.php)
     */
    public function serialize() -> string
    {
        return serialize(this->toArray());
    }

    /**
     * Returns the object in an array format
     */
    public function toArray() -> array
    {
        return this->data;
    }

    /**
     * Returns the object in a JSON format
     *
     * The default string uses the following options for json_encode
     *
     * `JSON_HEX_TAG`, `JSON_HEX_APOS`, `JSON_HEX_AMP`, `JSON_HEX_QUOT`,
     * `JSON_UNESCAPED_SLASHES`
     *
     * See [rfc4627](https://www.ietf.org/rfc/rfc4627.txt)
     */
    public function toJson(int options = 4194383) -> string
    {
        var result;

        let result = this->phpJsonEncode(this->jsonSerialize(), options);

        if (false === result) {
            let result = "";
        }

        return result;
    }

    /**
     * Constructs the object
     * See [unserialize](https://php.net/manual/en/serializable.unserialize.php)
     */
    public function unserialize(string serialized) -> void
    {
        var data;

        let data = unserialize(serialized);

        this->init(data);
    }

    public function __serialize() -> array
    {
        return this->toArray();
    }

    public function __unserialize(array data) -> void
    {
        this->init(data);
    }

    /**
     * Internal method to set data
     */
    protected function setData(string element, var value) -> void
    {
        var key;

        let key                  = this->processKey(element),
            this->data[element]  = value,
            this->lowerKeys[key] = element;
    }

    /**
     * @todo to be removed when we get traits
     */
    protected function phpJsonEncode(var value, int flags = 0, int depth = 512)
    {
        return json_encode(value, flags, depth);
    }

    /**
     * Checks if we need insensitive keys and if so, converts the element to
     * lowercase
     */
    protected function processKey(string element) -> string
    {
        if likely this->insensitive {
            return mb_strtolower(element);
        }

        return element;
    }
}
