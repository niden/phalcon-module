
extern zend_class_entry *phalcon_parsers_orm_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Orm);

PHP_METHOD(Phalcon_Parsers_Orm, destroyCache);
PHP_METHOD(Phalcon_Parsers_Orm, parse);
PHP_METHOD(Phalcon_Parsers_Orm, singleQuotes);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_orm_destroycache, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_orm_parse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_orm_singlequotes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_orm_method_entry) {
	PHP_ME(Phalcon_Parsers_Orm, destroyCache, arginfo_phalcon_parsers_orm_destroycache, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Orm, parse, arginfo_phalcon_parsers_orm_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Orm, singleQuotes, arginfo_phalcon_parsers_orm_singlequotes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
