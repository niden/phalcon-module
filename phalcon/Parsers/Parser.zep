
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
class Parser
{
    /**
     * Parse annotations
     */
    public static function annotationsParse(string docBlock, file, line) -> array
    {
        return phannot_parse_annotations(docBlock, file, line);
    }

    /**
     * Destroy AST Cache
     */
    public static function ormDestroyCache() -> void
    {
        phalcon_orm_destroy_cache();
    }

    /**
     * Parses a PHQL statement returning an intermediate representation (IR)
     */
    public static function ormParse(string phql) -> array
    {
        return phql_parse_phql(phql);
    }

    /**
     * Quote a string
     */
    public static function ormSingleQuotes(string input) -> array
    {
        return phalcon_orm_singlequotes(input);
    }

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

    /**
     * Create the symbol table
     */
    public static function viewCreateSymbolTable() -> void
    {
        create_symbol_table();
    }

    /**
     * Parse the view code
     */
    public static function voltParse(string viewCode, string currentPath) -> string
    {
        return phvolt_parse_view(viewCode, currentPath);
    }
}
