
extern zend_class_entry *phalcon_parsers_annotations_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Annotations);

PHP_METHOD(Phalcon_Parsers_Annotations, parse);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_annotations_parse, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, docBlock, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_annotations_method_entry) {
	PHP_ME(Phalcon_Parsers_Annotations, parse, arginfo_phalcon_parsers_annotations_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
