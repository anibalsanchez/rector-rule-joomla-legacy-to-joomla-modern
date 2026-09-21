<?php

namespace Rector\Tests\TypeDeclaration\Rector\LegacyCallToJClassToJModernRector\Fixture;

use Joomla\CMS\Application\CLI\Output\Processor\ColorProcessor;
use Joomla\CMS\Application\CLI\Output\Processor\ProcessorInterface;

class CliProcessor
{
    public function output(): void
    {
        $color = new \Joomla\CMS\Application\CLI\Output\Processor\ColorProcessor();
        $interface = new class() implements \Joomla\CMS\Application\CLI\Output\Processor\ProcessorInterface {
        };
        echo $color::class, $interface::class;
    }
}

?>
-----
<?php

namespace Rector\Tests\TypeDeclaration\Rector\LegacyCallToJClassToJModernRector\Fixture;

use Joomla\CMS\Application\CLI\Output\Processor\ColorProcessor;
use Joomla\CMS\Application\CLI\Output\Processor\ProcessorInterface;

class CliProcessor
{
    public function output(): void
    {
        $color = new \Joomla\Application\Cli\Output\Processor\ColorProcessor();
        $interface = new class() implements \Joomla\Application\Cli\Output\Processor\ProcessorInterface {
        };
        echo $color::class, $interface::class;
    }
}

?>