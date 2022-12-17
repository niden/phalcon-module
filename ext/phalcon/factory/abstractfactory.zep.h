
extern zend_class_entry *phalcon_factory_abstractfactory_ce;

ZEPHIR_INIT_CLASS(Phalcon_Factory_AbstractFactory);

PHP_METHOD(Phalcon_Factory_AbstractFactory, getServices);
PHP_METHOD(Phalcon_Factory_AbstractFactory, getService);
PHP_METHOD(Phalcon_Factory_AbstractFactory, init);
zend_object *zephir_init_properties_Phalcon_Factory_AbstractFactory(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_factory_abstractfactory_getservices, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_factory_abstractfactory_getservice, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_factory_abstractfactory_init, 0, 0, IS_VOID, 0)

#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, services, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, services, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_factory_abstractfactory_zephir_init_properties_phalcon_factory_abstractfactory, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_factory_abstractfactory_method_entry) {
	PHP_ME(Phalcon_Factory_AbstractFactory, getServices, arginfo_phalcon_factory_abstractfactory_getservices, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Factory_AbstractFactory, getService, arginfo_phalcon_factory_abstractfactory_getservice, ZEND_ACC_PROTECTED)
	PHP_ME(Phalcon_Factory_AbstractFactory, init, arginfo_phalcon_factory_abstractfactory_init, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
