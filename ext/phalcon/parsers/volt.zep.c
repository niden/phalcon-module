
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
ZEPHIR_INIT_CLASS(Phalcon_Parsers_Volt)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Parsers, Volt, phalcon, parsers_volt, phalcon_parsers_volt_method_entry, 0);

	return SUCCESS;
}

/**
 * Parse the view code
 */
PHP_METHOD(Phalcon_Parsers_Volt, parse)
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

