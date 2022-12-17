
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input;

use Phalcon\Html\Exception;

/**
 * Class Textarea
 */
class Textarea extends AbstractInput
{
    /**
     * @var string
     */
    protected type = "textarea";

    /**
     * Returns the HTML for the input.
     *
     * @return string
     * @throws Exception
     */
    public function __toString()
    {
        var value;
        array attributes;

        let attributes       = this->attributes,
            this->attributes = [];

        if !fetch value, attributes["value"] {
            let value = "";
        }

        unset attributes["type"];
        unset attributes["value"];

        return this->renderFullElement(
            this->type,
            value,
            attributes
        );
    }
}
