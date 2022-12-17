
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
class Annotations
{
    /**
     * Parse annotations
     */
    public static function parse(
        string docBlock,
        string file,
        int line) -> array
    {
        return phannot_parse_annotations(docBlock, file, line);
    }
}
