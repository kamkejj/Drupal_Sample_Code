<?php
/**
 * @file
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Class ToolkitCampaign
 *
 * Migrate from Toolkit Campaign content type to Toolkit Campaign taxonomy.
 */
class ToolkitCampaign extends ToolkitNode {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate from Toolkit Campaign content type to Toolkit Campaign taxonomy.');

    //Migrate from Campaign Toolkit (toolkit) content type to Taxonomy Campaign Toolkit (campaign_toolkit)
    $language = LANGUAGE_NONE;
    $text_format = 'full_html';
    $term_options = MigrateDestinationTerm::options($language, $text_format);
    $this->destination = new MigrateDestinationTerm('campaign_toolkit', $term_options);

    //Map node Title to Term Name
    $this->addFieldMapping('name', 'title');

    //Map Do not show up on Toolkits page
    $this->addFieldMapping('field_ct_enable_disable	')->defaultValue(0);

    //Map field_teaser to field_ct_teaser
    $this->addFieldMapping('field_ct_teaser', 'field_teaser');

    //Map field_resource to field_ct_resource_name
    $this->addFieldMapping('field_ct_resource_name', 'field_resource');

    //Map body to description
    $this->addFieldMapping('description', 'body');

    //Map field_image_thumbnail to field_ct_image_thumbnail
    $this->addFieldMapping('field_ct_image_thumbnail', 'field_image_thumbnail')
      ->sourceMigration('ToolkitFiles');
    $this->addFieldMapping('field_ct_image_thumbnail:file_class')
      ->defaultValue('MigrateFileFid');
  }

}