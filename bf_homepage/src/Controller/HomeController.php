<?php

/**
 * @file
 *
 * Contains \Drupal\bf_homepage\Controller\HomeController.
 *
 * @author Jon Kamke <jon@kamke.org>
 */

namespace Drupal\bf_homepage\Controller;

use Drupal\Core\Controller\ControllerBase;
use Drupal\file\Entity\File;
use Drupal\Core\Url;

/**
 * Class HomeController.
 *
 * @package Drupal\bf_homepage\Controller
 */
class HomeController extends ControllerBase {
  /**
   * Home.
   *
   * @return string Return renderable array.
   */
  public function home() {
    $config = $this->config('bf_homepage.homepage');

    if (empty($config->get('mainimage'))) {
      return;
    }

    $mainImageArray = $this->loadImage($config->get('mainimage'), 'home_hero');
    $leftImageArray = $this->loadImage($config->get('leftimage'), 'home_thum');
    $centerImageArray = $this->loadImage($config->get('centerimage'), 'home_thum');
    $rightImageArray = $this->loadImage($config->get('rightimage'), 'home_thum');

    return [
      '#theme' => 'homepage_twig',
      '#heroSection' => ['image' => $mainImageArray],
      '#leftSection' => [
        'image' => $leftImageArray,
        'title' => [
          '#type' => 'link',
          '#url' => Url::fromUri($config->get('left_block_link')),
          '#title' => t($config->get('left_block_title')),
          '#options' => [
            'attributes' => ['class' => ['callout_title']],
          ],
        ],
        'blurb' => t($config->get('left_block_blurb')),
      ],
      '#centerSection' => [
        'image' => $centerImageArray,
        'title' => [
          '#type' => 'link',
          '#url' => Url::fromUri($config->get('center_block_link')),
          '#title' => t($config->get('center_block_title')),
          '#options' => [
            'attributes' => ['class' => ['callout_title']],
          ],
        ],
        'blurb' => t($config->get('center_block_blurb')),
      ],
      '#rightSection' => [
        'image' => $rightImageArray,
        'title' => [
          '#type' => 'link',
          '#url' => Url::fromUri($config->get('right_block_link')),
          '#title' => t($config->get('right_block_title')),
          '#options' => [
            'attributes' => ['class' => ['callout_title']],
          ],
        ],
        'blurb' => t($config->get('right_block_blurb')),
      ],

    ];
  }

  /**
   * Load an image from fid and an image style.
   *
   * @param $fid
   * @param $imageStyle
   * @return array
   */
  private function loadImage($fid, $imageStyle) {
    $file = File::load($fid);

    $variables = [
      'style_name' => $imageStyle,
      'uri' => $file->getFileUri(),
    ];

    // The image.factory service will check if our image is valid.
    $image = \Drupal::service('image.factory')->get($file->getFileUri());
    if ($image->isValid()) {
      $variables['width'] = $image->getWidth();
      $variables['height'] = $image->getHeight();
    }
    else {
      $variables['width'] = $variables['height'] = NULL;
    }

    $render_array = [
      '#theme' => 'image_style',
      '#width' => $variables['width'],
      '#height' => $variables['height'],
      '#style_name' => $variables['style_name'],
      '#uri' => $variables['uri'],
    ];

    return $render_array;
  }

}
