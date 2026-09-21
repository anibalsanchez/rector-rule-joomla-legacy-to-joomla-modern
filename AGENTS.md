# AGENTS.md — Guidance for AI Coding Agents

## Project Overview

A [Rector](https://getrector.com/) rule that converts legacy Joomla `J`-class aliases
(`JFactory`, `JText`, `JModelLegacy`, …) to modern namespaced classes
(`\Joomla\CMS\Factory`, …), enabling one codebase to run on Joomla 3–6.

## Project Structure

```text
composer.json                  # package + test toolchain (php ^8.2, rector/rector ^2.0, phpunit ^11)
phpunit.xml                    # test suite over tests/Rector
src/Rector/
  LegacyCallToJClassToJModernRector.php   # the rule; main mapping is LEGACY_TO_MODERN_MAP
  classmap-j3|j4|j5|j6.php                # reference alias registrations per Joomla version
  extensions.classmap-j4|j5|j6.php        # extension-component aliases (J4+)
  compat6-craziness/                      # CMS classes removed in Joomla 6
tests/Rector/LegacyCallToJClassToJModernRector/
  Fixture/*.php.inc                       # before → after fixtures
  config/configured_rule.php
  LegacyCallToJClassToJModernRectorTest.php
```

The rule class lives in namespace `Utils\Rector\Rector` (PSR-4 mapped in composer.json).

## Commands

```bash
composer install     # set up dependencies
composer test        # run the fixture-based PHPUnit suite
```

## Deliberate Exclusions — Do Not "Fix" These

Some mappings are intentionally **commented out** at the top of `LEGACY_TO_MODERN_MAP`
because the target class does not exist in all supported Joomla versions. Rewriting them
unconditionally **breaks Joomla 3**:

- Database classes (`JDatabaseDriver`, `JDatabaseQuery`, drivers, exceptions) — J4+ only
- `ContentHelperRoute` → `\Joomla\Component\Content\Site\Helper\RouteHelper` — J4+ only

Never add a mapping for a class that is not aliased on all of Joomla 3–6. Verify
availability against `src/Rector/classmap-j*.php` before adding mappings.

## Adding or Changing a Mapping

1. Add the entry to `LEGACY_TO_MODERN_MAP` in the rule class (sorted, `\\`-escaped namespaces).
2. Add a fixture: `tests/Rector/.../Fixture/<name>.php.inc` with the "before" PHP and the
   expected "after" PHP in the same file (Rector fixture format).
3. Run `composer test` — the fixture test auto-discovers all files in `Fixture/`.
4. Keep fixtures minimal: one mapping concern per fixture where practical.

## Code Standards

- `declare(strict_types=1);` in every PHP file
- `final` classes; typed properties and return types (including `: ?Type`, `: void`)
- Guard clauses / early returns; avoid `else`; keep methods short and flat
- Specific exception types, not bare `Exception`
- Tests use PHPUnit built-in mocks (`createMock`)

## Scope

PHP only. The rule maps class names; it does not rewrite method bodies or author Joomla
application code, so Joomla app-level concerns (SQL building, input handling, templates,
frontend code) are out of scope here.
