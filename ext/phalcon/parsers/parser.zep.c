
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
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"
#include "phalcon/mvc/url/utils.h"
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&docBlock);
	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(docBlock)
		Z_PARAM_ZVAL(file)
		Z_PARAM_ZVAL(line)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &docBlock_param, &file, &line);
	zephir_get_strval(&docBlock, docBlock_param);


	ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(return_value, &docBlock, file, line);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Destroy AST Cache
 */
PHP_METHOD(Phalcon_Parsers_Parser, ormDestroyCache)
{
	zval *this_ptr = getThis();



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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&phql);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(phql)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(input)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &input_param);
	zephir_get_strval(&input, input_param);


	phalcon_orm_singlequotes(return_value, &input);
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(path)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);
	zephir_get_strval(&path, path_param);


	phalcon_get_uri(return_value, &path);
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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&uri);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_ARRAY(paths)
		Z_PARAM_ARRAY(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &pattern_param, &paths_param, &uri_param);
	zephir_get_strval(&pattern, pattern_param);
	zephir_get_arrval(&paths, paths_param);
	zephir_get_arrval(&uri, uri_param);


	phalcon_replace_paths(return_value, &pattern, &paths, &uri);
	RETURN_MM();
}

/**
 * Create the symbol table
 */
PHP_METHOD(Phalcon_Parsers_Parser, viewCreateSymbolTable)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

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
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&currentPath);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(viewCode)
		Z_PARAM_STR(currentPath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &viewCode_param, &currentPath_param);
	zephir_get_strval(&viewCode, viewCode_param);
	zephir_get_strval(&currentPath, currentPath_param);


	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(return_value, &viewCode, &currentPath);
	zephir_check_call_status();
	RETURN_MM();
}

