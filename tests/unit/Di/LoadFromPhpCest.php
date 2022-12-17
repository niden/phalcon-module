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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Config\Config;
use Phalcon\Config\ConfigInterface;
use Phalcon\Di\Di;
use Phalcon\Di\Exception;
use UnitTester;

/**
 * Class LoadFromPhpCest
 *
 * @package Phalcon\Tests\Unit\Di
 */
class LoadFromPhpCest
{
    /**
     * Unit Tests Phalcon\Di :: loadFromPhp()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function diLoadFromPhp(UnitTester $I)
    {
        $I->wantToTest('Di - loadFromPhp()');

        $container = new Di();

        // load php
        $container->loadFromPhp(dataDir('fixtures/Di/services.php'));

        // there are 3
        $I->assertCount(3, $container->getServices());

        // check some services
        $actual = $container->get('config');
        $I->assertInstanceOf(Config::class, $actual);
        $I->assertInstanceOf(ConfigInterface::class, $actual);

        $I->assertTrue($container->has('config'));
        $I->assertTrue($container->has('unit-test'));
        $I->assertTrue($container->has('component'));
    }
}
