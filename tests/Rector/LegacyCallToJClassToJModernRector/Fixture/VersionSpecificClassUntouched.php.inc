<?php

namespace Rector\Tests\TypeDeclaration\Rector\LegacyCallToJClassToJModernRector\Fixture;

class VersionSpecificClassUntouched
{
    public function run()
    {
        $adapter = new \JAdapter();
        $adapterInstance = new \JAdapterInstance();
        $filter = \JImageFilterBrightness::class;
        $wincache = \JCacheStorageWincache::class;
        $changeItem = \JSchemaChangeitemSqlsrv::class;
        $ldap = \JClientLdap::class;
        $ldap2 = \JLDAP::class;
    }
}

?>
-----
<?php

namespace Rector\Tests\TypeDeclaration\Rector\LegacyCallToJClassToJModernRector\Fixture;

class VersionSpecificClassUntouched
{
    public function run()
    {
        $adapter = new \JAdapter();
        $adapterInstance = new \JAdapterInstance();
        $filter = \JImageFilterBrightness::class;
        $wincache = \JCacheStorageWincache::class;
        $changeItem = \JSchemaChangeitemSqlsrv::class;
        $ldap = \JClientLdap::class;
        $ldap2 = \JLDAP::class;
    }
}

?>