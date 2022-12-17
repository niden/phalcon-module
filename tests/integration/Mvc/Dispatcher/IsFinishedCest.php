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

namespace Phalcon\Tests\Integration\Mvc\Dispatcher;

use IntegrationTester;

class IsFinishedCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: isFinished()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcDispatcherIsFinished(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - isFinished()');
        $I->skipTest('Need implementation');
    }
}
