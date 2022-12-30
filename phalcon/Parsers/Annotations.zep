
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
class Annotations
{
    const PHANNOT_SCANNER_RETCODE_EOF        = -1;
    const PHANNOT_SCANNER_RETCODE_ERR        = -2;
    const PHANNOT_SCANNER_RETCODE_IMPOSSIBLE = -3;

    /** Modes */
    const PHANNOT_MODE_RAW        = 0;
    const PHANNOT_MODE_ANNOTATION = 1;

    const PHANNOT_T_IGNORE = 297;

    const PHANNOT_T_DOCBLOCK_ANNOTATION = 299;
    const PHANNOT_T_ANNOTATION          = 300;

    /* Literals & Identifiers */
    const PHANNOT_T_INTEGER        = 301;
    const PHANNOT_T_DOUBLE         = 302;
    const PHANNOT_T_STRING         = 303;
    const PHANNOT_T_NULL           = 304;
    const PHANNOT_T_FALSE          = 305;
    const PHANNOT_T_TRUE           = 306;
    const PHANNOT_T_IDENTIFIER     = 307;
    const PHANNOT_T_ARRAY          = 308;
    const PHANNOT_T_ARBITRARY_TEXT = 309;

    /* Operators */
    const PHANNOT_T_AT                = "@";
    const PHANNOT_T_DOT               = ".";
    const PHANNOT_T_COMMA             = ",";
    const PHANNOT_T_EQUALS            = "=";
    const PHANNOT_T_COLON             = ":";
    const PHANNOT_T_BRACKET_OPEN      = "{";
    const PHANNOT_T_BRACKET_CLOSE     = "}";
    const PHANNOT_T_SBRACKET_OPEN     = "[";
    const PHANNOT_T_SBRACKET_CLOSE    = "]";
    const PHANNOT_T_PARENTHESES_OPEN  = "(";
    const PHANNOT_T_PARENTHESES_CLOSE = ")";

    /**
     * Parse annotations
     */
    public static function parse(string docBlock, file, line) -> array
    {
        return phannot_parse_annotations(docBlock, file, line);
    }
}
