
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Parsers;

/**
 * Proxy class for accessing C parser
 */
class Volt
{
    const PHVOLT_RAW_BUFFER_SIZE = 256;

    const PHVOLT_SCANNER_RETCODE_EOF        = -1;
    const PHVOLT_SCANNER_RETCODE_ERR        = -2;
    const PHVOLT_SCANNER_RETCODE_IMPOSSIBLE = -3;

    /** Modes */
    const PHVOLT_MODE_RAW     = 0;
    const PHVOLT_MODE_CODE    = 1;
    const PHVOLT_MODE_COMMENT = 2;

    const PHVOLT_T_IGNORE = 257;

    /* Literals & Identifiers */
    const PHVOLT_T_INTEGER    = 258;
    const PHVOLT_T_DOUBLE     = 259;
    const PHVOLT_T_STRING     = 260;
    const PHVOLT_T_NULL       = 261;
    const PHVOLT_T_FALSE      = 262;
    const PHVOLT_T_TRUE       = 263;
    const PHVOLT_T_IDENTIFIER = 265;

    /* Operators */
    const PHVOLT_T_ADD    = '+';
    const PHVOLT_T_SUB    = '-';
    const PHVOLT_T_MUL    = '*';
    const PHVOLT_T_DIV    = '/';
    const PHVOLT_T_MOD    = '%';
    const PHVOLT_T_AND    = 266;
    const PHVOLT_T_OR     = 267;
    const PHVOLT_T_CONCAT = '~';
    const PHVOLT_T_PIPE   = '|';

    const PHVOLT_T_DOT   = '.';
    const PHVOLT_T_COMMA = 269;

    const PHVOLT_T_NOT          = '!';
    const PHVOLT_T_LESS         = '<';
    const PHVOLT_T_LESSEQUAL    = 270;
    const PHVOLT_T_GREATER      = '>';
    const PHVOLT_T_GREATEREQUAL = 271;
    const PHVOLT_T_EQUALS       = 272;
    const PHVOLT_T_NOTEQUALS    = 273;
    const PHVOLT_T_IDENTICAL    = 274;
    const PHVOLT_T_NOTIDENTICAL = 275;
    const PHVOLT_T_RANGE        = 276;
    const PHVOLT_T_ASSIGN       = '=';
    const PHVOLT_T_COLON        = 277;
    const PHVOLT_T_QUESTION     = '?';
    const PHVOLT_T_POW          = 278;
    const PHVOLT_T_INCR         = 279;
    const PHVOLT_T_DECR         = 280;
    const PHVOLT_T_ADD_ASSIGN   = 281;
    const PHVOLT_T_SUB_ASSIGN   = 282;
    const PHVOLT_T_MUL_ASSIGN   = 283;
    const PHVOLT_T_DIV_ASSIGN   = 284;

    const PHVOLT_T_PARENTHESES_OPEN  = '(';
    const PHVOLT_T_PARENTHESES_CLOSE = ')';
    const PHVOLT_T_SBRACKET_OPEN     = '[';
    const PHVOLT_T_SBRACKET_CLOSE    = ']';
    const PHVOLT_T_CBRACKET_OPEN     = '{';
    const PHVOLT_T_CBRACKET_CLOSE    = '}';

