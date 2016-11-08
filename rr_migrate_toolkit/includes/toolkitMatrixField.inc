<?php
/**
 * @file
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Class ToolkitMatrixField
 *
 * Migration for the Matrix Field field.
 */
class ToolkitMatrixField extends ToolkitNode {

  private static $delta = -1;

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = 'Migrate the data for the Matrix Field module.';

    $queryMatrix = $this->getConnection()
      ->select('node_field_matrix_data', 'md')
      ->fields('md', array('nid', 'row', 'col', 'value'))
      ->condition('value', '', '!=')
      ->orderBy('md.nid');

    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'length' => 10,
          'unsigned' => TRUE,
          'not null' => FALSE,
          'description' => t('Source ID'),
          'alias' => 'md',
        ),
      ),
      MigrateDestinationTable::getKeySchema()
    );

    $this->source = new MigrateSourceSQL($queryMatrix);

    $this->destination = new MigrateDestinationTable('field_data_field_tr_resource_table');

    $this->addFieldMapping('entity_id', 'nid')
      ->sourceMigration('ToolkitResource');
    $this->addFieldMapping('delta', 'delta');
    $this->addFieldMapping('field_tr_resource_table_row', 'sourceRow');
    $this->addFieldMapping('field_tr_resource_table_col', 'sourceCol');
    $this->addFieldMapping('field_tr_resource_table_value', 'value');
    $this->addFieldMapping('entity_type')->defaultValue('node');
    $this->addFieldMapping('bundle')->defaultValue('bundle');
  }

  /**
   * Prepare Row
   *
   * View and change the data from the source before the field mappings in
   * the constructor.
   *
   * @param $row - data from the source
   * @return bool
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    //seems to simply be an incremented value starting at 0
    static::$delta += 1;
    $row->delta = static::$delta;

    //Rows and Cols in the D7 version start with 1 not 0
    $sourceCol = $row->col;
    $row->sourceCol = (int) $sourceCol + 1;

    $sourceRow = $row->row;
    $row->sourceRow = (int) $sourceRow + 1;


    return TRUE;

  }
}