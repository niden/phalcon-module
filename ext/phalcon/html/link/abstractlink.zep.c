
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * @property array  $attributes
 * @property string $href
 * @property array  $rels
 * @property bool   $templated
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Link_AbstractLink)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Html\\Link, AbstractLink, phalcon, html_link_abstractlink, phalcon_html_link_abstractlink_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Collection
	 */
	zend_declare_property_null(phalcon_html_link_abstractlink_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_link_abstractlink_ce, SL("href"), "", ZEND_ACC_PROTECTED);
	/**
	 * @var Collection
	 */
	zend_declare_property_null(phalcon_html_link_abstractlink_ce, SL("rels"), ZEND_ACC_PROTECTED);
	/**
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_html_link_abstractlink_ce, SL("templated"), 0, ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Link constructor.
 *
 * @param string $rel
 * @param string $href
 * @param array  $attributes
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes;
	zval *rel_param = NULL, *href_param = NULL, *attributes_param = NULL, _0, _1, _2, _3$$3, _4$$3;
	zval rel, href;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rel);
	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&attributes);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(rel)
		Z_PARAM_STR(href)
		Z_PARAM_ARRAY(attributes)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &rel_param, &href_param, &attributes_param);
	if (!rel_param) {
		ZEPHIR_INIT_VAR(&rel);
		ZVAL_STRING(&rel, "");
	} else {
		zephir_get_strval(&rel, rel_param);
	}
	if (!href_param) {
		ZEPHIR_INIT_VAR(&href);
		ZVAL_STRING(&href, "");
	} else {
		zephir_get_strval(&href, href_param);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 22, &attributes);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_support_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 22);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("rels"), &_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("href"), &href);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "hrefistemplated", NULL, 0, &href);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("templated"), &_2);
	if (1 != ZEPHIR_IS_EMPTY(&rel)) {
		zephir_read_property(&_3$$3, this_ptr, ZEND_STRL("rels"), PH_NOISY_CC | PH_READONLY);
		ZVAL_BOOL(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "set", NULL, 0, &rel, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns a list of attributes that describe the target URI.
 *
 * @return array
 *   A key-value list of attributes, where the key is a string and the value
 *  is either a PHP primitive or an array of PHP strings. If no values are
 *  found an empty array MUST be returned.
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetAttributes)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the target of the link.
 *
 * The target link must be one of:
 * - An absolute URI, as defined by RFC 5988.
 * - A relative URI, as defined by RFC 5988. The base of the relative link
 *     is assumed to be known based on context by the client.
 * - A URI template as defined by RFC 6570.
 *
 * If a URI template is returned, isTemplated() MUST return True.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetHref)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "href");
}

/**
 * Returns the relationship type(s) of the link.
 *
 * This method returns 0 or more relationship types for a link, expressed
 * as an array of strings.
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doGetRels)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("rels"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getkeys", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns whether this is a templated link.
 *
 * @return bool
 *   True if this link object is templated, False otherwise.
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doIsTemplated)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "templated");
}

/**
 * Determines if a href is a templated link or not.
 *
 * @see https://tools.ietf.org/html/rfc6570
 *
 * @param string $href
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, hrefIsTemplated)
{
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *href_param = NULL, _0, _1, _3;
	zval href;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(href)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &href_param);
	zephir_get_strval(&href, href_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "{");
	ZEPHIR_CALL_FUNCTION(&_1, "mb_strpos", NULL, 82, &href, &_0);
	zephir_check_call_status();
	_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	if (_2) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "}");
		ZEPHIR_CALL_FUNCTION(&_3, "mb_strpos", NULL, 82, &href, &_0);
		zephir_check_call_status();
		_2 = !ZEPHIR_IS_FALSE_IDENTICAL(&_3);
	}
	RETURN_MM_BOOL(_2);
}

/**
 * @param string       $key
 * @param string|array $value
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, newInstance, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &key, value);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

/**
 * @param string $href
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithHref)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *href_param = NULL, newInstance, _0;
	zval href;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(href)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &href_param);
	zephir_get_strval(&href, href_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval(&newInstance, ZEND_STRL("href"), &href);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hrefistemplated", NULL, 0, &href);
	zephir_check_call_status();
	zephir_update_property_zval(&newInstance, ZEND_STRL("templated"), &_0);
	RETURN_CCTOR(&newInstance);
}

/**
 * @param string $key
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithRel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, newInstance, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("rels"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &key, &_1);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

/**
 * @param string $key
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithoutAttribute)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, newInstance, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

/**
 * @param string $key
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Html_Link_AbstractLink, doWithoutRel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, newInstance, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&newInstance);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&newInstance);
	if (zephir_clone(&newInstance, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_read_property(&_0, &newInstance, ZEND_STRL("rels"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "remove", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_CCTOR(&newInstance);
}

