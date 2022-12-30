
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "phalcon/mvc/view/engine/volt/scanner.h"
#include "phalcon/mvc/view/engine/volt/volt.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Proxy class for accessing C parser
 */
ZEPHIR_INIT_CLASS(Phalcon_Parsers_Volt)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Parsers, Volt, phalcon, parsers_volt, phalcon_parsers_volt_method_entry, 0);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_RAW_BUFFER_SIZE"), 256);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_SCANNER_RETCODE_EOF"), -1);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_SCANNER_RETCODE_ERR"), -2);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_SCANNER_RETCODE_IMPOSSIBLE"), -3);

	/** Modes */
	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_MODE_RAW"), 0);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_MODE_CODE"), 1);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_MODE_COMMENT"), 2);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_IGNORE"), 257);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_INTEGER"), 258);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_DOUBLE"), 259);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_STRING"), 260);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NULL"), 261);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_FALSE"), 262);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_TRUE"), 263);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_IDENTIFIER"), 265);

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_ADD"), "+");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_SUB"), "-");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_MUL"), "*");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_DIV"), "/");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_MOD"), "%");

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_AND"), 266);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_OR"), 267);

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_CONCAT"), "~");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_PIPE"), "|");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_DOT"), ".");

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_COMMA"), 269);

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT"), "!");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_LESS"), "<");

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_LESSEQUAL"), 270);

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_GREATER"), ">");

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_GREATEREQUAL"), 271);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_EQUALS"), 272);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOTEQUALS"), 273);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_IDENTICAL"), 274);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOTIDENTICAL"), 275);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_RANGE"), 276);

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_ASSIGN"), "=");

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_COLON"), 277);

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_QUESTION"), "?");

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_POW"), 278);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_INCR"), 279);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_DECR"), 280);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ADD_ASSIGN"), 281);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_SUB_ASSIGN"), 282);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_MUL_ASSIGN"), 283);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_DIV_ASSIGN"), 284);

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_PARENTHESES_OPEN"), "(");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_PARENTHESES_CLOSE"), ")");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_SBRACKET_OPEN"), "[");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_SBRACKET_CLOSE"), "]");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_CBRACKET_OPEN"), "{");

	zephir_declare_class_constant_string(phalcon_parsers_volt_ce, SL("PHVOLT_T_CBRACKET_CLOSE"), "}");

	/** Reserved words */
	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_IF"), 300);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ELSE"), 301);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ELSEIF"), 302);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDIF"), 303);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_FOR"), 304);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDFOR"), 305);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_SET"), 306);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_BLOCK"), 307);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDBLOCK"), 308);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_IN"), 309);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_EXTENDS"), 310);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_IS"), 311);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_DEFINED"), 312);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_INCLUDE"), 313);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_CACHE"), 314);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDCACHE"), 315);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_DO"), 316);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_AUTOESCAPE"), 317);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDAUTOESCAPE"), 318);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_CONTINUE"), 319);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_BREAK"), 320);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ELSEFOR"), 321);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_MACRO"), 322);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDMACRO"), 323);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_WITH"), 324);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_CALL"), 325);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDCALL"), 326);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_RETURN"), 327);

	/** Delimiters */
	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_OPEN_DELIMITER"), 330);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_CLOSE_DELIMITER"), 331);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_OPEN_EDELIMITER"), 332);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_CLOSE_EDELIMITER"), 333);

	/** Special Tokens */
	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_FCALL"), 350);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_EXPR"), 354);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_QUALIFIED"), 355);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENCLOSED"), 356);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_RAW_FRAGMENT"), 357);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_EMPTY_STATEMENT"), 358);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ECHO"), 359);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ARRAY"), 360);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ARRAYACCESS"), 361);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_ISSET"), 362);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ISSET"), 363);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_RESOLVED_EXPR"), 364);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_SLICE"), 365);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_TERNARY"), 366);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_IN"), 367);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_MINUS"), 368);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_PLUS"), 369);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_EMPTY"), 380);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_EVEN"), 381);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ODD"), 382);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NUMERIC"), 383);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_SCALAR"), 384);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ITERABLE"), 385);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ISEMPTY"), 386);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ISEVEN"), 387);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ISODD"), 388);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ISNUMERIC"), 389);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ISSCALAR"), 390);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ISITERABLE"), 391);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_ISEMPTY"), 392);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_ISEVEN"), 393);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_ISODD"), 394);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_ISNUMERIC"), 395);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_ISSCALAR"), 396);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_NOT_ISITERABLE"), 397);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_RAW"), 400);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDRAW"), 401);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_SWITCH"), 411);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_CASE"), 412);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_DEFAULT"), 413);

	zephir_declare_class_constant_long(phalcon_parsers_volt_ce, SL("PHVOLT_T_ENDSWITCH"), 414);

	return SUCCESS;
}

/**
 * Parse the view code
 */
PHP_METHOD(Phalcon_Parsers_Volt, parse)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *viewCode_param = NULL, *currentPath_param = NULL;
	zval viewCode, currentPath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&viewCode);
	ZVAL_UNDEF(&currentPath);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(viewCode)
		Z_PARAM_STR(currentPath)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &viewCode_param, &currentPath_param);
	zephir_get_strval(&viewCode, viewCode_param);
	zephir_get_strval(&currentPath, currentPath_param);


	ZEPHIR_LAST_CALL_STATUS = phvolt_parse_view(return_value, &viewCode, &currentPath);
	zephir_check_call_status();
	RETURN_MM();
}

