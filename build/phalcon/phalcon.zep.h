
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

zend_class_entry *phalcon_parsers_parser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Parser);

static PHP_METHOD(Phalcon_Parsers_Parser, annotationsParse);
static PHP_METHOD(Phalcon_Parsers_Parser, ormDestroyCache);
static PHP_METHOD(Phalcon_Parsers_Parser, ormParse);
static PHP_METHOD(Phalcon_Parsers_Parser, ormSingleQuotes);
static PHP_METHOD(Phalcon_Parsers_Parser, getUri);
static PHP_METHOD(Phalcon_Parsers_Parser, replacePaths);
static PHP_METHOD(Phalcon_Parsers_Parser, voltParse);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_annotationsparse, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, docBlock, IS_STRING, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_ormdestroycache, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_ormparse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_ormsinglequotes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_geturi, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_replacepaths, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, paths, 0)
	ZEND_ARG_ARRAY_INFO(0, uri, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_voltparse, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewCode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, currentPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_parser_method_entry) {
	PHP_ME(Phalcon_Parsers_Parser, annotationsParse, arginfo_phalcon_parsers_parser_annotationsparse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, ormDestroyCache, arginfo_phalcon_parsers_parser_ormdestroycache, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, ormParse, arginfo_phalcon_parsers_parser_ormparse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, ormSingleQuotes, arginfo_phalcon_parsers_parser_ormsinglequotes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, getUri, arginfo_phalcon_parsers_parser_geturi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, replacePaths, arginfo_phalcon_parsers_parser_replacepaths, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, voltParse, arginfo_phalcon_parsers_parser_voltparse, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

#endif