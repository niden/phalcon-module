
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Parsers;

/**
 * Proxy class for accessing C parser
 */
class Volt
{
    /**
     * Parse the view code
     */
    public function parse(string viewCode, string currentPath) -> string
    {
        return phvolt_parse_view(viewCode, currentPath);
    }
}
