
extern zend_class_entry *phalcon_config_configfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Config_ConfigFactory);

PHP_METHOD(Phalcon_Config_ConfigFactory, __construct);
PHP_METHOD(Phalcon_Config_ConfigFactory, load);
PHP_METHOD(Phalcon_Config_ConfigFactory, newInstance);
PHP_METHOD(Phalcon_Config_ConfigFactory, getExceptionClass);
PHP_METHOD(Phalcon_Config_ConfigFactory, getServices);
PHP_METHOD(Phalcon_Config_ConfigFactory, parseConfig);
PHP_METHOD(Phalcon_Config_ConfigFactory, checkConfigArray);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_config_configfactory___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_configfactory_load, 0, 1, Phalcon\\Config\\ConfigInterface, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalcon_config_configfactory_newinstance, 0, 2, Phalcon\\Config\\ConfigInterface, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, fileName, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_getexceptionclass, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_parseconfig, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, config)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_config_configfactory_checkconfigarray, 0, 1, IS_VOID, 0)

	ZEND_ARG_ARRAY_INFO(0, config, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_config_configfactory_method_entry) {
	PHP_ME(Phalcon_Config_ConfigFactory, __construct, arginfo_phalcon_config_configfactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Config_ConfigFactory, load, arginfo_phalcon_config_configfactory_load, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config_ConfigFactory, newInstance, arginfo_phalcon_config_configfactory_newinstance, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Config_ConfigFactory, getExceptionClass, arginfo_phalcon_config_configfactory_getexceptionclass, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_ConfigFactory, getServices, arginfo_phalcon_config_configfactory_getservices, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_ConfigFactory, parseConfig, arginfo_phalcon_config_configfactory_parseconfig, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Config_ConfigFactory, checkConfigArray, arginfo_phalcon_config_configfactory_checkconfigarray, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
