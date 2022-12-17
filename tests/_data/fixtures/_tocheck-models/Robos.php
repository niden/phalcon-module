<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model;

/**
 * @author  David Napierata
 */
class Robos extends Model
{
    public function initialize()
    {
        $this->setSource('robots');

        $this->setConnectionService('dbTwo');
    }
}
