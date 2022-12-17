
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Component INPUT[type=file] for forms
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_Element_File)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Forms\\Element, File, phalcon, forms_element_file, phalcon_forms_element_abstractelement_ce, NULL, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_forms_element_file_ce, SL("method"), "inputFile", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

