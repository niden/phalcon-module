
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "phalcon.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


#include "phalcon/mvc/model/orm.h"

zend_class_entry *phalcon_annotations_exception_ce;
zend_class_entry *phalcon_mvc_model_exception_ce;
zend_class_entry *phalcon_mvc_view_exception_ce;
zend_class_entry *phalcon_parsers_parser_ce;

ZEND_DECLARE_MODULE_GLOBALS(phalcon)

PHP_INI_BEGIN()
	STD_PHP_INI_BOOLEAN("phalcon.db.escape_identifiers", "1", PHP_INI_ALL, OnUpdateBool, db.escape_identifiers, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.db.force_casting", "0", PHP_INI_ALL, OnUpdateBool, db.force_casting, zend_phalcon_globals, phalcon_globals)
	
	
	STD_PHP_INI_BOOLEAN("phalcon.orm.case_insensitive_column_map", "0", PHP_INI_ALL, OnUpdateBool, orm.case_insensitive_column_map, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.cast_last_insert_id_to_int", "0", PHP_INI_ALL, OnUpdateBool, orm.cast_last_insert_id_to_int, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.cast_on_hydrate", "0", PHP_INI_ALL, OnUpdateBool, orm.cast_on_hydrate, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.column_renaming", "1", PHP_INI_ALL, OnUpdateBool, orm.column_renaming, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.disable_assign_setters", "0", PHP_INI_ALL, OnUpdateBool, orm.disable_assign_setters, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.enable_implicit_joins", "1", PHP_INI_ALL, OnUpdateBool, orm.enable_implicit_joins, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.enable_literals", "1", PHP_INI_ALL, OnUpdateBool, orm.enable_literals, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.events", "1", PHP_INI_ALL, OnUpdateBool, orm.events, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.exception_on_failed_save", "0", PHP_INI_ALL, OnUpdateBool, orm.exception_on_failed_save, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.exception_on_failed_metadata_save", "1", PHP_INI_ALL, OnUpdateBool, orm.exception_on_failed_metadata_save, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.ignore_unknown_columns", "0", PHP_INI_ALL, OnUpdateBool, orm.ignore_unknown_columns, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.late_state_binding", "0", PHP_INI_ALL, OnUpdateBool, orm.late_state_binding, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.not_null_validations", "1", PHP_INI_ALL, OnUpdateBool, orm.not_null_validations, zend_phalcon_globals, phalcon_globals)
	
	STD_PHP_INI_ENTRY("phalcon.orm.resultset_prefetch_records", "0", PHP_INI_ALL, NULL, orm.resultset_prefetch_records, zend_phalcon_globals, phalcon_globals)
	
	STD_PHP_INI_BOOLEAN("phalcon.orm.update_snapshot_on_save", "1", PHP_INI_ALL, OnUpdateBool, orm.update_snapshot_on_save, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.orm.virtual_foreign_keys", "1", PHP_INI_ALL, OnUpdateBool, orm.virtual_foreign_keys, zend_phalcon_globals, phalcon_globals)
	STD_PHP_INI_BOOLEAN("phalcon.warning.enable", "1", PHP_INI_ALL, OnUpdateBool, warning.enable, zend_phalcon_globals, phalcon_globals)
PHP_INI_END()

static PHP_MINIT_FUNCTION(phalcon)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Phalcon_Annotations_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_Model_Exception);
	ZEPHIR_INIT(Phalcon_Mvc_View_Exception);
	ZEPHIR_INIT(Phalcon_Parsers_Parser);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(phalcon)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_phalcon_globals *phalcon_globals)
{
	phalcon_globals->initialized = 0;

	/* Cache Enabled */
	phalcon_globals->cache_enabled = 1;

	/* Recursive Lock */
	phalcon_globals->recursive_lock = 0;

	/* Static cache */
	memset(phalcon_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	

	phalcon_globals->orm.ast_cache = NULL;
	phalcon_globals->orm.cache_level = 3;













	phalcon_globals->orm.parser_cache = NULL;
	phalcon_globals->orm.resultset_prefetch_records = ZSTR_VAL(zend_string_init(ZEND_STRL("0"), 0));
	phalcon_globals->orm.unique_cache_id = 3;



	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_phalcon_globals *phalcon_globals)
{
	
}

static PHP_RINIT_FUNCTION(phalcon)
{
	zend_phalcon_globals *phalcon_globals_ptr;
	phalcon_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(phalcon_globals_ptr);
	zephir_initialize_memory(phalcon_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(phalcon)
{
	phalcon_orm_destroy_cache();
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(phalcon)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_PHALCON_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_PHALCON_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_PHALCON_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_PHALCON_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_PHALCON_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(phalcon)
{
#if defined(COMPILE_DL_PHALCON) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(phalcon_globals);
	php_zephir_init_module_globals(phalcon_globals);
}

static PHP_GSHUTDOWN_FUNCTION(phalcon)
{
	
}


zend_function_entry php_phalcon_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_phalcon_deps[] = {
	ZEND_MOD_REQUIRED("pdo")
	ZEND_MOD_REQUIRED("spl")
	ZEND_MOD_REQUIRED("standard")
	ZEND_MOD_REQUIRED("hash")
	ZEND_MOD_REQUIRED("json")
	ZEND_MOD_END
};

zend_module_entry phalcon_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_phalcon_deps,
	PHP_PHALCON_EXTNAME,
	php_phalcon_functions,
	PHP_MINIT(phalcon),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(phalcon),
#else
	NULL,
#endif
	PHP_RINIT(phalcon),
	PHP_RSHUTDOWN(phalcon),
	PHP_MINFO(phalcon),
	PHP_PHALCON_VERSION,
	ZEND_MODULE_GLOBALS(phalcon),
	PHP_GINIT(phalcon),
	PHP_GSHUTDOWN(phalcon),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(phalcon),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_PHALCON
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(phalcon)
#endif
