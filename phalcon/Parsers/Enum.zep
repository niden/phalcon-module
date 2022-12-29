<?php
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Parsers;

class Enum
{
    /** Reserved words */
    const PHQL_T_UPDATE      = 300;
    const PHQL_T_SET         = 301;
    const PHQL_T_WHERE       = 302;
    const PHQL_T_DELETE      = 303;
    const PHQL_T_FROM        = 304;
    const PHQL_T_AS          = 305;
    const PHQL_T_INSERT      = 306;
    const PHQL_T_INTO        = 307;
    const PHQL_T_VALUES      = 308;
    const PHQL_T_SELECT      = 309;
    const PHQL_T_ORDER       = 310;
    const PHQL_T_BY          = 311;
    const PHQL_T_LIMIT       = 312;
    const PHQL_T_GROUP       = 313;
    const PHQL_T_HAVING      = 314;
    const PHQL_T_IN          = 315;
    const PHQL_T_ON          = 316;
    const PHQL_T_INNER       = 317;
    const PHQL_T_JOIN        = 318;
    const PHQL_T_LEFT        = 319;
    const PHQL_T_RIGHT       = 320;
    const PHQL_T_IS          = 321;
    const PHQL_T_NULL        = 322;
    const PHQL_T_NOTIN       = 323;
    const PHQL_T_CROSS       = 324;
    const PHQL_T_FULL        = 325;
    const PHQL_T_OUTER       = 326;
    const PHQL_T_ASC         = 327;
    const PHQL_T_DESC        = 328;
    const PHQL_T_OFFSET      = 329;
    const PHQL_T_DISTINCT    = 330;
    const PHQL_T_BETWEEN     = 331;
    const PHQL_T_BETWEEN_NOT = 332;
    const PHQL_T_CAST        = 333;
    const PHQL_T_TRUE        = 334;
    const PHQL_T_FALSE       = 335;
    const PHQL_T_CONVERT     = 336;
    const PHQL_T_USING       = 337;
    const PHQL_T_ALL         = 338;
    const PHQL_T_FOR         = 339;

    cial Tokens */
    const PHQL_T_FCALL         = 350;
    const PHQL_T_NLIKE         = 351;
    const PHQL_T_STARALL       = 352;
    const PHQL_T_DOMAINALL     = 353;
    const PHQL_T_EXPR          = 354;
    const PHQL_T_QUALIFIED     = 355;
    const PHQL_T_ENCLOSED      = 356;
    const PHQL_T_NILIKE        = 357;
    const PHQL_T_RAW_QUALIFIED = 358;

    const PHQL_T_INNERJOIN = 360;
    const PHQL_T_LEFTJOIN  = 361;
    const PHQL_T_RIGHTJOIN = 362;
    const PHQL_T_CROSSJOIN = 363;
    const PHQL_T_FULLJOIN  = 364;
    const PHQL_T_ISNULL    = 365;
    const PHQL_T_ISNOTNULL = 366;
    const PHQL_T_MINUS     = 367;

    tgresql Text Search Operators */
    const PHQL_T_TS_MATCHES          = 401;
    const PHQL_T_TS_OR               = 402;
    const PHQL_T_TS_AND              = 403;
    const PHQL_T_TS_NEGATE           = 404;
    const PHQL_T_TS_CONTAINS_ANOTHER = 405;
    const PHQL_T_TS_CONTAINS_IN      = 406;

    const PHQL_T_SUBQUERY = 407;
    const PHQL_T_EXISTS   = 408;

    const PHQL_T_CASE = 409;
    const PHQL_T_WHEN = 410;
    const PHQL_T_ELSE = 411;
    const PHQL_T_END  = 412;
    const PHQL_T_THEN = 413;
    const PHQL_T_WITH = 415;
}
