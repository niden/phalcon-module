
extern zend_class_entry *phalcon_parsers_uri_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Uri);

PHP_METHOD(Phalcon_Parsers_Uri, getUri);
PHP_METHOD(Phalcon_Parsers_Uri, replacePaths);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_uri_geturi, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_uri_replacepaths, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, paths, 0)
	ZEND_ARG_ARRAY_INFO(0, uri, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_uri_method_entry) {
	PHP_ME(Phalcon_Parsers_Uri, getUri, arginfo_phalcon_parsers_uri_geturi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Uri, replacePaths, arginfo_phalcon_parsers_uri_replacepaths, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
