<?php

declare(strict_types=1);

namespace Phalcon\Build;

class Generator
{
    /**
     * Directory with Phalcon source code
     *
     * @var string
     */
    protected string $sourceDir;

    /**
     * Directory, where source code for building Phalcon will be put
     *
     * @var string
     */
    protected string $outputDir;

    /**
     * Generator for phalcon.h
     *
     * @var Generator_File_PhalconH
     */
    protected Generator_File_PhalconH $phalconH;

    /**
     * Generator for phalcon.c
     *
     * @var Generator_File_PhalconC
     */
    protected Generator_File_PhalconC $phalconC;

    /**
     * Generator for config.m4
     *
     * @var Generator_File_ConfigM4
     */
    protected Generator_File_ConfigM4 $configM4;

    /**
     * Generator for config.w32
     *
     * @var Generator_File_ConfigW32
     */
    protected Generator_File_ConfigW32 $configW32;

    /**
     * @param string $rootDir
     * @param string $outputDir
     */
    public function __construct(string $rootDir, string $outputDir)
    {
        $this->sourceDir = $rootDir . '/ext';
        $this->outputDir = $outputDir;

        $configDir = $rootDir . '/build/config';

        $this->phalconH = new Generator_File_PhalconH($this->sourceDir, $outputDir);
        $this->phalconC = new Generator_File_PhalconC($rootDir, $this->sourceDir, $configDir, $outputDir);
        $this->configM4 = new Generator_File_ConfigM4($rootDir, $outputDir);
        $this->configW32 = new Generator_File_ConfigW32($rootDir, $outputDir);
    }

    /**
     * Generator source code, from which Phalcon extension can be built
     */
    public function run()
    {
        echo 'Generating build... ';

        Util::cleanDirectory($this->outputDir);
        $this->generateFiles();

        echo "OK\n";
    }

    /**
     * Generate all the files in the output directory
     */
    protected function generateFiles()
    {
        $includedHeaderFiles = $this->phalconH->generate();
        $this->phalconC->generate($includedHeaderFiles);

        $this->configM4->generate();
        $this->configW32->generate();

        copy($this->sourceDir . '/php_phalcon.h', $this->outputDir . '/php_phalcon.h');
        $this->processKernelGlobals();
    }

    /**
     * Resolves headers in the php_phalcon.h file
     */
    protected function processKernelGlobals()
    {
        $lines = [];

        foreach (file($this->outputDir . '/php_phalcon.h') as $line) {
            if (preg_match('@^#include "(kernel/.+)"@', $line, $matches)) {
                $content = file_get_contents($this->sourceDir . DIRECTORY_SEPARATOR . $matches[1]);
                $lines[] = $content . PHP_EOL;
            } else {
                $lines[] = $line;
            }
        }

        file_put_contents($this->outputDir . '/php_phalcon.h', join('', $lines));
    }
}
