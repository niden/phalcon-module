
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Capitalizes the first letter of each word
 */
class Ucwords
{
    /**
     * @param string $text
     * @param string $encoding
     *
     * @return string
     */
    public function __invoke(
        string text,
        string encoding = "UTF-8"
    ) -> string {
        return mb_convert_case(text, MB_CASE_TITLE, encoding);
    }
}
