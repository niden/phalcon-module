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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;

/**
 * Class AddForeignKeyCest
 */
class AddForeignKeyCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: addForeignKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoPostgresqlAddForeignKey(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Postgresql - addForeignKey()');
        $I->skipTest('Need implementation');
    }
}