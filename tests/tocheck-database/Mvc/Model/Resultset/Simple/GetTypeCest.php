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

namespace Phalcon\Tests\Integration\Mvc\Model\Resultset\Simple;

use IntegrationTester;

/**
 * Class GetTypeCest
 */
class GetTypeCest
{
    /**
     * Tests Phalcon\Mvc\Model\Resultset\Simple :: getType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelResultsetSimpleGetType(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Resultset\Simple - getType()');
        $I->skipTest('Need implementation');
    }
}
