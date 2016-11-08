<?php
/**
 * @file
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Class ToolkitDownload
 *
 * Migration for the Toolkit Download content type.
 */
class ToolkitDownload extends ToolkitNode {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Import the Toolkit Download content type.');

    //Map the File Download field
    $this->addFieldMapping('field_td_file_download', 'field_file_download')
      ->sourceMigration('ToolkitFiles');
    $this->addFieldMapping('field_td_file_download:file_class')
      ->defaultValue('MigrateFileFid');

    //Map Resource Type field
    $this->addFieldMapping('field_td_resource_type', 'field_resource_type');

    //Map Toolkit Topics taxonomy
    //The topic_name source is prepared in prepareRow()
    $this->addFieldMapping('field_td_toolkit_topics', 'topic_name');

    //Map Related Toolkit term reference field
    //The source is setup in the prepareRow() function
    $this->addFieldMapping('field_ct_related_toolkit', 'rel_toolkit');
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

    //Get the Title from field_rel_toolkit
    $rel_nid = $row->field_rel_toolkit[0];
    $node_title_query = $this->getConnection()->select('node', 'n')
      ->fields('n', array('title'))
      ->condition('nid', $rel_nid, '=')
      ->execute()
      ->fetchAll();

    $row->rel_toolkit = $node_title_query[0]->title;

    return TRUE;
  }

}