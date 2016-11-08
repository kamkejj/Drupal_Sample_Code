<?php
/**
 * @file
 *
 * Migrate the Toolkit files from D6 to D7.
 *
 * @author Jon Kamke <jon@ten7.com>
 */


/**
 * Class ToolkitFilesMigration
 */
class ToolkitFilesMigration extends DrupalFile6Migration {

  /**
   * ToolkitFilesMigration constructor.
   *
   * @param array $arguments
   */
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->description = t('Import Toolkit files from the swmcb.com D6 site.');

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
   * @param string $connection - the database name in settings.php
   * @return \DatabaseConnection
   */
  public function getConnection($connection = 'swmcb') {
    return Database::getConnection('default', $connection);
  }
}