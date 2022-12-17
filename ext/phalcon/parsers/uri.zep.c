
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "phalcon/mvc/url/utils.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Parsers_Uri)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Parsers, Uri, phalcon, parsers_uri, phalcon_parsers_uri_method_entry, 0);

	return SUCCESS;
}

/**
 * Get the URI
 */
PHP_METHOD(Phalcon_Parsers_Uri, getUri)
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
PHP_METHOD(Phalcon_Parsers_Uri, replacePaths)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval paths;
	zval *pattern_param = NULL, *paths_param = NULL, *uri_param = NULL;
	zval pattern, uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pattern);
	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&paths);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(pattern)
		Z_PARAM_ARRAY(paths)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &pattern_param, &paths_param, &uri_param);
	zephir_get_strval(&pattern, pattern_param);
	zephir_get_arrval(&paths, paths_param);
	zephir_get_strval(&uri, uri_param);


	phalcon_replace_paths(return_value, &pattern, &paths, &uri);
	RETURN_MM();
}

