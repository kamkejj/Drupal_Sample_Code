<?php
/**
 * @file
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Implements hook_migrate_api().
 */
function rr_migrate_toolkit_migrate_api() {
  global $conf;
  /**
   * See settings.php to configure the source files directory.
   */
  $sourceDir = $conf['filesSourceDir'];

  return array(
    'api' => 2,
    'groups' => array(
      'toolkits' => array(
        'title' => t('Toolkits'),
      ),
    ),
    'migrations' => array(
      'ToolkitFiles' => array(
        'source_connection' => 'swmcb',
        'source_version' => 6,
        'class_name' => 'ToolkitFilesMigration',
        'group' => 'toolkits',
        'default_uid' => 1,
        'source_dir' => $sourceDir,
        'destination_dir' => 'public://legacy/swmcb',
      ),
      'ToolkitTopics' => array(
        'source_connection' => 'swmcb',
        'source_version' => 6,
        'class_name' => 'ToolkitTopics',
        'group' => 'toolkits',
        'source_vocabulary' => '2',  // "Toolkit Topics" vocabulary
        'destination_vocabulary' => 'toolkit_topics',
      ),
      'ToolkitCampaign' => array(
        'source_connection' => 'swmcb',
        'source_version' => 6,
        'class_name' => 'ToolkitCampaign',
        'group' => 'toolkits',
        'default_uid' => 1,
        'source_type' => 'toolkit',
        'destination_type' => 'campaign_toolkit',
        'dependencies' => array('ToolkitFiles'),
      ),
      'ToolkitDownload' => array(
        'source_connection' => 'swmcb',
        'source_version' => 6,
        'class_name' => 'ToolkitDownload',
        'group' => 'toolkits',
        'default_uid' => 1,
        'source_type' => 'toolkit_download',
        'destination_type' => 'toolkit_download',
        'dependencies' => array(
          'ToolkitFiles',
          'ToolkitCampaign',
          'ToolkitTopics'
        ),
      ),
      'ToolkitResource' => array(
        'source_connection' => 'swmcb',
        'source_version' => 6,
        'class_name' => 'ToolkitResource',
        'group' => 'toolkits',
        'default_uid' => 1,
        'source_type' => 'toolkit_resource',
        'destination_type' => 'toolkit_resource',
        'dependencies' => array('ToolkitFiles'),
      ),
      'ToolkitMatrixField' => array(
        'source_connection' => 'swmcb',
        'source_version' => 6,
        'class_name' => 'ToolkitMatrixField',
        'group' => 'toolkits',
        'default_uid' => 1,
        'source_type' => 'toolkit_resource',
        'destination_type' => 'toolkit_resource',
        'dependencies' => array('ToolkitResource'),
      ),
    ),
  );
}