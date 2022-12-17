
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
#include "phalcon/annotations/scanner.h"
#include "phalcon/annotations/annot.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Parsers_Annotations)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Parsers, Annotations, phalcon, parsers_annotations, phalcon_parsers_annotations_method_entry, 0);

	return SUCCESS;
}

/**
 * Parse annotations
 */
PHP_METHOD(Phalcon_Parsers_Annotations, parse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long line, ZEPHIR_LAST_CALL_STATUS;
	zval *docBlock_param = NULL, *file_param = NULL, *line_param = NULL, _0;
	zval docBlock, file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&docBlock);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(docBlock)
		Z_PARAM_STR(file)
		Z_PARAM_LONG(line)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &docBlock_param, &file_param, &line_param);
	zephir_get_strval(&docBlock, docBlock_param);
	zephir_get_strval(&file, file_param);
	line = zephir_get_intval(line_param);


	ZVAL_LONG(&_0, line);
	ZEPHIR_LAST_CALL_STATUS = phannot_parse_annotations(return_value, &docBlock, &file, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

