<?php
/**
 * @file
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Class ToolkitNode
 *
 * Base class to use for the migrations.
 */
class ToolkitNode extends DrupalNode6Migration {

  /**
   * Constructor
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
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
   * Implements DrupalMigration::query().
   *
   * Allows us to override the quest as needed.
   *
   * @return QueryConditionInterface|SelectQueryInterface
   */
  protected function query() {
    $query = parent::query();

    return $query;
  }

  /**
   * Get a database connection to the source database.
   *
   * @param string $connection - the database name in settings.php
   * @return \DatabaseConnection
   */
  public function getConnection($connection = 'swmcb') {
    return Database::getConnection('default', $connection);
  }

}