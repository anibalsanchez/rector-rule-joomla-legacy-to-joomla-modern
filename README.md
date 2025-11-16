# Rector Rule Joomla Legacy To Joomla Modern

A Rector rule to modernize Joomla class calls by converting legacy J-class aliases to modern namespaced classes.

## Why Use This Rule?

This rule helps modernize Joomla code by converting legacy J-class aliases (like `JFactory`, `JText`) to their modern namespaced equivalents. This improves code readability, follows modern PHP standards, and prepares your codebase for future Joomla versions.

**Before:**

```php
$app = JFactory::getApplication();
$text = JText::_('COM_EXAMPLE_LABEL');
```

**After:**

```php
$app = \Joomla\CMS\Factory::getApplication();
$text = \Joomla\CMS\Language\Text::_('COM_EXAMPLE_LABEL');
```

### ⚠️ Joomla 3-6 Compatibility Notice

This rule supports Joomla 3 through Joomla 6, but here's the catch:

- **Joomla 3-4-5**: Your code runs natively without any compatibility plugin. Life is good.
- **Joomla 6**: Surprise! You'll need the compatibility plugin again because someone decided to move classes to yet another namespace location (`\Joomla\Filesystem\*`, `\Joomla\Input\*`, etc.). Same classes, different folders. Again.

So yes, you're modernizing your code to use namespaces that will themselves become legacy in J6. But at least you'll be ready for the next round of namespace musical chairs. 🎪

## Quick Start

### Installation

Clone the repository and add the rule to `rector.php`.

### Add to rector.php

```php
<?php

require_once '.../src/Rector/LegacyCallToJClassToJModernRector.php';

use Rector\Config\RectorConfig;
use Utils\Rector\Rector\LegacyCallToJClassToJModernRector;

return RectorConfig::configure()
    ->withRules([
        LegacyCallToJClassToJModernRector::class,
    ]);
```

### Run Rector

```bash
vendor/bin/rector process src/
```

## Coverage

This rector rule includes **473 class mappings** covering:

- Core Framework (Registry, Data, String classes)
- Application (Admin, Site, CLI, Web)
- MVC (Models, Views, Controllers)
- Database (Drivers, Query builders, Importers/Exporters)
- Tables (All core tables)
- Forms (70+ form fields, 14 form rules)
- User & Session
- Input & Filters
- Helpers (Module, Component, Plugin, Layout, Content, Tags, etc.)
- Documents (HTML, JSON, XML, Feed, Raw, Error)
- HTML Helpers (30+ helpers)
- Filesystem (File, Folder, Path, Stream)
- Cache (Controllers, Storage adapters)
- HTTP (Client, Factory, Transport)
- Mail
- Language & Translation
- Access & ACL
- Router & Menu
- Categories & Pagination
- Installer & Updater
- Toolbar
- Editor & Captcha
- Authentication & Browser
- Profiler & Image
- Feed & Client (FTP, LDAP)
- Crypt & String utilities
- Extension classes (ActionLog, Fields, Privacy, Finder, Tags)

## Joomla Version Compatibility

- ✓ = Available in this version
- ✗ = Not available in this version

Most classes are available across J3-J6. Key differences:

- **Database classes** (`JDatabaseDriver`, `JDatabaseQuery`, etc.) are only available in J4+
- **Extension classes** (`ActionLogPlugin`, `FieldsPlugin`, etc.) are only available in J4+
- Some J3-only classes were removed in J4 (e.g., `JRegistryFormat`, `JLanguageStemmer`)

## Complete Class Mapping Reference

### Core Framework Classes (10)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JFactory` | `\Joomla\CMS\Factory` | ✓ | ✓ | ✓ | ✓ |
| `JText` | `\Joomla\CMS\Language\Text` | ✓ | ✓ | ✓ | ✓ |
| `JLog` | `\Joomla\CMS\Log\Log` | ✓ | ✓ | ✓ | ✓ |
| `JDate` | `\Joomla\CMS\Date\Date` | ✓ | ✓ | ✓ | ✓ |
| `JUri` | `\Joomla\CMS\Uri\Uri` | ✓ | ✓ | ✓ | ✓ |
| `JVersion` | `\Joomla\CMS\Version` | ✓ | ✓ | ✓ | ✓ |
| `JRegistry` | `\Joomla\Registry\Registry` | ✓ | ✓ | ✓ | ✓ |
| `JData` | `\Joomla\Data\DataObject` | ✓ | ✓ | ✓ | ✓ |
| `JDataSet` | `\Joomla\Data\DataSet` | ✓ | ✓ | ✓ | ✓ |
| `JObject` | `\Joomla\CMS\Object\CMSObject` | ✓ | ✓ | ✓ | ✓ |

