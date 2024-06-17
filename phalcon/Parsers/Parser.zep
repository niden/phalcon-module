
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
     * Get the URI
     */
    public static function getUri(string path) -> string
    {
        return phalcon_get_uri(path);
    }

    /**
     * Get the Version for the parser module
     */
    public static function getVersion() -> string
    {
        return "1.0.0";
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
    public static function replacePaths(
        string pattern,
        array paths,
        array uri
    ) -> array {
        return phalcon_replace_paths(pattern, paths, uri);
    }

    public static function settingGet(string input)
    {
        switch input {
            case "orm.events":
                return globals_get("orm.events");
            case "orm.case_insensitive_column_map":
                return globals_get("orm.case_insensitive_column_map");
            case "orm.cast_last_insert_id_to_int":
                return globals_get("orm.cast_last_insert_id_to_int");
            case "orm.cast_on_hydrate":
                return globals_get("orm.cast_on_hydrate");
            case "orm.column_renaming":
                return globals_get("orm.column_renaming");
            case "orm.disable_assign_setters":
                return globals_get("orm.disable_assign_setters");
            case "orm.enable_literals":
                return globals_get("orm.enable_literals");
            case "orm.exception_on_failed_save":
                return globals_get("orm.exception_on_failed_save");
            case "orm.exception_on_failed_metadata_save":
                return globals_get("orm.exception_on_failed_metadata_save");
            case "orm.not_null_validations":
                return globals_get("orm.not_null_validations");
            case "orm.ignore_unknown_columns":
                return globals_get("orm.ignore_unknown_columns");
            case "orm.late_state_binding":
                return globals_get("orm.late_state_binding");
            case "orm.resultset_prefetch_records": //-
                return globals_get("orm.resultset_prefetch_records"); //-
            case "orm.update_snapshot_on_save":
                return globals_get("orm.update_snapshot_on_save");
            case "orm.virtual_foreign_keys":
                return globals_get("orm.virtual_foreign_keys");
            default:
                return false;
        }
    }

    public static function settingSet(string input, mixed value) -> void
    {
        switch input {
            case "orm.events":
                globals_set("orm.events", value);
            case "orm.case_insensitive_column_map":
                globals_set("orm.case_insensitive_column_map", value);
            case "orm.cast_last_insert_id_to_int":
                globals_set("orm.cast_last_insert_id_to_int", value);
            case "orm.cast_on_hydrate":
                globals_set("orm.cast_on_hydrate", value);
            case "orm.column_renaming":
                globals_set("orm.column_renaming", value);
            case "orm.disable_assign_setters":
                globals_set("orm.disable_assign_setters", value);
            case "orm.enable_literals":
                globals_set("orm.enable_literals", value);
            case "orm.exception_on_failed_save":
                globals_set("orm.exception_on_failed_save", value);
            case "orm.exception_on_failed_metadata_save":
                globals_set("orm.exception_on_failed_metadata_save", value);
            case "orm.not_null_validations":
                globals_set("orm.not_null_validations", value);
            case "orm.ignore_unknown_columns":
                globals_set("orm.ignore_unknown_columns", value);
            case "orm.late_state_binding":
                globals_set("orm.late_state_binding", value);
            case "orm.resultset_prefetch_records": //-
                globals_set("orm.resultset_prefetch_records", value); //-
            case "orm.update_snapshot_on_save":
                globals_set("orm.update_snapshot_on_save", value);
            case "orm.virtual_foreign_keys":
                globals_set("orm.virtual_foreign_keys", value);
        }
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
