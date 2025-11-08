# Joomla Class Aliases Dictionary (J3-J6 Compatibility)

This document provides a unified class alias dictionary for supporting Joomla versions 3, 4, 5, and 6. Use these aliases to maintain compatibility across all Joomla versions.

## Core Framework Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JFactory` | `\Joomla\CMS\Factory` | ✓ | ✓ | ✓ | ✓ | Core factory class |
| `JText` | `\Joomla\CMS\Language\Text` | ✓ | ✓ | ✓ | ✓ | Language/translation |
| `JLog` | `\Joomla\CMS\Log\Log` | ✓ | ✓ | ✓ | ✓ | Logging system |
| `JDate` | `\Joomla\CMS\Date\Date` | ✓ | ✓ | ✓ | ✓ | Date handling |
| `JUri` | `\Joomla\CMS\Uri\Uri` | ✓ | ✓ | ✓ | ✓ | URI manipulation |
| `JVersion` | `\Joomla\CMS\Version` | ✓ | ✓ | ✓ | ✓ | Version information |

## Application Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JApplicationHelper` | `\Joomla\CMS\Application\ApplicationHelper` | ✓ | ✓ | ✓ | ✓ | Application utilities |
| `JApplicationAdministrator` | `\Joomla\CMS\Application\AdministratorApplication` | ✓ | ✓ | ✓ | ✓ | Admin application |
| `JApplicationSite` | `\Joomla\CMS\Application\SiteApplication` | ✓ | ✓ | ✓ | ✓ | Site application |
| `JApplicationCli` | `\Joomla\CMS\Application\CliApplication` | ✓ | ✓ | ✓ | ✓ | CLI application |

## MVC Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JModelLegacy` | `\Joomla\CMS\MVC\Model\BaseDatabaseModel` | ✓ | ✓ | ✓ | ✓ | Base model class |
| `JModelList` | `\Joomla\CMS\MVC\Model\ListModel` | ✓ | ✓ | ✓ | ✓ | List model |
| `JModelItem` | `\Joomla\CMS\MVC\Model\ItemModel` | ✓ | ✓ | ✓ | ✓ | Item model |
| `JModelAdmin` | `\Joomla\CMS\MVC\Model\AdminModel` | ✓ | ✓ | ✓ | ✓ | Admin model |
| `JModelForm` | `\Joomla\CMS\MVC\Model\FormModel` | ✓ | ✓ | ✓ | ✓ | Form model |
| `JViewLegacy` | `\Joomla\CMS\MVC\View\HtmlView` | ✓ | ✓ | ✓ | ✓ | Base view class |
| `JControllerLegacy` | `\Joomla\CMS\MVC\Controller\BaseController` | ✓ | ✓ | ✓ | ✓ | Base controller |
| `JControllerAdmin` | `\Joomla\CMS\MVC\Controller\AdminController` | ✓ | ✓ | ✓ | ✓ | Admin controller |
| `JControllerForm` | `\Joomla\CMS\MVC\Controller\FormController` | ✓ | ✓ | ✓ | ✓ | Form controller |

## Database Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JDatabaseDriver` | `\Joomla\Database\DatabaseDriver` | ✗ | ✓ | ✓ | ✓ | J4+ only |
| `JDatabaseQuery` | `\Joomla\Database\DatabaseQuery` | ✗ | ✓ | ✓ | ✓ | J4+ only |
| `JDatabaseFactory` | `\Joomla\Database\DatabaseFactory` | ✗ | ✓ | ✓ | ✓ | J4+ only |

## Table Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JTable` | `\Joomla\CMS\Table\Table` | ✓ | ✓ | ✓ | ✓ | Base table class |
| `JTableNested` | `\Joomla\CMS\Table\Nested` | ✓ | ✓ | ✓ | ✓ | Nested set table |
| `JTableUser` | `\Joomla\CMS\Table\User` | ✓ | ✓ | ✓ | ✓ | User table |
| `JTableContent` | `\Joomla\CMS\Table\Content` | ✓ | ✓ | ✓ | ✓ | Content table |
| `JTableCategory` | `\Joomla\CMS\Table\Category` | ✓ | ✓ | ✓ | ✓ | Category table |

## Form Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JForm` | `\Joomla\CMS\Form\Form` | ✓ | ✓ | ✓ | ✓ | Form handling |
| `JFormField` | `\Joomla\CMS\Form\FormField` | ✓ | ✓ | ✓ | ✓ | Form field base |
| `JFormHelper` | `\Joomla\CMS\Form\FormHelper` | ✓ | ✓ | ✓ | ✓ | Form utilities |
| `JFormRule` | `\Joomla\CMS\Form\FormRule` | ✓ | ✓ | ✓ | ✓ | Form validation |

## User & Session Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JUser` | `\Joomla\CMS\User\User` | ✓ | ✓ | ✓ | ✓ | User object |
| `JUserHelper` | `\Joomla\CMS\User\UserHelper` | ✓ | ✓ | ✓ | ✓ | User utilities |
| `JSession` | `\Joomla\CMS\Session\Session` | ✓ | ✓ | ✓ | ✓ | Session handling |

## Input & Filter Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JInput` | `\Joomla\CMS\Input\Input` | ✓ | ✓ | ✓ | ✓ | Input handling |
| `JFilterInput` | `\Joomla\CMS\Filter\InputFilter` | ✓ | ✓ | ✓ | ✓ | Input filtering |
| `JFilterOutput` | `\Joomla\CMS\Filter\OutputFilter` | ✓ | ✓ | ✓ | ✓ | Output filtering |

