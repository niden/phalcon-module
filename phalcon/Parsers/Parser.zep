
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

    public static function settingGetEvents() -> bool
    {
        return globals_get("orm.events");
    }

    public static function settingGetCaseInsensitiveColumnMap() -> bool
    {
        return globals_get("orm.case_insensitive_column_map");
    }

    public static function settingGetCastLastInsertIdToInt() -> bool
    {
        return globals_get("orm.cast_last_insert_id_to_int");
    }

    public static function settingGetCastOnHydrate() -> bool
    {
        return globals_get("orm.cast_on_hydrate");
    }

    public static function settingGetColumnRenaming() -> bool
    {
        return globals_get("orm.column_renaming");
    }

    public static function settingGetDisableAssignSetters() -> bool
    {
        return globals_get("orm.disable_assign_setters");
    }

    public static function settingGetEnableLiterals() -> bool
    {
        return globals_get("orm.enable_literals");
    }

    public static function settingGetExceptionOnFailedSave() -> bool
    {
        return globals_get("orm.exception_on_failed_save");
    }

    public static function settingGetExceptionOnFailedMetadataSave() -> bool
    {
        return globals_get("orm.exception_on_failed_metadata_save");
    }

    public static function settingGetNotNullValidations() -> bool
    {
        return globals_get("orm.not_null_validations");
    }

    public static function settingGetIgnoreUnknownColumns() -> bool
    {
        return globals_get("orm.ignore_unknown_columns");
    }

    public static function settingGetLateStateBinding() -> bool
    {
        return globals_get("orm.late_state_binding");
    }

    public static function settingGetResultsetPrefetchRecords()
    {
        return globals_get("orm.resultset_prefetch_records");
    }

    public static function settingGetUpdateSnapshotOnSave() -> bool
    {
        return globals_get("orm.update_snapshot_on_save");
    }

    public static function settingGetVirtualForeignKeys() -> bool
    {
        return globals_get("orm.virtual_foreign_keys");
    }

    public static function settingSetEvents(string value) -> void
    {
        globals_set("orm.events", value);
    }

    public static function settingSetCaseInsensitiveColumnMap(string value) -> void
    {
        globals_set("orm.case_insensitive_column_map", value);
    }

    public static function settingSetCastLastInsertIdToInt(string value) -> void
    {
        globals_set("orm.cast_last_insert_id_to_int", value);
    }

    public static function settingSetCastOnHydrate(string value) -> void
    {
        globals_set("orm.cast_on_hydrate", value);
    }

    public static function settingSetColumnRenaming(string value) -> void
    {
        globals_set("orm.column_renaming", value);
    }

    public static function settingSetDisableAssignSetters(string value) -> void
    {
        globals_set("orm.disable_assign_setters", value);
    }

    public static function settingSetEnableLiterals(string value) -> void
    {
        globals_set("orm.enable_literals", value);
    }

    public static function settingSetExceptionOnFailedSave(string value) -> void
    {
        globals_set("orm.exception_on_failed_save", value);
    }

    public static function settingSetExceptionOnFailedMetadataSave(string value) -> void
    {
        globals_set("orm.exception_on_failed_metadata_save", value);
    }

    public static function settingSetNotNullValidations(string value) -> void
    {
        globals_set("orm.not_null_validations", value);
    }

    public static function settingSetIgnoreUnknownColumns(string value) -> void
    {
        globals_set("orm.ignore_unknown_columns", value);
    }

    public static function settingSetLateStateBinding(string value) -> void
    {
        globals_set("orm.late_state_binding", value);
    }

    public static function settingSetResultsetPrefetchRecords(int value) -> void
    {
        globals_set("orm.resultset_prefetch_records", value);
    }

    public static function settingSetUpdateSnapshotOnSave(string value) -> void
    {
        globals_set("orm.update_snapshot_on_save", value);
    }

    public static function settingSetVirtualForeignKeys(string value) -> void
    {
        globals_set("orm.virtual_foreign_keys", value);
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
