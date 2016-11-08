<?php
/**
 * @file
 *
 * @author Jon Kamke <jon@ten7.com>
 */

/**
 * Class ToolkitTopics
 *
 * Migrate the Taxonomy terms for Toolkit Topics.
 */
class ToolkitTopics extends DrupalTerm6Migration {

  /**
   * ToolkitTopics constructor.
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->description = t('Migrate the Toolkit Topics vocabulary.');

  }
}