<?php

/**
 * @file
 *
 * Contains Drupal\bf_homepage\Form\HomepageForm.
 *
 * @author Jon Kamke <jon@kamke.org>
 */

namespace Drupal\bf_homepage\Form;

use Drupal\Core\Form\ConfigFormBase;
use Drupal\Core\Form\FormStateInterface;
use Drupal\file\Entity\File;
use Drupal\file\FileUsage\DatabaseFileUsageBackend;
use Symfony\Component\DependencyInjection\ContainerInterface;
use \Drupal\Core\Config\ConfigFactoryInterface;

/**
 * Class HomepageForm.
 *
 * @package Drupal\bf_homepage\Form
 */
class HomepageForm extends ConfigFormBase {

  /**
   * Drupal Service file.usage.
   *
   * @var \Drupal\file\FileUsage\DatabaseFileUsageBackend
   */
  protected $fileUsage;

  /**
   * HomepageForm constructor.
   *
   * @param ConfigFactoryInterface $config_factory
   * @param DatabaseFileUsageBackend $fileUsage
   */
  public function __construct(ConfigFactoryInterface $config_factory, DatabaseFileUsageBackend $fileUsage) {
    parent::__construct($config_factory);

    $this->fileUsage = $fileUsage;
  }

  /**
   * {@inheritdoc}
   */
  protected function getEditableConfigNames() {
    return [
      'bf_homepage.homepage',
    ];
  }

  /**
   * {@inheritdoc}
   */
  public function getFormId() {
    return 'homepage_form';
  }

