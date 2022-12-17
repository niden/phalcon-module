
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Arr;

/**
 * Returns a new array with keys of the collection as one element and values
 * as another
 */
class Split
{
    /**
     * @param array $collection
     *
     * @return array
     */
    public function __invoke(array collection) -> array
    {
        return [
            array_keys(collection),
            array_values(collection)
        ];
    }
}
