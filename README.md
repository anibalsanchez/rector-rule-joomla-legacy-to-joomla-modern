# Rector Rule: Joomla Legacy Classes → Joomla Modern Namespaces

A [Rector](https://getrector.com/) rule that converts legacy Joomla `J`-class aliases (`JFactory`, `JText`, `JModelLegacy`, …) to their modern namespaced equivalents (`\Joomla\CMS\Factory`, `\Joomla\CMS\Language\Text`, …), so one codebase can run across multiple Joomla versions.

## Why?

Legacy `J`-class aliases are registered via `JLoader::registerAlias()` and are deprecated (or already removed) in newer Joomla versions. Rewriting them by hand across hundreds of classes is error-prone. This rule automates the conversion:

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

The rule handles:

- Static calls (`JFactory::getApplication()`)
- Class constant fetches (`JText::__SCRIPT_NAME`)
- Class inheritance (`extends JModelLegacy`, `implements JTableInterface`)

## Requirements

- PHP 8.2+ (Rector 2.x requirement)
- Rector 2.x in the project you want to modernize

## Installation

Once the package is registered on Packagist:

```bash
composer require --dev joomla-legacy-to-modern/rector-rule
```

Until then, require the repository directly in your project's `composer.json`:

```json
{
    "repositories": [
        {
            "type": "vcs",
            "url": "https://github.com/<your-org>/rector-rule-joomla-legacy-to-joomla-modern"
        }
    ],
    "require-dev": {
        "joomla-legacy-to-modern/rector-rule": "dev-main"
    }
}
```

then run `composer update joomla-legacy-to-modern/rector-rule`.

### Register the rule

In your project's `rector.php`:

```php
<?php

use Rector\Config\RectorConfig;
use Utils\Rector\Rector\LegacyCallToJClassToJModernRector;

return RectorConfig::configure()
    ->withRules([
        LegacyCallToJClassToJModernRector::class,
    ]);
```

### Development (this repository)

```bash
composer install
composer test   # runs the fixture-based PHPUnit suite
```

## Usage

```bash
# Preview changes first (recommended)
vendor/bin/rector process src/ --dry-run

# Apply changes
vendor/bin/rector process src/
```

## Coverage

**473 class mappings**, grouped by area:

| Area | Examples |
|------|----------|
| Core framework | `JFactory`, `JText`, `JDate`, `JUri`, `JVersion`, `JRegistry` |
| Application | `JApplicationSite`, `JApplicationAdministrator`, `JCli`, `JWeb` |
| MVC | `JModelLegacy`, `JModelList`, `JViewLegacy`, `JControllerLegacy`, … |
| Database | `JDatabaseDriver`, `JDatabaseQuery`, drivers (Mysqli, Pdo, Pgsql, …) |
| Tables | `JTable`, `JTableContent`, `JTableUser`, … |
| Forms | 4 base classes, 70+ field classes, 14 rule classes |
| User & session | `JUser`, `JUserHelper`, `JSession` |
| Input & filter | `JInput`, `JInputCli`, `JFilterInput`, `JFilterOutput` |
| Helpers | `JModuleHelper`, `JComponentHelper`, `JPluginHelper`, `JLayoutHelper`, … |
| Documents | `JDocument`, `JDocumentHtml`, renderers, feed classes |
| HTML helpers | `JHtml` and 30+ helper classes |
| Filesystem | `JFile`, `JFolder`, `JPath`, `JStream` |
| Everything else | Cache, HTTP, Mail, Language, Access, Router, Categories, Pagination, Installer, Updater, Toolbar, Editor, Captcha, Authentication, Profiler, Image, Feed, FTP, LDAP, Crypt |
| Extension classes (J4+) | `ActionLogPlugin`, `FieldsPlugin`, `PrivacyPlugin`, `FinderIndexer`, `TagsTableTag`, … |

The full mapping lives in [`src/Rector/LegacyCallToJClassToJModernRector.php`](src/Rector/LegacyCallToJClassToJModernRector.php).

## Joomla Version Compatibility

Legend: ✓ available as alias in that version · ✗ not available

Most classes are registered as aliases in Joomla 3 through 6. Key differences:

- **Database classes** (`JDatabaseDriver`, `JDatabaseQuery`, drivers) are aliased only in **Joomla 4+**. If you also target Joomla 3, these must be handled case-by-case — the rule deliberately excludes them (see the commented block in the rule class), because rewriting them unconditionally breaks Joomla 3.
- **Extension-specific classes** (`ActionLogPlugin`, `FieldsPlugin`, `FinderIndexer`, …) are aliased only in **Joomla 4+**.
- Some J3-only classes were removed in J4 (e.g. `JRegistryFormat`, `JLanguageStemmer`).

### The Joomla 6 namespace shuffle

Several `\Joomla\CMS\*` classes are deprecated (Joomla 4.3–4.4) and **removed in Joomla 6** in favor of standalone framework packages:

| CMS class (deprecated) | Framework alternative |
|------------------------|----------------------|
| `\Joomla\CMS\Filesystem\File` | `\Joomla\Filesystem\File` |
| `\Joomla\CMS\Filesystem\Folder` | `\Joomla\Filesystem\Folder` |
| `\Joomla\CMS\Filesystem\Path` | `\Joomla\Filesystem\Path` |
| `\Joomla\CMS\Filesystem\Stream` | `\Joomla\Filesystem\Stream` |
| `\Joomla\CMS\Filesystem\Patcher` | `\Joomla\Filesystem\Patcher` |
| `\Joomla\CMS\Filesystem\FilesystemHelper` | `\Joomla\Filesystem\Helper` |
| `\Joomla\CMS\Input\Input` | `\Joomla\Input\Input` |
| `\Joomla\CMS\Input\Cookie` | `\Joomla\Input\Cookie` |
| `\Joomla\CMS\Input\Files` | `\Joomla\Input\Files` |
| `\Joomla\CMS\Input\Json` | `\Joomla\Input\Json` |
| `\Joomla\CMS\Application\BaseApplication` | `\Joomla\Application\AbstractApplication` |
| `\Joomla\CMS\Application\CliApplication` | `joomla/console` package |

⚠️ **Caveat when supporting Joomla 3–5:** the `\Joomla\Filesystem\*` and `\Joomla\Input\*` framework classes are not present in Joomla 3–5 — there the CMS equivalents are the correct choice, and the J6 equivalents require the framework packages / compatibility plugin. This rule therefore maps to the `\Joomla\CMS\*` classes (valid from J3 to J5); the J6 framework-package migration is a separate follow-up step. The `compat6-craziness/` directory and the per-version classmaps document these differences.

## Reference Classmaps

The `src/Rector/` directory also ships the raw alias registrations extracted from each Joomla version's `JLoader::registerAlias()` sources, useful for verifying availability per version:

- `classmap-j3.php`, `classmap-j4.php`, `classmap-j5.php`, `classmap-j6.php` — core CMS aliases
- `extensions.classmap-j4.php`, `extensions.classmap-j5.php`, `extensions.classmap-j6.php` — extension-component aliases
- `compat6-craziness/` — the CMS classes deprecated for removal in Joomla 6

## Excluded on Purpose

Some aliases are **not** converted automatically because the target class does not exist in all supported Joomla versions:

- Database driver/query classes and their exceptions (J4+ only — rewriting breaks Joomla 3)
- `ContentHelperRoute` → `\Joomla\Component\Content\Site\Helper\RouteHelper` (J4+ only; in J3 the class lives elsewhere)

These are listed (commented out) at the top of the rule's mapping and should be handled case-by-case.

## Contributing

1. Fork the repository
2. Create your feature branch: `git checkout -b feature/amazing-feature`
3. Add a fixture under `tests/Rector/LegacyCallToJClassToJModernRector/Fixture/` (`*.php.inc` files showing before → after)
4. Run the test suite: `vendor/bin/phpunit` (from your Rector dev environment)
5. Commit and push, then open a Pull Request

## License

The MIT License (MIT).