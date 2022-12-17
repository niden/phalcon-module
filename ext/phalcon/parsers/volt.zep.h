
extern zend_class_entry *phalcon_parsers_volt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Volt);

PHP_METHOD(Phalcon_Parsers_Volt, parse);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_volt_parse, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewCode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, currentPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_volt_method_entry) {
	PHP_ME(Phalcon_Parsers_Volt, parse, arginfo_phalcon_parsers_volt_parse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
