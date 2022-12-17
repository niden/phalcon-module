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

namespace Phalcon\Tests\Database\Mvc\Model;

use DatabaseTester;
use PDO;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Column;
use Phalcon\Db\Enum;
use Phalcon\Db\Index;
use Phalcon\Di\Di;
use Phalcon\Mvc\Model\Manager as ModelsManager;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\Invoices;

use function uniqid;

/**
 * Class GetRelatedCest
 */
class GetRelatedCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Mvc\Model :: getRelated()
     *
     * @param DatabaseTester $I
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-08-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getRelated()');

        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $custId = 2;

        $firstName = uniqid('cust-', true);
        $lastName  = uniqid('cust-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custId, 0, $firstName, $lastName);

        $paidInvoiceId   = 4;
        $unpaidInvoiceId = 5;

        $title = uniqid('inv-');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $paidInvoiceId,
            $custId,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $invoicesMigration->insert(
            $unpaidInvoiceId,
            $custId,
            Invoices::STATUS_UNPAID,
            $title . '-unpaid'
        );

        /**
         * @var Customers $customer
         */
        $customer = Customers::findFirst($custId);
        $invoices = $customer->getRelated(
            'invoices',
            [
                'order' => 'inv_id DESC'
            ]
        );

        $expected = 2;
        $actual   = $invoices->count();
        $I->assertSame($expected, $actual);

        $expected = Invoices::class;
        $actual   = $invoices[0];
        $I->assertInstanceOf($expected, $actual);

        $expected = $unpaidInvoiceId;
        $actual   = $invoices[0]->inv_id;
        $I->assertSame($expected, $actual);

        $expected = $paidInvoiceId;
        $actual   = $invoices[1]->inv_id;
        $I->assertSame($expected, $actual);

        $paidInvoices = $customer->getRelated('paidInvoices');

        $expected = 1;
        $actual   = $paidInvoices->count();
        $I->assertSame($expected, $actual);

        $expected = Invoices::class;
        $actual   = $paidInvoices[0];
        $I->assertInstanceOf($expected, $actual);

        $expected = $paidInvoiceId;
        $actual   = $paidInvoices[0]->inv_id;
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: getRelated() - changing FK
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-01
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetRelatedChangeForeignKey(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getRelated() - Change Foreign Key');

        $this->setNewFactoryDefault();
        $this->setDatabase($I);

        /** @var PDO $connection */
        $connection = $I->getConnection();


        $custIdOne    = 10;
        $firstNameOne = uniqid('cust-1-', true);
        $lastNameOne  = uniqid('cust-1-', true);

        $custIdTwo    = 20;
        $firstNameTwo = uniqid('cust-2-', true);
        $lastNameTwo  = uniqid('cust-2-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custIdOne, 0, $firstNameOne, $lastNameOne);
        $customersMigration->insert($custIdTwo, 0, $firstNameTwo, $lastNameTwo);

        $invoiceId = 40;
        $title = uniqid('inv-');
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );

        /**
         * Find the invoice. Then use `getRelated` to get the customer. It
         * should return CustomerOne.
         *
         * Change the FK to the customer. Call `getRelated` again. It should
         * return CustomerTwo
         */
        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => $invoiceId,
                ]
            ]
        );

        /**
         * Assert that the correct customer is stored
         */
        $expected = $custIdOne;
        $actual   = $invoice->inv_cst_id;
        $I->assertSame($expected, $actual);

        /**
         * Call get related - We should get CustomerOne
         */
        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $I->assertInstanceOf($class, $customer);

        $expected = $custIdOne;
        $actual   = $customer->cst_id;
        $I->assertSame($expected, $actual);

        $invoice->inv_cst_id = $custIdTwo;
        $result = $invoice->save();
        $I->assertTrue($result);

        /**
         * Now call getRelated. We should get CustomerTwo
         */
        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $I->assertInstanceOf($class, $customer);

        $expected = $custIdTwo;
        $actual   = $customer->cst_id;
        $I->assertSame($expected, $actual);

        /**
         * Delete Customer Two and call getRelated again. We should get
         * the cached copy
         */
        $result = $customer->delete();
        $I->assertTrue($result);

        /** @var Customers $customer */
        $customer = $invoice->getRelated('customer');

        $class = Customers::class;
        $I->assertInstanceOf($class, $customer);

        $expected = $custIdTwo;
        $actual   = $customer->cst_id;
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: getRelated() - Property change data
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-12-16
     *
     * @group  sqlite
     */
    public function mvcModelGetRelatedPropertyChangeData(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - getRelated() - Property change data');

        Di::reset();

        $container = new Di();
        $database  = new Sqlite(["dbname" => ":memory:"]);

        $container->set('db', $database);
        $container->set('modelsManager', new ModelsManager());
        $container->set('modelsMetadata', new Memory());

        Di::setDefault($container);

        $database->createTable(
            'co_customers',
            '',
            [
                'columns' => [
                    new Column(
                        'cst_id',
                        [
                            'type'    => Column::TYPE_INTEGER,
                            'size'    => 11,
                            'notNull' => true,
                        ]
                    ),
                    new Column(
                        'cst_status_flag',
                        [
                            'type'    => Column::TYPE_INTEGER,
                            'size'    => 1,
                            'notNull' => true,
                        ]
                    ),
                    new Column(
                        'cst_name_last',
                        [
                            'type'    => Column::TYPE_VARCHAR,
                            'size'    => 100,
                            'notNull' => true,
                        ]
                    ),
                    new Column(
                        'cst_name_first',
                        [
                            'type'    => Column::TYPE_VARCHAR,
                            'size'    => 50,
                            'notNull' => true,
                        ]
                    ),
                ],
                'indexes' => [
                    new Index('PRIMARY', ['cst_id'])
                ],
            ]
        );

        $database->createTable(
            'co_invoices',
            '',
            [
                'columns' => [
                    new Column(
                        'inv_id',
                        [
                            'type'    => Column::TYPE_INTEGER,
                            'size'    => 11,
                            'notNull' => true,
                        ]
                    ),
                    new Column(
                        'inv_cst_id',
                        [
                            'type'    => Column::TYPE_INTEGER,
                            'size'    => 11,
                            'notNull' => true,
                        ]
                    ),
                    new Column(
                        'inv_status_flag',
                        [
                            'type'    => Column::TYPE_INTEGER,
                            'size'    => 1,
                            'notNull' => true,
                        ]
                    ),
                    new Column(
                        'inv_title',
                        [
                            'type'    => Column::TYPE_VARCHAR,
                            'size'    => 255,
                            'notNull' => true,
                        ]
                    ),
                    new Column(
                        'inv_total',
                        [
                            'type'    => Column::TYPE_FLOAT,
                            'size'    => 10,
                            'notNull' => false,
                        ]
                    ),
                    new Column(
                        'inv_created_at',
                        [
                            'type'    => Column::TYPE_DATETIME,
                            'size'    => 255,
                            'notNull' => false,
                        ]
                    ),
                ],
                'indexes' => [
                    new Index('PRIMARY', ['inv_id'])
                ],
            ]
        );

        $title = uniqid('invoice-');
        $database->insert(
            'co_invoices',
            [
                1,
                1,
                1,
                $title,
                100,
                '2022-12-12 10:11:12',
            ],
            [
                'inv_id',
                'inv_cst_id',
                'inv_status_flag',
                'inv_title',
                'inv_total',
                'inv_created_at',
            ]
        );

        $firstName = uniqid('first-');
        $lastName  = uniqid('last-');
        $database->insert(
            'co_customers',
            [
                1,
                1,
                $lastName,
                $firstName,
            ],
            [
                'cst_id',
                'cst_status_flag',
                'cst_name_last',
                'cst_name_first',
            ]
        );

        $invoice = Invoices::findFirst(1);

        /**
         * Reusable relationship
         */
        $expected = $lastName;
        $actual   = $invoice->customer->cst_name_last;
        $I->assertSame($expected, $actual);

        $expected = $firstName;
        $actual   = $invoice->customer->cst_name_first;
        $I->assertSame($expected, $actual);

        /**
         * Non-Reusable relationship
         */
        $expected = $lastName;
        $actual   = $invoice->customer_nocache->cst_name_last;
        $I->assertSame($expected, $actual);

        $expected = $firstName;
        $actual   = $invoice->customer_nocache->cst_name_first;
        $I->assertSame($expected, $actual);

        /**
         * Save a different name and last name
         */
        $newLastName  = uniqid('new-last-');
        $newFirstName = uniqid('new-first-');

        $invoice->customer->cst_name_last  = $newLastName;
        $invoice->customer->cst_name_first = $newFirstName;
        $invoice->save();

        /**
         * Query the database and get the record. Check if the new values
         * have been saved
         */
        $record = $database->fetchOne(
            'SELECT * FROM co_customers WHERE cst_id = 1'
        );

        $expected = $newLastName;
        $actual   = $record['cst_name_last'];
        $I->assertSame($expected, $actual);

        $expected = $newFirstName;
        $actual   = $record['cst_name_first'];
        $I->assertSame($expected, $actual);

        /**
         * Now do a findFirst() and check the relationship
         */
        $updatedInvoice = Invoices::findFirst(1);

        /**
         * Reusable
         */
        $expected = $newLastName;
        $actual   = $updatedInvoice->customer->cst_name_last;
        $I->assertSame($expected, $actual);

        $expected = $newFirstName;
        $actual   = $updatedInvoice->customer->cst_name_first;
        $I->assertSame($expected, $actual);

        /**
         * Non Reusable
         */
        $expected = $newLastName;
        $actual   = $updatedInvoice->customer_nocache->cst_name_last;
        $I->assertSame($expected, $actual);

        $expected = $newFirstName;
        $actual   = $updatedInvoice->customer_nocache->cst_name_first;
        $I->assertSame($expected, $actual);
    }
}
