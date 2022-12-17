
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Encryption\Crypt\Padding;

/**
 * Class Zero
 *
 * @package Phalcon\Encryption\Crypt\Padding
 */
class Zero implements PadInterface
{
    /**
     * @param int $paddingSize
     *
     * @return string
     */
    public function pad(int paddingSize) -> string
    {
        return str_repeat(chr(0), paddingSize);
    }

    /**
     * @param string $input
     * @param int    $blockSize
     *
     * @return int
     */
    public function unpad(string input, int blockSize) -> int
    {
        var length, inputArray;
        int counter, paddingSize;

        let length      = mb_strlen(input),
            inputArray  = str_split(input),
            counter     = length - 1,
            paddingSize = 0;

        while (
            counter >= 0 &&
            inputArray[counter] == chr(0) &&
            paddingSize <= blockSize
        ) {
            let paddingSize++,
                counter--;
        }

        return paddingSize;
    }
}