### Application Classes (10)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JApplicationHelper` | `\Joomla\CMS\Application\ApplicationHelper` | ✓ | ✓ | ✓ | ✓ |
| `JApplicationAdministrator` | `\Joomla\CMS\Application\AdministratorApplication` | ✓ | ✓ | ✓ | ✓ |
| `JApplicationSite` | `\Joomla\CMS\Application\SiteApplication` | ✓ | ✓ | ✓ | ✓ |
| `JApplicationCli` | `\Joomla\CMS\Application\CliApplication` | ✓ | ✓ | ✓ | ✓ |
| `JApplicationBase` | `\Joomla\CMS\Application\BaseApplication` | ✓ | ✓ | ✓ | ✓ |
| `JApplicationCms` | `\Joomla\CMS\Application\CMSApplication` | ✓ | ✓ | ✓ | ✓ |
| `JApplicationWeb` | `\Joomla\CMS\Application\WebApplication` | ✓ | ✓ | ✓ | ✓ |
| `JApplicationDaemon` | `\Joomla\CMS\Application\DaemonApplication` | ✓ | ✓ | ✓ | ✓ |
| `JCli` | `\Joomla\CMS\Application\CliApplication` | ✓ | ✓ | ✓ | ✓ |
| `JDaemon` | `\Joomla\CMS\Application\DaemonApplication` | ✓ | ✓ | ✓ | ✓ |

### MVC Classes (12)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JModelLegacy` | `\Joomla\CMS\MVC\Model\BaseDatabaseModel` | ✓ | ✓ | ✓ | ✓ |
| `JModelList` | `\Joomla\CMS\MVC\Model\ListModel` | ✓ | ✓ | ✓ | ✓ |
| `JModelItem` | `\Joomla\CMS\MVC\Model\ItemModel` | ✓ | ✓ | ✓ | ✓ |
| `JModelAdmin` | `\Joomla\CMS\MVC\Model\AdminModel` | ✓ | ✓ | ✓ | ✓ |
| `JModelForm` | `\Joomla\CMS\MVC\Model\FormModel` | ✓ | ✓ | ✓ | ✓ |
| `JViewLegacy` | `\Joomla\CMS\MVC\View\HtmlView` | ✓ | ✓ | ✓ | ✓ |
| `JViewCategories` | `\Joomla\CMS\MVC\View\CategoriesView` | ✓ | ✓ | ✓ | ✓ |
| `JViewCategory` | `\Joomla\CMS\MVC\View\CategoryView` | ✓ | ✓ | ✓ | ✓ |
| `JViewCategoryfeed` | `\Joomla\CMS\MVC\View\CategoryFeedView` | ✓ | ✓ | ✓ | ✓ |
| `JControllerLegacy` | `\Joomla\CMS\MVC\Controller\BaseController` | ✓ | ✓ | ✓ | ✓ |
| `JControllerAdmin` | `\Joomla\CMS\MVC\Controller\AdminController` | ✓ | ✓ | ✓ | ✓ |
| `JControllerForm` | `\Joomla\CMS\MVC\Controller\FormController` | ✓ | ✓ | ✓ | ✓ |

