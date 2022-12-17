<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Mvc\Model\Resultset\Complex;

use IntegrationTester;

/**
 * Class CurrentCest
 */
class CurrentCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Complex :: current()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetComplexCurrent(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Complex - current()');
        $I->skipTest('Need implementation');
    }
}
