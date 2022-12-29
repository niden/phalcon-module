
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


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Parsers_Enum)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Parsers, Enum, phalcon, parsers_enum, NULL, 0);

	/** Reserved words */
	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_UPDATE"), 300);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_SET"), 301);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_WHERE"), 302);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_DELETE"), 303);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_FROM"), 304);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_AS"), 305);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_INSERT"), 306);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_INTO"), 307);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_VALUES"), 308);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_SELECT"), 309);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ORDER"), 310);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_BY"), 311);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_LIMIT"), 312);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_GROUP"), 313);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_HAVING"), 314);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_IN"), 315);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ON"), 316);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_INNER"), 317);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_JOIN"), 318);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_LEFT"), 319);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_RIGHT"), 320);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_IS"), 321);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_NULL"), 322);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_NOTIN"), 323);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_CROSS"), 324);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_FULL"), 325);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_OUTER"), 326);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ASC"), 327);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_DESC"), 328);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_OFFSET"), 329);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_DISTINCT"), 330);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_BETWEEN"), 331);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_BETWEEN_NOT"), 332);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_CAST"), 333);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_TRUE"), 334);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_FALSE"), 335);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_CONVERT"), 336);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_USING"), 337);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ALL"), 338);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_FOR"), 339);

	/** Special Tokens */
	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_FCALL"), 350);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_NLIKE"), 351);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_STARALL"), 352);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_DOMAINALL"), 353);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_EXPR"), 354);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_QUALIFIED"), 355);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ENCLOSED"), 356);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_NILIKE"), 357);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_RAW_QUALIFIED"), 358);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_INNERJOIN"), 360);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_LEFTJOIN"), 361);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_RIGHTJOIN"), 362);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_CROSSJOIN"), 363);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_FULLJOIN"), 364);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ISNULL"), 365);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ISNOTNULL"), 366);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_MINUS"), 367);

	/** Postgresql Text Search Operators */
	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_TS_MATCHES"), 401);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_TS_OR"), 402);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_TS_AND"), 403);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_TS_NEGATE"), 404);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_TS_CONTAINS_ANOTHER"), 405);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_TS_CONTAINS_IN"), 406);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_SUBQUERY"), 407);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_EXISTS"), 408);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_CASE"), 409);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_WHEN"), 410);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_ELSE"), 411);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_END"), 412);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_THEN"), 413);

	zephir_declare_class_constant_long(phalcon_parsers_enum_ce, SL("PHQL_T_WITH"), 415);

	return SUCCESS;
}