### Database Classes (30) - J4+ Only

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JDatabaseDriver` | `\Joomla\Database\DatabaseDriver` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseQuery` | `\Joomla\Database\DatabaseQuery` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseFactory` | `\Joomla\Database\DatabaseFactory` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseInterface` | `\Joomla\Database\DatabaseInterface` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseIterator` | `\Joomla\Database\DatabaseIterator` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseExporter` | `\Joomla\Database\DatabaseExporter` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseImporter` | `\Joomla\Database\DatabaseImporter` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseDriverMysqli` | `\Joomla\Database\Mysqli\MysqliDriver` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseDriverPdo` | `\Joomla\Database\Pdo\PdoDriver` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseDriverPdomysql` | `\Joomla\Database\Mysql\MysqlDriver` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseDriverPgsql` | `\Joomla\Database\Pgsql\PgsqlDriver` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseDriverSqlite` | `\Joomla\Database\Sqlite\SqliteDriver` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseDriverSqlsrv` | `\Joomla\Database\Sqlsrv\SqlsrvDriver` | ✗ | ✓ | ✓ | ✓ |
| `JDatabaseDriverSqlazure` | `\Joomla\Database\Sqlazure\SqlazureDriver` | ✗ | ✓ | ✓ | ✓ |

### Table Classes (16)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JTable` | `\Joomla\CMS\Table\Table` | ✓ | ✓ | ✓ | ✓ |
| `JTableNested` | `\Joomla\CMS\Table\Nested` | ✓ | ✓ | ✓ | ✓ |
| `JTableUser` | `\Joomla\CMS\Table\User` | ✓ | ✓ | ✓ | ✓ |
| `JTableContent` | `\Joomla\CMS\Table\Content` | ✓ | ✓ | ✓ | ✓ |
| `JTableCategory` | `\Joomla\CMS\Table\Category` | ✓ | ✓ | ✓ | ✓ |
| `JTableAsset` | `\Joomla\CMS\Table\Asset` | ✓ | ✓ | ✓ | ✓ |
| `JTableExtension` | `\Joomla\CMS\Table\Extension` | ✓ | ✓ | ✓ | ✓ |
| `JTableLanguage` | `\Joomla\CMS\Table\Language` | ✓ | ✓ | ✓ | ✓ |
| `JTableMenu` | `\Joomla\CMS\Table\Menu` | ✓ | ✓ | ✓ | ✓ |
| `JTableMenuType` | `\Joomla\CMS\Table\MenuType` | ✓ | ✓ | ✓ | ✓ |
| `JTableModule` | `\Joomla\CMS\Table\Module` | ✓ | ✓ | ✓ | ✓ |
| `JTableUpdate` | `\Joomla\CMS\Table\Update` | ✓ | ✓ | ✓ | ✓ |
| `JTableUpdatesite` | `\Joomla\CMS\Table\UpdateSite` | ✓ | ✓ | ✓ | ✓ |
| `JTableUsergroup` | `\Joomla\CMS\Table\Usergroup` | ✓ | ✓ | ✓ | ✓ |
| `JTableViewlevel` | `\Joomla\CMS\Table\ViewLevel` | ✓ | ✓ | ✓ | ✓ |
| `JTableContenthistory` | `\Joomla\CMS\Table\ContentHistory` | ✓ | ✓ | ✓ | ✓ |

### Form Classes (88 total: 4 base + 70 fields + 14 rules)

**Base Form Classes:**

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JForm` | `\Joomla\CMS\Form\Form` | ✓ | ✓ | ✓ | ✓ |
| `JFormField` | `\Joomla\CMS\Form\FormField` | ✓ | ✓ | ✓ | ✓ |
| `JFormHelper` | `\Joomla\CMS\Form\FormHelper` | ✓ | ✓ | ✓ | ✓ |
| `JFormRule` | `\Joomla\CMS\Form\FormRule` | ✓ | ✓ | ✓ | ✓ |

**Form Fields (70):** All available in J3-J6

- `JFormFieldAccessLevel`, `JFormFieldAliastag`, `JFormFieldAuthor`, `JFormFieldCacheHandler`, `JFormFieldCalendar`, `JFormFieldCaptcha`, `JFormFieldCategory`, `JFormFieldCheckbox`, `JFormFieldCheckboxes`, `JFormFieldChromeStyle`, `JFormFieldColor`, `JFormFieldCombo`, `JFormFieldComponentlayout`, `JFormFieldComponents`, `JFormFieldContenthistory`, `JFormFieldContentlanguage`, `JFormFieldContenttype`, `JFormFieldDatabaseConnection`, `JFormFieldEditor`, `JFormFieldEMail`, `JFormFieldFile`, `JFormFieldFileList`, `JFormFieldFolderList`, `JFormFieldFrontend_Language`, `JFormFieldGroupedList`, `JFormFieldHeadertag`, `JFormFieldHidden`, `JFormFieldImageList`, `JFormFieldInteger`, `JFormFieldLanguage`, `JFormFieldLastvisitDateRange`, `JFormFieldLimitbox`, `JFormFieldList`, `JFormFieldMedia`, `JFormFieldMenu`, `JFormFieldMenuitem`, `JFormFieldMeter`, `JFormFieldModulelayout`, `JFormFieldModuleOrder`, `JFormFieldModulePosition`, `JFormFieldModuletag`, `JFormFieldNote`, `JFormFieldNumber`, `JFormFieldOrdering`, `JFormFieldPassword`, `JFormFieldPlugins`, `JFormFieldPlugin_Status`, `JFormFieldPredefinedList`, `JFormFieldRadio`, `JFormFieldRange`, `JFormFieldRedirect_Status`, `JFormFieldRegistrationDateRange`, `JFormFieldRules`, `JFormFieldSessionHandler`, `JFormFieldSpacer`, `JFormFieldSQL`, `JFormFieldStatus`, `JFormFieldSubform`, `JFormFieldTag`, `JFormFieldTel`, `JFormFieldTemplatestyle`, `JFormFieldText`, `JFormFieldTextarea`, `JFormFieldTimezone`, `JFormFieldUrl`, `JFormFieldUserActive`, `JFormFieldUserGroupList`, `JFormFieldUserState`, `JFormFieldUser`

**Form Rules (14):** All available in J3-J6

- `JFormRuleBoolean`, `JFormRuleCalendar`, `JFormRuleCaptcha`, `JFormRuleColor`, `JFormRuleEmail`, `JFormRuleEquals`, `JFormRuleNotequals`, `JFormRuleNumber`, `JFormRuleOptions`, `JFormRulePassword`, `JFormRuleRules`, `JFormRuleTel`, `JFormRuleUrl`, `JFormRuleUsername`

### User & Session Classes (3)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JUser` | `\Joomla\CMS\User\User` | ✓ | ✓ | ✓ | ✓ |
| `JUserHelper` | `\Joomla\CMS\User\UserHelper` | ✓ | ✓ | ✓ | ✓ |
| `JSession` | `\Joomla\CMS\Session\Session` | ✓ | ✓ | ✓ | ✓ |

