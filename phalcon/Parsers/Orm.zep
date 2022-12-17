
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
class Orm
{
    /**
     * Destroy AST Cache
     */
    public static function destroyCache() -> void
    {
        phalcon_orm_destroy_cache();
    }

    /**
     * Parses a PHQL statement returning an intermediate representation (IR)
     */
    public static function parse(string phql) -> array
    {
        return phql_parse_phql(phql);
    }

    /**
     * Quote a string
     */
    public static function singleQuotes(string input) -> array
    {
        return phalcon_orm_singlequotes(input);
    }

}
