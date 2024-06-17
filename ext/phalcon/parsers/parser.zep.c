
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "phalcon/mvc/model/orm.h"
#include "phalcon/annotations/scanner.h"
#include "phalcon/annotations/annot.h"
#include "phalcon/mvc/url/utils.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"
#include "phalcon/mvc/view/engine/volt/scanner.h"
#include "phalcon/mvc/view/engine/volt/volt.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Proxy class for accessing C parser
 */
ZEPHIR_INIT_CLASS(Phalcon_Parsers_Parser)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Parsers, Parser, phalcon, parsers_parser, phalcon_parsers_parser_method_entry, 0);

	return SUCCESS;
}

/**
 * Parse annotations
 */
PHP_METHOD(Phalcon_Parsers_Parser, annotationsParse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *docBlock_param = NULL, *file, file_sub, *line, line_sub;
	zval docBlock;

	ZVAL_UNDEF(&docBlock);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(docBlock)
		Z_PARAM_ZVAL(file)
		Z_PARAM_ZVAL(line)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &docBlock_param, &file, &line);
	zephir_get_strval(&docBlock, docBlock_param);
	ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(return_value, &docBlock, file, line);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get the URI
 */
PHP_METHOD(Phalcon_Parsers_Parser, getUri)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *path_param = NULL;
	zval path;

	ZVAL_UNDEF(&path);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &path_param);
	zephir_get_strval(&path, path_param);
	phalcon_get_uri(return_value, &path);
	RETURN_MM();
}

/**
 * Get the Version for the parser module
 */
PHP_METHOD(Phalcon_Parsers_Parser, getVersion)
{

	RETURN_STRING("1.0.0");
}

/**
 * Destroy AST Cache
 */
PHP_METHOD(Phalcon_Parsers_Parser, ormDestroyCache)
{

	phalcon_orm_destroy_cache();
}

/**
 * Parses a PHQL statement returning an intermediate representation (IR)
 */
PHP_METHOD(Phalcon_Parsers_Parser, ormParse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *phql_param = NULL;
	zval phql;

	ZVAL_UNDEF(&phql);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(phql)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &phql_param);
	zephir_get_strval(&phql, phql_param);
	ZEPHIR_LAST_CALL_STATUS = phql_parse_phql(return_value, &phql);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Quote a string
 */
PHP_METHOD(Phalcon_Parsers_Parser, ormSingleQuotes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input_param = NULL;
	zval input;

	ZVAL_UNDEF(&input);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);
	phalcon_orm_singlequotes(return_value, &input);
	RETURN_MM();
}

/**
 * Get the URI
 */
PHP_METHOD(Phalcon_Parsers_Parser, replacePaths)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval paths, uri;
	zval *pattern_param = NULL, *paths_param = NULL, *uri_param = NULL;
	zval pattern;

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&uri);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_ARRAY(paths)
		Z_PARAM_ARRAY(uri)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &pattern_param, &paths_param, &uri_param);
	zephir_get_strval(&pattern, pattern_param);
	zephir_get_arrval(&paths, paths_param);
	zephir_get_arrval(&uri, uri_param);
	phalcon_replace_paths(return_value, &pattern, &paths, &uri);
	RETURN_MM();
}

PHP_METHOD(Phalcon_Parsers_Parser, settingGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *input_param = NULL;
	zval input;

	ZVAL_UNDEF(&input);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);
	do {
		if (ZEPHIR_IS_STRING(&input, "orm.events")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).events);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.case_insensitive_column_map")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).case_insensitive_column_map);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.cast_last_insert_id_to_int")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).cast_last_insert_id_to_int);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.cast_on_hydrate")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).cast_on_hydrate);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.column_renaming")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).column_renaming);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.disable_assign_setters")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).disable_assign_setters);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.enable_literals")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).enable_literals);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.exception_on_failed_save")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).exception_on_failed_save);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.exception_on_failed_metadata_save")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).exception_on_failed_metadata_save);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.not_null_validations")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).not_null_validations);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.ignore_unknown_columns")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).ignore_unknown_columns);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.late_state_binding")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).late_state_binding);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.resultset_prefetch_records")) {
			RETURN_MM_STRING(ZEPHIR_GLOBAL(orm).resultset_prefetch_records);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.update_snapshot_on_save")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).update_snapshot_on_save);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.virtual_foreign_keys")) {
			RETURN_MM_BOOL(ZEPHIR_GLOBAL(orm).virtual_foreign_keys);
		}
		RETURN_MM_BOOL(0);
	} while(0);

	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Parsers_Parser, settingSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value;
	zval *input_param = NULL, value_sub;
	zval input;

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&value_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(input)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &input_param, &value);
	zephir_get_strval(&input, input_param);
	do {
		if (ZEPHIR_IS_STRING(&input, "orm.events")) {
			ZEPHIR_GLOBAL(orm).events = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.case_insensitive_column_map")) {
			ZEPHIR_GLOBAL(orm).case_insensitive_column_map = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.cast_last_insert_id_to_int")) {
			ZEPHIR_GLOBAL(orm).cast_last_insert_id_to_int = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.cast_on_hydrate")) {
			ZEPHIR_GLOBAL(orm).cast_on_hydrate = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.column_renaming")) {
			ZEPHIR_GLOBAL(orm).column_renaming = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.disable_assign_setters")) {
			ZEPHIR_GLOBAL(orm).disable_assign_setters = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.enable_literals")) {
			ZEPHIR_GLOBAL(orm).enable_literals = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.exception_on_failed_save")) {
			ZEPHIR_GLOBAL(orm).exception_on_failed_save = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.exception_on_failed_metadata_save")) {
			ZEPHIR_GLOBAL(orm).exception_on_failed_metadata_save = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.not_null_validations")) {
			ZEPHIR_GLOBAL(orm).not_null_validations = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.ignore_unknown_columns")) {
			ZEPHIR_GLOBAL(orm).ignore_unknown_columns = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.late_state_binding")) {
			ZEPHIR_GLOBAL(orm).late_state_binding = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.resultset_prefetch_records")) {
			ZEPHIR_GLOBAL(orm).resultset_prefetch_records = ZSTR_VAL(zval_get_string(value));
		}
		if (ZEPHIR_IS_STRING(&input, "orm.update_snapshot_on_save")) {
			ZEPHIR_GLOBAL(orm).update_snapshot_on_save = zend_is_true(value);
		}
		if (ZEPHIR_IS_STRING(&input, "orm.virtual_foreign_keys")) {
			ZEPHIR_GLOBAL(orm).virtual_foreign_keys = zend_is_true(value);
		}
	} while(0);

	ZEPHIR_MM_RESTORE();
}

/**
 * Create the symbol table
 */
PHP_METHOD(Phalcon_Parsers_Parser, viewCreateSymbolTable)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CREATE_SYMBOL_TABLE();
	
	ZEPHIR_MM_RESTORE();
}

/**
 * Parse the view code
 */
PHP_METHOD(Phalcon_Parsers_Parser, voltParse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL, *currentPath_param = NULL;
	zval viewCode, currentPath;

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&currentPath);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(viewCode)
		Z_PARAM_STR(currentPath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &viewCode_param, &currentPath_param);
	zephir_get_strval(&viewCode, viewCode_param);
	zephir_get_strval(&currentPath, currentPath_param);
	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(return_value, &viewCode, &currentPath);
	zephir_check_call_status();
	RETURN_MM();
}