### Input & Filter Classes (7)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JInput` | `\Joomla\CMS\Input\Input` | ✓ | ✓ | ✓ | ✓ |
| `JInputCli` | `\Joomla\CMS\Input\Cli` | ✓ | ✓ | ✓ | ✓ |
| `JInputCookie` | `\Joomla\CMS\Input\Cookie` | ✓ | ✓ | ✓ | ✓ |
| `JInputFiles` | `\Joomla\CMS\Input\Files` | ✓ | ✓ | ✓ | ✓ |
| `JInputJSON` | `\Joomla\CMS\Input\Json` | ✓ | ✓ | ✓ | ✓ |
| `JFilterInput` | `\Joomla\CMS\Filter\InputFilter` | ✓ | ✓ | ✓ | ✓ |
| `JFilterOutput` | `\Joomla\CMS\Filter\OutputFilter` | ✓ | ✓ | ✓ | ✓ |

### Helper Classes (10)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JModuleHelper` | `\Joomla\CMS\Helper\ModuleHelper` | ✓ | ✓ | ✓ | ✓ |
| `JComponentHelper` | `\Joomla\CMS\Component\ComponentHelper` | ✓ | ✓ | ✓ | ✓ |
| `JPluginHelper` | `\Joomla\CMS\Plugin\PluginHelper` | ✓ | ✓ | ✓ | ✓ |
| `JLayoutHelper` | `\Joomla\CMS\Layout\LayoutHelper` | ✓ | ✓ | ✓ | ✓ |
| `JHelperContent` | `\Joomla\CMS\Helper\ContentHelper` | ✓ | ✓ | ✓ | ✓ |
| `JLibraryHelper` | `\Joomla\CMS\Helper\LibraryHelper` | ✓ | ✓ | ✓ | ✓ |
| `JHelperTags` | `\Joomla\CMS\Helper\TagsHelper` | ✓ | ✓ | ✓ | ✓ |
| `JHelperUsergroups` | `\Joomla\CMS\Helper\UserGroupsHelper` | ✓ | ✓ | ✓ | ✓ |
| `JHelperRoute` | `\Joomla\CMS\Helper\RouteHelper` | ✓ | ✓ | ✓ | ✓ |
| `JAuthenticationHelper` | `\Joomla\CMS\Helper\AuthenticationHelper` | ✓ | ✓ | ✓ | ✓ |

