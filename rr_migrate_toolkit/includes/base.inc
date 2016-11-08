<?php
/**
 * @file
 *
 * Toolkit base class for the migrations.
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Base class for Toolkit migrations that extends the Migration class.
 */
abstract class ToolkitMigration extends Migration {
  // A Migration constructor takes an array of arguments as its first parameter.
  // The arguments must be passed through to the parent constructor.
  public function __construct($arguments) {
    parent::__construct($arguments);

    // With migrate_ui enabled, migration pages will indicate people involved in
    // the particular migration, with their role and contact info. We default the
    // list in the shared class; it can be overridden for specific migrations.
    $this->team = array(
      new MigrateTeamMember('Denise Beyer', 'denise@gortonstudios.com',
        t('Product Owner')),
      new MigrateTeamMember('Jon Kamke', 'jon@ten7.com',
        t('Implementor')),
    );
  }

  /**
   * @param string $connection - the database name in settings.php
   * @return \DatabaseConnection
   */
  public function getConnection($connection = 'swmcb') {
    return Database::getConnection('default', $connection);
  }
}