    /** Reserved words */
    const PHVOLT_T_IF            = 300;
    const PHVOLT_T_ELSE          = 301;
    const PHVOLT_T_ELSEIF        = 302;
    const PHVOLT_T_ENDIF         = 303;
    const PHVOLT_T_FOR           = 304;
    const PHVOLT_T_ENDFOR        = 305;
    const PHVOLT_T_SET           = 306;
    const PHVOLT_T_BLOCK         = 307;
    const PHVOLT_T_ENDBLOCK      = 308;
    const PHVOLT_T_IN            = 309;
    const PHVOLT_T_EXTENDS       = 310;
    const PHVOLT_T_IS            = 311;
    const PHVOLT_T_DEFINED       = 312;
    const PHVOLT_T_INCLUDE       = 313;
    const PHVOLT_T_CACHE         = 314;
    const PHVOLT_T_ENDCACHE      = 315;
    const PHVOLT_T_DO            = 316;
    const PHVOLT_T_AUTOESCAPE    = 317;
    const PHVOLT_T_ENDAUTOESCAPE = 318;
    const PHVOLT_T_CONTINUE      = 319;
    const PHVOLT_T_BREAK         = 320;
    const PHVOLT_T_ELSEFOR       = 321;
    const PHVOLT_T_MACRO         = 322;
    const PHVOLT_T_ENDMACRO      = 323;
    const PHVOLT_T_WITH          = 324;
    const PHVOLT_T_CALL          = 325;
    const PHVOLT_T_ENDCALL       = 326;
    const PHVOLT_T_RETURN        = 327;

    /** Delimiters */
    const PHVOLT_T_OPEN_DELIMITER   = 330;
    const PHVOLT_T_CLOSE_DELIMITER  = 331;
    const PHVOLT_T_OPEN_EDELIMITER  = 332;
    const PHVOLT_T_CLOSE_EDELIMITER = 333;

    /** Special Tokens */
    const PHVOLT_T_FCALL           = 350;
    const PHVOLT_T_EXPR            = 354;
    const PHVOLT_T_QUALIFIED       = 355;
    const PHVOLT_T_ENCLOSED        = 356;
    const PHVOLT_T_RAW_FRAGMENT    = 357;
    const PHVOLT_T_EMPTY_STATEMENT = 358;
    const PHVOLT_T_ECHO            = 359;
    const PHVOLT_T_ARRAY           = 360;
    const PHVOLT_T_ARRAYACCESS     = 361;
    const PHVOLT_T_NOT_ISSET       = 362;
    const PHVOLT_T_ISSET           = 363;
    const PHVOLT_T_RESOLVED_EXPR   = 364;
    const PHVOLT_T_SLICE           = 365;
    const PHVOLT_T_TERNARY         = 366;
    const PHVOLT_T_NOT_IN          = 367;

    const PHVOLT_T_MINUS = 368;
    const PHVOLT_T_PLUS  = 369;

    const PHVOLT_T_EMPTY    = 380;
    const PHVOLT_T_EVEN     = 381;
    const PHVOLT_T_ODD      = 382;
    const PHVOLT_T_NUMERIC  = 383;
    const PHVOLT_T_SCALAR   = 384;
    const PHVOLT_T_ITERABLE = 385;

    const PHVOLT_T_ISEMPTY    = 386;
    const PHVOLT_T_ISEVEN     = 387;
    const PHVOLT_T_ISODD      = 388;
    const PHVOLT_T_ISNUMERIC  = 389;
    const PHVOLT_T_ISSCALAR   = 390;
    const PHVOLT_T_ISITERABLE = 391;

    const PHVOLT_T_NOT_ISEMPTY    = 392;
    const PHVOLT_T_NOT_ISEVEN     = 393;
    const PHVOLT_T_NOT_ISODD      = 394;
    const PHVOLT_T_NOT_ISNUMERIC  = 395;
    const PHVOLT_T_NOT_ISSCALAR   = 396;
    const PHVOLT_T_NOT_ISITERABLE = 397;

    const PHVOLT_T_RAW    = 400;
    const PHVOLT_T_ENDRAW = 401;

    /* switch-case statement */
    const PHVOLT_T_SWITCH    = 411;
    const PHVOLT_T_CASE      = 412;
    const PHVOLT_T_DEFAULT   = 413;
    const PHVOLT_T_ENDSWITCH = 414;

    /**
     * Parse the view code
     */
    public function parse(string viewCode, string currentPath) -> string
    {
        return phvolt_parse_view(viewCode, currentPath);
    }
}