## Helper Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JModuleHelper` | `\Joomla\CMS\Helper\ModuleHelper` | ✓ | ✓ | ✓ | ✓ | Module utilities |
| `JComponentHelper` | `\Joomla\CMS\Component\ComponentHelper` | ✓ | ✓ | ✓ | ✓ | Component utilities |
| `JPluginHelper` | `\Joomla\CMS\Plugin\PluginHelper` | ✓ | ✓ | ✓ | ✓ | Plugin utilities |
| `JLayoutHelper` | `\Joomla\CMS\Layout\LayoutHelper` | ✓ | ✓ | ✓ | ✓ | Layout utilities |

## Plugin Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JPlugin` | `\Joomla\CMS\Plugin\CMSPlugin` | ✓ | ✓ | ✓ | ✓ | Base plugin class |

## Document Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JDocument` | `\Joomla\CMS\Document\Document` | ✓ | ✓ | ✓ | ✓ | Document base |
| `JDocumentHtml` | `\Joomla\CMS\Document\HtmlDocument` | ✓ | ✓ | ✓ | ✓ | HTML document |

## HTML Helper Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JHtml` | `\Joomla\CMS\HTML\HTMLHelper` | ✓ | ✓ | ✓ | ✓ | HTML utilities |

## Filesystem Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JFile` | `\Joomla\CMS\Filesystem\File` | ✓ | ✓ | ✓ | ✓ | File operations |
| `JFolder` | `\Joomla\CMS\Filesystem\Folder` | ✓ | ✓ | ✓ | ✓ | Folder operations |
| `JPath` | `\Joomla\CMS\Filesystem\Path` | ✓ | ✓ | ✓ | ✓ | Path utilities |

## Cache Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JCache` | `\Joomla\CMS\Cache\Cache` | ✓ | ✓ | ✓ | ✓ | Cache system |

## HTTP Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JHttp` | `\Joomla\CMS\Http\Http` | ✓ | ✓ | ✓ | ✓ | HTTP client |
| `JHttpFactory` | `\Joomla\CMS\Http\HttpFactory` | ✓ | ✓ | ✓ | ✓ | HTTP factory |

## Mail Classes

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JMail` | `\Joomla\CMS\Mail\Mail` | ✓ | ✓ | ✓ | ✓ | Mail system |
| `JMailHelper` | `\Joomla\CMS\Mail\MailHelper` | ✓ | ✓ | ✓ | ✓ | Mail utilities |

## Extension Classes (J4+)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `ActionLogPlugin` | `\Joomla\Component\Actionlogs\Administrator\Plugin\ActionLogPlugin` | ✗ | ✓ | ✓ | ✓ | Action log plugin |
| `FieldsPlugin` | `\Joomla\Component\Fields\Administrator\Plugin\FieldsPlugin` | ✗ | ✓ | ✓ | ✓ | Fields plugin |
| `PrivacyPlugin` | `\Joomla\Component\Privacy\Administrator\Plugin\PrivacyPlugin` | ✗ | ✓ | ✓ | ✓ | Privacy plugin |
| `ContentHelperRoute` | `\Joomla\Component\Content\Site\Helper\RouteHelper` | ✗ | ✓ | ✓ | ✓ | Content routing |
| `FinderIndexer` | `\Joomla\Component\Finder\Administrator\Indexer\Indexer` | ✗ | ✓ | ✓ | ✓ | Finder indexer |

## Deprecated Classes (J3 Only)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 | Notes |
|--------------|------------------|----|----|----|----|-------|
| `JRegistryFormat` | `\Joomla\Registry\AbstractRegistryFormat` | ✓ | ✗ | ✗ | ✗ | Removed in J4 |
| `JLanguageStemmer` | `\Joomla\CMS\Language\LanguageStemmer` | ✓ | ✗ | ✗ | ✗ | Removed in J4 |
| `JCryptPassword` | `\Joomla\CMS\Crypt\CryptPassword` | ✓ | ✗ | ✗ | ✗ | Removed in J4 |

## Usage Recommendations

### For Maximum Compatibility (J3-J6)

Always use the legacy aliases for classes that are available across all versions:

```php
// ✅ Good - Works in J3-J6
$app = JFactory::getApplication();
$db = JFactory::getDbo();
$user = JFactory::getUser();
$text = JText::_('COM_EXAMPLE_LABEL');

// ✅ Good - Version check for J4+ features
if (version_compare(JVERSION, '4.0', '>=')) {
    // Use J4+ specific features
}
```

### For J4+ Only Extensions

Use modern namespaces directly:

```php
// ✅ Good for J4+ only
use Joomla\CMS\Factory;
use Joomla\CMS\Language\Text;
use Joomla\Database\DatabaseInterface;
```

### Version Detection Pattern

```php
// Check Joomla version for compatibility
if (version_compare(JVERSION, '4.0', '>=')) {
    // J4+ code
    $db = Factory::getContainer()->get(DatabaseInterface::class);
} else {
    // J3 code
    $db = JFactory::getDbo();
}
```

## Best Practices

1. **Use Legacy Aliases**: For maximum compatibility, always use the `J*` aliases
2. **Version Checks**: Implement version checks when using J4+ specific features
3. **Fallback Patterns**: Always provide J3 fallbacks for new functionality
4. **Testing**: Test your code on all target Joomla versions
5. **Documentation**: Document version requirements clearly

## Notes

- ✓ = Available in this version
- ✗ = Not available in this version
- All aliases marked as available are registered via `JLoader::registerAlias()`
- Database classes are only available as aliases in J4+
- Extension-specific classes are only available in J4+
- Some classes were removed or deprecated between versions