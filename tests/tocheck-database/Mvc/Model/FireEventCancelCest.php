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

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;

/**
 * Class FireEventCancelCest
 */
class FireEventCancelCest
{
    /**
     * Tests Phalcon\Mvc\Model :: fireEventCancel()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelFireEventCancel(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model - fireEventCancel()');
        $I->skipTest('Need implementation');
    }
}