### Document Classes (20)

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `JDocument` | `\Joomla\CMS\Document\Document` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentHtml` | `\Joomla\CMS\Document\HtmlDocument` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentError` | `\Joomla\CMS\Document\ErrorDocument` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentFeed` | `\Joomla\CMS\Document\FeedDocument` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentJson` | `\Joomla\CMS\Document\JsonDocument` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentRaw` | `\Joomla\CMS\Document\RawDocument` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentXml` | `\Joomla\CMS\Document\XmlDocument` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentOpensearch` | `\Joomla\CMS\Document\OpensearchDocument` | ✓ | ✓ | ✓ | ✓ |
| `JDocumentRenderer` | `\Joomla\CMS\Document\DocumentRenderer` | ✓ | ✓ | ✓ | ✓ |
| `JFeedEnclosure` | `\Joomla\CMS\Document\Feed\FeedEnclosure` | ✓ | ✓ | ✓ | ✓ |
| `JFeedImage` | `\Joomla\CMS\Document\Feed\FeedImage` | ✓ | ✓ | ✓ | ✓ |
| `JFeedItem` | `\Joomla\CMS\Document\Feed\FeedItem` | ✓ | ✓ | ✓ | ✓ |

### HTML Helper Classes (30+)

All available in J3-J6: `JHtml`, `JHtmlAccess`, `JHtmlActionsDropdown`, `JHtmlAdminLanguage`, `JHtmlBehavior`, `JHtmlBootstrap`, `JHtmlCategory`, `JHtmlContent`, `JHtmlContentlanguage`, `JHtmlDate`, `JHtmlDebug`, `JHtmlDraggablelist`, `JHtmlDropdown`, `JHtmlEmail`, `JHtmlForm`, `JHtmlFormbehavior`, `JHtmlGrid`, `JHtmlIcons`, `JHtmlJGrid`, `JHtmlJquery`, `JHtmlLinks`, `JHtmlList`, `JHtmlMenu`, `JHtmlNumber`, `JHtmlSearchtools`, `JHtmlSelect`, `JHtmlSidebar`, `JHtmlSortableList`, `JHtmlString`, `JHtmlTag`, `JHtmlTel`, `JHtmlUser`

### Extension Classes (19) - J4+ Only

| Legacy Alias | Modern Namespace | J3 | J4 | J5 | J6 |
|--------------|------------------|----|----|----|----|
| `ActionLogPlugin` | `\Joomla\Component\Actionlogs\Administrator\Plugin\ActionLogPlugin` | ✗ | ✓ | ✓ | ✓ |
| `FieldsPlugin` | `\Joomla\Component\Fields\Administrator\Plugin\FieldsPlugin` | ✗ | ✓ | ✓ | ✓ |
| `FieldsListPlugin` | `\Joomla\Component\Fields\Administrator\Plugin\FieldsListPlugin` | ✗ | ✓ | ✓ | ✓ |
| `PrivacyPlugin` | `\Joomla\Component\Privacy\Administrator\Plugin\PrivacyPlugin` | ✗ | ✓ | ✓ | ✓ |
| `PrivacyExportDomain` | `\Joomla\Component\Privacy\Administrator\Export\Domain` | ✗ | ✓ | ✓ | ✓ |
| `PrivacyExportField` | `\Joomla\Component\Privacy\Administrator\Export\Field` | ✗ | ✓ | ✓ | ✓ |
| `PrivacyExportItem` | `\Joomla\Component\Privacy\Administrator\Export\Item` | ✗ | ✓ | ✓ | ✓ |
| `PrivacyRemovalStatus` | `\Joomla\Component\Privacy\Administrator\Removal\Status` | ✗ | ✓ | ✓ | ✓ |
| `PrivacyTableRequest` | `\Joomla\Component\Privacy\Administrator\Table\RequestTable` | ✗ | ✓ | ✓ | ✓ |
| `ContentHelperRoute` | `\Joomla\Component\Content\Site\Helper\RouteHelper` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexer` | `\Joomla\Component\Finder\Administrator\Indexer\Indexer` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexerAdapter` | `\Joomla\Component\Finder\Administrator\Indexer\Adapter` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexerHelper` | `\Joomla\Component\Finder\Administrator\Indexer\Helper` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexerParser` | `\Joomla\Component\Finder\Administrator\Indexer\Parser` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexerQuery` | `\Joomla\Component\Finder\Administrator\Indexer\Query` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexerResult` | `\Joomla\Component\Finder\Administrator\Indexer\Result` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexerTaxonomy` | `\Joomla\Component\Finder\Administrator\Indexer\Taxonomy` | ✗ | ✓ | ✓ | ✓ |
| `FinderIndexerToken` | `\Joomla\Component\Finder\Administrator\Indexer\Token` | ✗ | ✓ | ✓ | ✓ |
| `TagsTableTag` | `\Joomla\Component\Tags\Administrator\Table\TagTable` | ✗ | ✓ | ✓ | ✓ |

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## License

