<?php

namespace Rector\Tests\TypeDeclaration\Rector\LegacyCallToJClassToJModernRector\Fixture;

use Joomla\CMS\Factory;
use Joomla\CMS\Language\Text;

class SomeClass
{
    public function modernCalls()
    {
        \Joomla\CMS\Factory::getApplication();
        Factory::getUser();
        Text::_('LABEL');
        \Joomla\CMS\Language\Text::sprintf('FORMAT', $value);
    }
}

?>
-----
<?php

namespace Rector\Tests\TypeDeclaration\Rector\LegacyCallToJClassToJModernRector\Fixture;

use Joomla\CMS\Factory;
use Joomla\CMS\Language\Text;

class SomeClass
{
    public function modernCalls()
    {
        JFactory::getApplication();
        JFactory::getUser();
        JText::_('LABEL');
        JText::sprintf('FORMAT', $value);
    }
}

?>
