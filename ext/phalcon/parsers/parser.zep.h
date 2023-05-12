
extern zend_class_entry *phalcon_parsers_parser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Parser);

PHP_METHOD(Phalcon_Parsers_Parser, annotationsParse);
PHP_METHOD(Phalcon_Parsers_Parser, getUri);
PHP_METHOD(Phalcon_Parsers_Parser, getVersion);
PHP_METHOD(Phalcon_Parsers_Parser, ormDestroyCache);
PHP_METHOD(Phalcon_Parsers_Parser, ormParse);
PHP_METHOD(Phalcon_Parsers_Parser, ormSingleQuotes);
PHP_METHOD(Phalcon_Parsers_Parser, replacePaths);
PHP_METHOD(Phalcon_Parsers_Parser, viewCreateSymbolTable);
PHP_METHOD(Phalcon_Parsers_Parser, voltParse);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_annotationsparse, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, docBlock, IS_STRING, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_geturi, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_getversion, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_ormdestroycache, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_ormparse, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, phql, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_ormsinglequotes, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, input, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_replacepaths, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, paths, 0)
	ZEND_ARG_ARRAY_INFO(0, uri, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_viewcreatesymboltable, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_voltparse, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, viewCode, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, currentPath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_parsers_parser_method_entry) {
	PHP_ME(Phalcon_Parsers_Parser, annotationsParse, arginfo_phalcon_parsers_parser_annotationsparse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, getUri, arginfo_phalcon_parsers_parser_geturi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, getVersion, arginfo_phalcon_parsers_parser_getversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, ormDestroyCache, arginfo_phalcon_parsers_parser_ormdestroycache, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, ormParse, arginfo_phalcon_parsers_parser_ormparse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, ormSingleQuotes, arginfo_phalcon_parsers_parser_ormsinglequotes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, replacePaths, arginfo_phalcon_parsers_parser_replacepaths, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, viewCreateSymbolTable, arginfo_phalcon_parsers_parser_viewcreatesymboltable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, voltParse, arginfo_phalcon_parsers_parser_voltparse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
