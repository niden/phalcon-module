
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
#include "phalcon/mvc/model/orm.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "phalcon/mvc/model/query/scanner.h"
#include "phalcon/mvc/model/query/phql.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Parsers_Orm)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Parsers, Orm, phalcon, parsers_orm, phalcon_parsers_orm_method_entry, 0);

	return SUCCESS;
}

/**
 * Destroy AST Cache
 */
PHP_METHOD(Phalcon_Parsers_Orm, destroyCache)
{
	zval *this_ptr = getThis();



	phalcon_orm_destroy_cache();
}

/**
 * Parses a PHQL statement returning an intermediate representation (IR)
 */
PHP_METHOD(Phalcon_Parsers_Orm, parse)
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
PHP_METHOD(Phalcon_Parsers_Orm, singleQuotes)
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