  /**
   * {@inheritdoc}
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    $config = $this->config('bf_homepage.homepage');

    //Hero Image
    $form['main_block'] = [
      '#type' => 'fieldset',
      '#title' => t('Main Image Section'),
      '#weight' => 0,
    ];
    $form['main_block']['main_image'] = [
      '#title' => t('Main Hero Image'),
      '#type' => 'managed_file',
      '#description' => t('Allowed image types: gif png jpg jpeg. Should be 1000x460 pixels.'),
      '#default_value' => !empty($config->get('mainimage')) ? [$config->get('mainimage')] : [],
      '#upload_validators' => [
        'file_validate_extensions' => ['gif png jpg jpeg'],
        'file_validate_size' => [25600000],
      ],
      '#upload_location' => 'public://homepage/main',
      '#required' => TRUE,
    ];

    //Left content image and text
    $form['left_block'] = [
      '#type' => 'fieldset',
      '#title' => t('Left Image Section'),
      '#weight' => 0,
    ];
    $form['left_block']['left_image'] = [
      '#title' => t('Left Block Image'),
      '#type' => 'managed_file',
      '#description' => t('Allowed image types: gif png jpg jpeg. Should be 325px square.'),
      '#default_value' => !empty($config->get('leftimage')) ? [$config->get('leftimage')] : [],
      '#upload_validators' => [
        'file_validate_extensions' => ['gif png jpg jpeg'],
        'file_validate_size' => [25600000],
      ],
      '#upload_location' => 'public://homepage/left',
      '#required' => TRUE,
    ];
    $form['left_block']['left_block_title'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Left Block Title'),
      '#maxlength' => 64,
      '#size' => 64,
      '#default_value' => $config->get('left_block_title'),
      '#required' => TRUE,
    ];
    $form['left_block']['left_block_blurb'] = [
      '#type' => 'textarea',
      '#title' => $this->t('Left Block Text Blurb'),
      '#default_value' => $config->get('left_block_blurb'),
      '#required' => TRUE,
    ];
    $form['left_block']['left_block_link'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Left Block Link'),
      '#description' => t('Enter the URL for the link such as http://google.com'),
      '#maxlength' => 64,
      '#size' => 64,
      '#default_value' => $config->get('left_block_link'),
      '#required' => TRUE,
    ];

    //Center image and content
    $form['center_block'] = [
      '#type' => 'fieldset',
      '#title' => t('Center Image Section'),
      '#weight' => 0,
    ];
    $form['center_block']['center_image'] = [
      '#title' => t('Center Block Image'),
      '#type' => 'managed_file',
      '#description' => t('Allowed image types: gif png jpg jpeg. Should be 325px square.'),
      '#default_value' => !empty($config->get('centerimage')) ? [$config->get('centerimage')] : [],
      '#upload_validators' => [
        'file_validate_extensions' => ['gif png jpg jpeg'],
        'file_validate_size' => [25600000],
      ],
      '#upload_location' => 'public://homepage/center',
      '#required' => TRUE,
    ];
    $form['center_block']['center_block_title'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Center Block Title'),
      '#maxlength' => 64,
      '#size' => 64,
      '#default_value' => $config->get('center_block_title'),
      '#required' => TRUE,
    ];
    $form['center_block']['center_block_blurb'] = [
      '#type' => 'textarea',
      '#title' => $this->t('Center Block Text Blurb'),
      '#default_value' => $config->get('center_block_blurb'),
      '#required' => TRUE,
    ];
    $form['center_block']['center_block_link'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Center Block Link'),
      '#description' => t('Enter the URL for the link such as http://google.com'),
      '#maxlength' => 64,
      '#size' => 64,
      '#default_value' => $config->get('center_block_link'),
      '#required' => TRUE,
    ];

    //Right image and content
    $form['right_block'] = [
      '#type' => 'fieldset',
      '#title' => t('Right Image Section'),
      '#weight' => 0,
    ];
    $form['right_block']['right_image'] = [
      '#title' => t('Right Block Image'),
      '#type' => 'managed_file',
      '#description' => t('Allowed image types: gif png jpg jpeg. Should be 325px square.'),
      '#default_value' => !empty($config->get('rightimage')) ? [$config->get('rightimage')] : [],
      '#upload_validators' => [
        'file_validate_extensions' => ['gif png jpg jpeg'],
        'file_validate_size' => [25600000],
      ],
      '#upload_location' => 'public://homepage/right',
      '#required' => TRUE,
    ];
    $form['right_block']['right_block_title'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Right Block Title'),
      '#maxlength' => 64,
      '#size' => 64,
      '#default_value' => $config->get('right_block_title'),
      '#required' => TRUE,
    ];
    $form['right_block']['right_block_blurb'] = [
      '#type' => 'textarea',
      '#title' => $this->t('Right Block Text Blurb'),
      '#default_value' => $config->get('right_block_blurb'),
      '#required' => TRUE,
    ];
    $form['right_block']['right_block_link'] = [
      '#type' => 'textfield',
      '#title' => $this->t('Right Block Link'),
      '#description' => t('Enter the URL for the link such as http://google.com'),
      '#maxlength' => 64,
      '#size' => 64,
      '#default_value' => $config->get('right_block_link'),
      '#required' => TRUE,
    ];

    return parent::buildForm($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
    parent::validateForm($form, $form_state);

  }

  /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    parent::submitForm($form, $form_state);

    //Get file id (fid)
    $mainImageId = !empty($form_state->getValue('main_image')) ? $form_state->getValue('main_image') : array('');
    $leftImageId = !empty($form_state->getValue('left_image')) ? $form_state->getValue('left_image') : array('');
    $centerImageId = !empty($form_state->getValue('center_image')) ? $form_state->getValue('center_image') : array('');
    $rightImageId = !empty($form_state->getValue('right_image')) ? $form_state->getValue('right_image') : array('');

    //Permanently save uploaded managed_file
    $this->saveImagePermanently($mainImageId);
    $this->saveImagePermanently($leftImageId);
    $this->saveImagePermanently($centerImageId);
    $this->saveImagePermanently($rightImageId);

    //Save fields to the config table
    $this->config('bf_homepage.homepage')
      ->set('left_block_title', $form_state->getValue('left_block_title'))
      ->set('left_block_blurb', $form_state->getValue('left_block_blurb'))
      ->set('left_block_link', $form_state->getValue('left_block_link'))
      ->set('center_block_title', $form_state->getValue('center_block_title'))
      ->set('center_block_blurb', $form_state->getValue('center_block_blurb'))
      ->set('center_block_link', $form_state->getValue('center_block_link'))
      ->set('right_block_title', $form_state->getValue('right_block_title'))
      ->set('right_block_blurb', $form_state->getValue('right_block_blurb'))
      ->set('right_block_link', $form_state->getValue('right_block_link'))
      ->set('mainimage', $mainImageId[0])
      ->set('leftimage', $leftImageId[0])
      ->set('centerimage', $centerImageId[0])
      ->set('rightimage', $rightImageId[0])
      ->save();
  }

  /**
   * Permanently save uploaded files.
   *
   * @param array $imageId
   */
  protected function saveImagePermanently(array $imageId) {
    if (empty($imageId)) {
      return;
    }

    $file = File::load($imageId[0]);
    if (gettype($file) == 'object') {
      // Record the module using the file.
      $this->fileUsage->add($file, 'bf_homepage', 'bf_homepage', 1);
    }

  }

  /**
   * {@inheritdoc}
   */
  public static function create(ContainerInterface $container) {

    return new static(
      $container->get('config.factory'),
      $container->get('file.usage')

    );
  }

}