The MIT License (MIT).

## J6 Backward Compatibility Classes (The Great Namespace Shuffle)

Because apparently moving perfectly functional classes between folders across major versions is a great use of everyone's time, the following `\Joomla\CMS\*` classes are deprecated and will be removed in Joomla 6. The classes themselves? Largely unchanged. The namespace? Different. Your codebase? Broken. Your weekend? Ruined.

Use the framework alternatives (which are essentially the same classes, just in a different folder):

### Filesystem Classes (deprecated 4.4, removed in 6.0)

*Because `\Joomla\CMS\Filesystem` was clearly too intuitive. Let's move everything to `\Joomla\Filesystem` instead. Same functionality, different path. Progress!*

| CMS Class | Framework Alternative |
|-----------|----------------------|
| `\Joomla\CMS\Filesystem\File` | `\Joomla\Filesystem\File` |
| `\Joomla\CMS\Filesystem\Folder` | `\Joomla\Filesystem\Folder` |
| `\Joomla\CMS\Filesystem\Path` | `\Joomla\Filesystem\Path` |
| `\Joomla\CMS\Filesystem\Stream` | `\Joomla\Filesystem\Stream` |
| `\Joomla\CMS\Filesystem\Patcher` | `\Joomla\Filesystem\Patcher` |
| `\Joomla\CMS\Filesystem\FilesystemHelper` | `\Joomla\Filesystem\Helper` |
| `\Joomla\CMS\Filesystem\Streams\StreamString` | `\Joomla\Filesystem\Stream\StringWrapper` |
| `\Joomla\CMS\Filesystem\Support\StringController` | `\Joomla\Filesystem\Support\StringController` |

### Application Classes (deprecated 4.0-4.3, removed in 6.0)

*CLI applications worked fine in `\Joomla\CMS\Application`, but why keep things stable when you can deprecate them across multiple versions and force everyone to migrate to a completely different package?*

| CMS Class | Framework Alternative |
|-----------|----------------------|
| `\Joomla\CMS\Application\BaseApplication` | `\Joomla\Application\AbstractApplication` |
| `\Joomla\CMS\Application\CliApplication` | `joomla/console` package |
| `\Joomla\CMS\Application\CLI\CliInput` | `joomla/console` package |
| `\Joomla\CMS\Application\CLI\CliOutput` | `joomla/console` package |
| `\Joomla\CMS\Application\CLI\ColorStyle` | `joomla/console` package |
| `\Joomla\CMS\Application\CLI\Output\Stdout` | `joomla/console` package |
| `\Joomla\CMS\Application\CLI\Output\Xml` | `joomla/console` package |

### Input Classes (deprecated 4.3, removed in 6.0)

*Input handling classes that have been working since Joomla 1.7? Time to move them! Not because they need improvement, but because... reasons.*

| CMS Class | Framework Alternative |
|-----------|----------------------|
| `\Joomla\CMS\Input\Input` | `\Joomla\Input\Input` |
| `\Joomla\CMS\Input\Cookie` | `\Joomla\Input\Cookie` |
| `\Joomla\CMS\Input\Files` | `\Joomla\Input\Files` |
| `\Joomla\CMS\Input\Json` | `\Joomla\Input\Json` |

## Notes

- ✓ = Available in this version
- ✗ = Not available in this version
- All aliases marked as available are registered via `JLoader::registerAlias()`
- Database classes are only available as aliases in J4+
- Extension-specific classes are only available in J4+
- Some classes were removed or deprecated between versions
- **J6 BC classes**: Classes in `\Joomla\CMS\*` namespace that are deprecated should be replaced with their `\Joomla\*` framework equivalents before J6. Yes, you'll need to update thousands of lines of code to change folder paths again. No, the classes themselves haven't meaningfully changed. Welcome to modern framework development.
- **Pro tip**: This Rector rule exists because manually tracking these namespace gymnastics across 473 classes would drive anyone to madness. You're welcome.
