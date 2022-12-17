
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
class Uri
{
    /**
     * Get the URI
     */
    public static function getUri(string path) -> string
    {
        return phalcon_get_uri(path);
    }

    /**
     * Get the URI
     */
    public static function replacePaths(
        string pattern,
        array paths,
        array uri
    ) -> array {
        return phalcon_replace_paths(pattern, paths, uri);
    }
}
