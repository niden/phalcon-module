
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Space
 *
 * @package Phalcon\Encryption\Crypt\Padding
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_Space)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Crypt\\Padding, Space, phalcon, encryption_crypt_padding_space, phalcon_encryption_crypt_padding_space_method_entry, 0);

	zend_class_implements(phalcon_encryption_crypt_padding_space_ce, 1, phalcon_encryption_crypt_padding_padinterface_ce);
	return SUCCESS;
}

/**
 * @param int $paddingSize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Space, pad)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *paddingSize_param = NULL, _0, _1;
	zend_long paddingSize, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paddingSize)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paddingSize_param);
	paddingSize = zephir_get_intval(paddingSize_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, " ");
	ZVAL_LONG(&_1, paddingSize);
	ZEPHIR_RETURN_CALL_FUNCTION("str_repeat", NULL, 1, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Space, unpad)
{
	zend_bool _0, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long blockSize, ZEPHIR_LAST_CALL_STATUS, counter = 0, paddingSize = 0;
	zval *input_param = NULL, *blockSize_param = NULL, length, inputArray, _1, _2, _3;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&inputArray);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(input)
		Z_PARAM_LONG(blockSize)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &input_param, &blockSize_param);
	zephir_get_strval(&input, input_param);
	blockSize = zephir_get_intval(blockSize_param);


	ZEPHIR_CALL_FUNCTION(&length, "mb_strlen", NULL, 230, &input);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&inputArray, "str_split", NULL, 84, &input);
	zephir_check_call_status();
	counter = (zephir_get_numberval(&length) - 1);
	paddingSize = 0;
	while (1) {
		_0 = counter >= 0;
		if (_0) {
			zephir_array_fetch_long(&_1, &inputArray, counter, PH_NOISY | PH_READONLY, "phalcon/Encryption/Crypt/Padding/Space.zep", 48);
			ZVAL_LONG(&_2, 32);
			ZEPHIR_CALL_FUNCTION(&_3, "chr", &_4, 240, &_2);
			zephir_check_call_status();
			_0 = ZEPHIR_IS_EQUAL(&_1, &_3);
		}
		_5 = _0;
		if (_5) {
			_5 = paddingSize <= blockSize;
		}
		if (!(_5)) {
			break;
		}
		paddingSize++;
		counter--;
	}
	RETURN_MM_LONG(paddingSize);
}

