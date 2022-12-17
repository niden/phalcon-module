
extern zend_class_entry *phalcon_mvc_micro_lazyloader_ce;

ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_LazyLoader);

PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct);
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, callMethod);
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, getDefinition);
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, getHandler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, definition, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader_callmethod, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_INFO(0, arguments)
	ZEND_ARG_OBJ_INFO(0, modelBinder, Phalcon\\Mvc\\Model\\BinderInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader_getdefinition, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_MASK_EX(arginfo_phalcon_mvc_micro_lazyloader_gethandler, 0, 0, MAY_BE_NULL|MAY_BE_OBJECT)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalcon_mvc_micro_lazyloader_gethandler, 0, 0, IS_OBJECT, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalcon_mvc_micro_lazyloader_method_entry) {
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, __construct, arginfo_phalcon_mvc_micro_lazyloader___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, callMethod, arginfo_phalcon_mvc_micro_lazyloader_callmethod, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, getDefinition, arginfo_phalcon_mvc_micro_lazyloader_getdefinition, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_Micro_LazyLoader, getHandler, arginfo_phalcon_mvc_micro_lazyloader_gethandler, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
