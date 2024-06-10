
extern zend_class_entry *phalcon_parsers_parser_ce;

ZEPHIR_INIT_CLASS(Phalcon_Parsers_Parser);

PHP_METHOD(Phalcon_Parsers_Parser, annotationsParse);
PHP_METHOD(Phalcon_Parsers_Parser, getUri);
PHP_METHOD(Phalcon_Parsers_Parser, getVersion);
PHP_METHOD(Phalcon_Parsers_Parser, ormDestroyCache);
PHP_METHOD(Phalcon_Parsers_Parser, ormParse);
PHP_METHOD(Phalcon_Parsers_Parser, ormSingleQuotes);
PHP_METHOD(Phalcon_Parsers_Parser, replacePaths);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetEvents);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetCaseInsensitiveColumnMap);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetCastLastInsertIdToInt);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetCastOnHydrate);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetColumnRenaming);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetDisableAssignSetters);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetEnableLiterals);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetExceptionOnFailedSave);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetExceptionOnFailedMetadataSave);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetNotNullValidations);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetIgnoreUnknownColumns);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetLateStateBinding);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetResultsetPrefetchRecords);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetUpdateSnapshotOnSave);
PHP_METHOD(Phalcon_Parsers_Parser, settingGetVirtualForeignKeys);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetEvents);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetCaseInsensitiveColumnMap);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetCastLastInsertIdToInt);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetCastOnHydrate);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetColumnRenaming);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetDisableAssignSetters);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetEnableLiterals);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetExceptionOnFailedSave);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetExceptionOnFailedMetadataSave);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetNotNullValidations);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetIgnoreUnknownColumns);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetLateStateBinding);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetResultsetPrefetchRecords);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetUpdateSnapshotOnSave);
PHP_METHOD(Phalcon_Parsers_Parser, settingSetVirtualForeignKeys);
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetevents, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetcaseinsensitivecolumnmap, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetcastlastinsertidtoint, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetcastonhydrate, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetcolumnrenaming, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetdisableassignsetters, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetenableliterals, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetexceptiononfailedsave, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetexceptiononfailedmetadatasave, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetnotnullvalidations, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetignoreunknowncolumns, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetlatestatebinding, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_parsers_parser_settinggetresultsetprefetchrecords, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetupdatesnapshotonsave, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settinggetvirtualforeignkeys, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetevents, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetcaseinsensitivecolumnmap, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetcastlastinsertidtoint, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetcastonhydrate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetcolumnrenaming, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetdisableassignsetters, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetenableliterals, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetexceptiononfailedsave, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetexceptiononfailedmetadatasave, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetnotnullvalidations, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetignoreunknowncolumns, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetlatestatebinding, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetresultsetprefetchrecords, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetupdatesnapshotonsave, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_parsers_parser_settingsetvirtualforeignkeys, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
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
	PHP_ME(Phalcon_Parsers_Parser, settingGetEvents, arginfo_phalcon_parsers_parser_settinggetevents, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetCaseInsensitiveColumnMap, arginfo_phalcon_parsers_parser_settinggetcaseinsensitivecolumnmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetCastLastInsertIdToInt, arginfo_phalcon_parsers_parser_settinggetcastlastinsertidtoint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetCastOnHydrate, arginfo_phalcon_parsers_parser_settinggetcastonhydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetColumnRenaming, arginfo_phalcon_parsers_parser_settinggetcolumnrenaming, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetDisableAssignSetters, arginfo_phalcon_parsers_parser_settinggetdisableassignsetters, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetEnableLiterals, arginfo_phalcon_parsers_parser_settinggetenableliterals, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetExceptionOnFailedSave, arginfo_phalcon_parsers_parser_settinggetexceptiononfailedsave, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetExceptionOnFailedMetadataSave, arginfo_phalcon_parsers_parser_settinggetexceptiononfailedmetadatasave, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetNotNullValidations, arginfo_phalcon_parsers_parser_settinggetnotnullvalidations, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetIgnoreUnknownColumns, arginfo_phalcon_parsers_parser_settinggetignoreunknowncolumns, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetLateStateBinding, arginfo_phalcon_parsers_parser_settinggetlatestatebinding, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
PHP_ME(Phalcon_Parsers_Parser, settingGetResultsetPrefetchRecords, arginfo_phalcon_parsers_parser_settinggetresultsetprefetchrecords, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetUpdateSnapshotOnSave, arginfo_phalcon_parsers_parser_settinggetupdatesnapshotonsave, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingGetVirtualForeignKeys, arginfo_phalcon_parsers_parser_settinggetvirtualforeignkeys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetEvents, arginfo_phalcon_parsers_parser_settingsetevents, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetCaseInsensitiveColumnMap, arginfo_phalcon_parsers_parser_settingsetcaseinsensitivecolumnmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetCastLastInsertIdToInt, arginfo_phalcon_parsers_parser_settingsetcastlastinsertidtoint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetCastOnHydrate, arginfo_phalcon_parsers_parser_settingsetcastonhydrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetColumnRenaming, arginfo_phalcon_parsers_parser_settingsetcolumnrenaming, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetDisableAssignSetters, arginfo_phalcon_parsers_parser_settingsetdisableassignsetters, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetEnableLiterals, arginfo_phalcon_parsers_parser_settingsetenableliterals, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetExceptionOnFailedSave, arginfo_phalcon_parsers_parser_settingsetexceptiononfailedsave, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetExceptionOnFailedMetadataSave, arginfo_phalcon_parsers_parser_settingsetexceptiononfailedmetadatasave, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetNotNullValidations, arginfo_phalcon_parsers_parser_settingsetnotnullvalidations, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetIgnoreUnknownColumns, arginfo_phalcon_parsers_parser_settingsetignoreunknowncolumns, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetLateStateBinding, arginfo_phalcon_parsers_parser_settingsetlatestatebinding, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetResultsetPrefetchRecords, arginfo_phalcon_parsers_parser_settingsetresultsetprefetchrecords, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetUpdateSnapshotOnSave, arginfo_phalcon_parsers_parser_settingsetupdatesnapshotonsave, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, settingSetVirtualForeignKeys, arginfo_phalcon_parsers_parser_settingsetvirtualforeignkeys, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, viewCreateSymbolTable, arginfo_phalcon_parsers_parser_viewcreatesymboltable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Parsers_Parser, voltParse, arginfo_phalcon_parsers_parser_voltparse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
