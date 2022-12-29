
/* This file was generated automatically by Zephir do not modify it! */

#ifndef ZEPHIR_CLASS_ENTRIES_H
#define ZEPHIR_CLASS_ENTRIES_H


zend_class_entry *phalcon_mvc_view_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Exception);


zend_class_entry *phalcon_annotations_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Annotations_Exception);


zend_class_entry *phalcon_mvc_model_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Exception);


zend_class_entry *phalcon_mvc_view_engine_volt_exception_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_View_Engine_Volt_Exception);

static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, __construct);
static PHP_METHOD(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement);
zend_object *zephir_init_properties_Phalcon_Mvc_View_Engine_Volt_Exception(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, statement, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, statement, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, previous, Exception, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception_getstatement, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_engine_volt_exception_zephir_init_properties_phalcon_mvc_view_engine_volt_exception, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_view_engine_volt_exception_method_entry) {
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Exception, __construct, arginfo_phalcon_mvc_view_engine_volt_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Engine_Volt_Exception, getStatement, arginfo_phalcon_mvc_view_engine_volt_exception_getstatement, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

zend_class_entry *phalcon_parsers_annotations_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Annotations);

static PHP_METHOD(Phalcon_Parsers_Annotations, parse);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_annotations_parse, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, docBlock, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, line, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_annotations_method_entry) {
	PHP_ME(Phalcon_Parsers_Annotations, parse, arginfo_phalcon_parsers_annotations_parse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

zend_class_entry *phalcon_parsers_enum_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Enum);


zend_class_entry *phalcon_parsers_orm_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Orm);

static PHP_METHOD(Phalcon_Parsers_Orm, destroyCache);
static PHP_METHOD(Phalcon_Parsers_Orm, parse);
static PHP_METHOD(Phalcon_Parsers_Orm, singleQuotes);

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

zend_class_entry *phalcon_parsers_uri_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Uri);

static PHP_METHOD(Phalcon_Parsers_Uri, getUri);
static PHP_METHOD(Phalcon_Parsers_Uri, replacePaths);

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

zend_class_entry *phalcon_parsers_volt_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Volt);

static PHP_METHOD(Phalcon_Parsers_Volt, parse);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_volt_parse, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewCode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, currentPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_volt_method_entry) {
	PHP_ME(Phalcon_Parsers_Volt, parse, arginfo_phalcon_parsers_volt_parse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif