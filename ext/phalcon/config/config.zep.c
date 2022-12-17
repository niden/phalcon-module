
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
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
 * `Phalcon\Config` is designed to simplify the access to, and the use of,
 * configuration data within applications. It provides a nested object property
 * based user interface for accessing this configuration data within application
 * code.
 *
 *```php
 * $config = new \Phalcon\Config\Config(
 *     [
 *         "database" => [
 *             "adapter"  => "Mysql",
 *             "host"     => "localhost",
 *             "username" => "scott",
 *             "password" => "cheetah",
 *             "dbname"   => "test_db",
 *         ],
 *         "phalcon" => [
 *             "controllersDir" => "../app/controllers/",
 *             "modelsDir"      => "../app/models/",
 *             "viewsDir"       => "../app/views/",
 *         ],
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Config_Config)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Config, Config, phalcon, config_config, phalcon_support_collection_ce, phalcon_config_config_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_config_config_ce, SL("pathDelimiter"), ".", ZEND_ACC_PROTECTED);
	zephir_declare_class_constant_string(phalcon_config_config_ce, SL("DEFAULT_PATH_DELIMITER"), ".");

	zend_class_implements(phalcon_config_config_ce, 1, phalcon_config_configinterface_ce);
	return SUCCESS;
}

/**
 * Gets the default path delimiter
 *
 * @return string
 */
PHP_METHOD(Phalcon_Config_Config, getPathDelimiter)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "pathDelimiter");
}

/**
 * Merges a configuration into the current one
 *
 *```php
 * $appConfig = new \Phalcon\Config\Config(
 *     [
 *         "database" => [
 *             "host" => "localhost",
 *         ],
 *     ]
 * );
 *
 * $globalConfig->merge($appConfig);
 *```
 *
 * @param array|ConfigInterface $toMerge
 *
 * @return ConfigInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Config_Config, merge)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *toMerge, toMerge_sub, result, source, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&toMerge_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(toMerge)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &toMerge);


	ZEPHIR_CALL_METHOD(&source, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(toMerge) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&result, this_ptr, "internalmerge", NULL, 20, &source, toMerge);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &result);
		zephir_check_call_status();
		RETURN_THIS();
	}
	_0 = Z_TYPE_P(toMerge) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(toMerge, phalcon_config_configinterface_ce);
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_1$$4, toMerge, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&result, this_ptr, "internalmerge", NULL, 20, &source, &_1$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &result);
		zephir_check_call_status();
		RETURN_THIS();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_config_exception_ce, "Invalid data type for merge.", "phalcon/Config/Config.zep", 103);
	return;
}

/**
 * Returns a value from current config using a dot separated path.
 *
 *```php
 * echo $config->path("unknown.path", "default", ".");
 *```
 *
 * @param string      $path
 * @param mixed|null  $defaultValue
 * @param string|null $delimiter
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Config_Config, path)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *defaultValue = NULL, defaultValue_sub, *delimiter_param = NULL, __$null, config, key, keys, pathDelimiter, _0, _1$$4, _3$$5, _4$$5;
	zval path, delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&delimiter);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&pathDelimiter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(path)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &path_param, &defaultValue, &delimiter_param);
	zephir_get_strval(&path, path_param);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &path);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &path);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(&pathDelimiter, &delimiter);
	if (1 == ZEPHIR_IS_EMPTY(&pathDelimiter)) {
		zephir_read_property(&_1$$4, this_ptr, ZEND_STRL("pathDelimiter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&pathDelimiter, &_1$$4);
	}
	ZEPHIR_INIT_VAR(&config);
	if (zephir_clone(&config, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&keys);
	zephir_fast_explode(&keys, &pathDelimiter, &path, LONG_MAX);
	while (1) {
		if (!(1 != ZEPHIR_IS_EMPTY(&keys))) {
			break;
		}
		ZEPHIR_MAKE_REF(&keys);
		ZEPHIR_CALL_FUNCTION(&key, "array_shift", &_2, 21, &keys);
		ZEPHIR_UNREF(&keys);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$5, &config, "has", NULL, 0, &key);
		zephir_check_call_status();
		if (!ZEPHIR_IS_TRUE_IDENTICAL(&_3$$5)) {
			break;
		}
		if (1 == ZEPHIR_IS_EMPTY(&keys)) {
			ZEPHIR_RETURN_CALL_METHOD(&config, "get", NULL, 0, &key);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(&_4$$5, &config, "get", NULL, 0, &key);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&config, &_4$$5);
		if (1 == ZEPHIR_IS_EMPTY(&config)) {
			break;
		}
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();
}

/**
 * Sets the default path delimiter
 *
 * @param string|null $delimiter
 *
 * @return ConfigInterface
 */
PHP_METHOD(Phalcon_Config_Config, setPathDelimiter)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *delimiter_param = NULL;
	zval delimiter;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&delimiter);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &delimiter_param);
	if (!delimiter_param) {
		ZEPHIR_INIT_VAR(&delimiter);
	} else {
		zephir_get_strval(&delimiter, delimiter_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("pathDelimiter"), &delimiter);
	RETURN_THIS();
}

/**
 * Converts recursively the object to an array
 *
 *```php
 * print_r(
 *     $config->toArray()
 * );
 *```
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config_Config, toArray)
{
	zend_bool _5$$3, _7$$5;
	zend_string *_4;
	zend_ulong _3;
	zval results;
	zval data, key, value, *_1, _2, _6$$4, _8$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&results);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&results);
	array_init(&results);
	ZEPHIR_CALL_PARENT(&data, phalcon_config_config_ce, getThis(), "toarray", &_0, 0);
	zephir_check_call_status();
	zephir_is_iterable(&data, 0, "phalcon/Config/Config.zep", 203);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1);
			_5$$3 = Z_TYPE_P(&value) == IS_OBJECT;
			if (_5$$3) {
				_5$$3 = 1 == (zephir_method_exists_ex(&value, ZEND_STRL("toarray")) == SUCCESS);
			}
			if (_5$$3) {
				ZEPHIR_CALL_METHOD(&_6$$4, &value, "toarray", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(&value, &_6$$4);
			}
			zephir_array_update_zval(&results, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &data, "current", NULL, 0);
			zephir_check_call_status();
				_7$$5 = Z_TYPE_P(&value) == IS_OBJECT;
				if (_7$$5) {
					_7$$5 = 1 == (zephir_method_exists_ex(&value, ZEND_STRL("toarray")) == SUCCESS);
				}
				if (_7$$5) {
					ZEPHIR_CALL_METHOD(&_8$$6, &value, "toarray", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(&value, &_8$$6);
				}
				zephir_array_update_zval(&results, &key, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&results);
}

/**
 * Performs a merge recursively
 *
 * @param array $source
 * @param array $target
 *
 * @return array
 */
PHP_METHOD(Phalcon_Config_Config, internalMerge)
{
	zend_bool _4$$3, _5$$3, _10$$5, _11$$5;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *source_param = NULL, *target_param = NULL, key, value, *_0, _1, _6$$3, _7$$4, _8$$4, _12$$5, _13$$6, _14$$6;
	zval source, target;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(source)
		Z_PARAM_ARRAY(target)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &source_param, &target_param);
	zephir_get_arrval(&source, source_param);
	zephir_get_arrval(&target, target_param);


	zephir_is_iterable(&target, 0, "phalcon/Config/Config.zep", 232);
	if (Z_TYPE_P(&target) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&target), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			_4$$3 = Z_TYPE_P(&value) == IS_ARRAY;
			if (_4$$3) {
				_4$$3 = 1 == zephir_array_isset(&source, &key);
			}
			_5$$3 = _4$$3;
			if (_5$$3) {
				ZEPHIR_OBS_NVAR(&_6$$3);
				zephir_array_fetch(&_6$$3, &source, &key, PH_NOISY, "phalcon/Config/Config.zep", 222);
				_5$$3 = Z_TYPE_P(&_6$$3) == IS_ARRAY;
			}
			if (_5$$3) {
				zephir_array_fetch(&_8$$4, &source, &key, PH_NOISY | PH_READONLY, "phalcon/Config/Config.zep", 224);
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "internalmerge", &_9, 20, &_8$$4, &value);
				zephir_check_call_status();
				zephir_array_update_zval(&source, &key, &_7$$4, PH_COPY | PH_SEPARATE);
				continue;
			}
			zephir_array_update_zval(&source, &key, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &target, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &target, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &target, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &target, "current", NULL, 0);
			zephir_check_call_status();
				_10$$5 = Z_TYPE_P(&value) == IS_ARRAY;
				if (_10$$5) {
					_10$$5 = 1 == zephir_array_isset(&source, &key);
				}
				_11$$5 = _10$$5;
				if (_11$$5) {
					ZEPHIR_OBS_NVAR(&_12$$5);
					zephir_array_fetch(&_12$$5, &source, &key, PH_NOISY, "phalcon/Config/Config.zep", 222);
					_11$$5 = Z_TYPE_P(&_12$$5) == IS_ARRAY;
				}
				if (_11$$5) {
					zephir_array_fetch(&_14$$6, &source, &key, PH_NOISY | PH_READONLY, "phalcon/Config/Config.zep", 224);
					ZEPHIR_CALL_METHOD(&_13$$6, this_ptr, "internalmerge", &_9, 20, &_14$$6, &value);
					zephir_check_call_status();
					zephir_array_update_zval(&source, &key, &_13$$6, PH_COPY | PH_SEPARATE);
					continue;
				}
				zephir_array_update_zval(&source, &key, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &target, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&source);
}

/**
 * Sets the collection data
 *
 * @param mixed $element
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Config_Config, setData)
{
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *element = NULL, element_sub, *value, value_sub, data, key, _0, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&element_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(element)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &element, &value);
	ZEPHIR_SEPARATE_PARAM(element);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&data, &_0);
	zephir_cast_to_string(&_1, element);
	ZEPHIR_CPY_WRT(element, &_1);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(&key, "mb_strtolower", NULL, 10, element);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&key, element);
	}
	zephir_update_property_array(this_ptr, SL("lowerKeys"), &key, element);
	if (Z_TYPE_P(value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_config_config_ce);
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("insensitive"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 22, value, &_3$$3);
		zephir_check_call_status();
		zephir_array_update_zval(&data, element, &_2$$3, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_zval(&data, element, value, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("data"), &data);
	ZEPHIR_MM_RESTORE();
}

