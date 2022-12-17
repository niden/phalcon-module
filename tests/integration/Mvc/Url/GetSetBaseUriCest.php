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

namespace Phalcon\Tests\Integration\Mvc\Url;

use IntegrationTester;
use Phalcon\Mvc\Url;

class GetSetBaseUriCest
{
    /**
     * Tests Phalcon\Mvc\Url :: getBaseUri()/setBaseUri()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcUrlGetSetBaseUri(IntegrationTester $I)
    {
        $I->wantToTest('Url - getBaseUri()/setBaseUri()');
        $url = new Url();

        $path = 'https://phalcon.io';
        $url->setBaseUri($path);

        $expected = $path;
        $actual   = $url->getBaseUri();
        $I->assertEquals($expected, $actual);
    }
}
