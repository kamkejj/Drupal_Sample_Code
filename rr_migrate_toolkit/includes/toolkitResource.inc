<?php
/**
 * @file
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Class ToolkitResource
 *
 * Migration for the Toolkit Download content type.
 */
class ToolkitResource extends ToolkitNode {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import the Toolkit Resource content type.');

    //Map field_resource_type to field_tr_resource_type
    $this->addFieldMapping('field_tr_resource_type', 'field_resource_type');

    //Map file field_image_thumbnail to field_trt_thumbnail
    $this->addFieldMapping('field_trt_thumbnail', 'field_image_thumbnail')
      ->sourceMigration('ToolkitFiles');
    $this->addFieldMapping('field_trt_thumbnail:file_class')
      ->defaultValue('MigrateFileFid');

    //Map file field_file to field_tr_file_attachment
    $this->addFieldMapping('field_tr_file_attachment', 'field_file')
      ->sourceMigration('ToolkitFiles');
    $this->addFieldMapping('field_tr_file_attachment:file_class')
      ->defaultValue('MigrateFileFid');

    //Map Toolkit Topics taxonomy
    //The topic_name source is prepared in prepareRow()
    $this->addFieldMapping('field_tr_toolkit_topics', 'topic_name');

    //Map Matrix table
    //@see ToolkitMatrixField

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

    //Get the Toolkit Topics term name from the database for the new
    //field_td_toolkit_topics field.
    $nid = $row->nid;
    $term = $this->getConnection()->select('term_node', 'tn')
      ->fields('tn', array('tid', 'nid'))
      ->condition('nid', $nid, '=')
      ->execute()
      ->fetchAll();

    $tid = $term[0]->tid;
    $query = $this->getConnection()->select('term_data', 'td')
      ->fields('td', array('name'))
      ->condition('tid', $tid, '=')
      ->execute()
      ->fetchAll();

    $row->topic_name = $query[0]->name;

    return TRUE;
  }

}