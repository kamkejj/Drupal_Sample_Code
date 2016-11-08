<?php
/**
 * @file
 *
 * Admin page callbacks for the BF Admin module.
 *
 * @author Jon Kamke <jon@kamke.org>
 */

/**
 * Form callback for various settings.
 *
 * @see bf_admin_menu
 */
function bf_admin_site_settings_form() {
  $form = array();

  $form['petOfTheWeek'] = array(
    '#type' => 'fieldset',
    '#title' => t('Pet Of The Week'),
    '#weight' => 0,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['petOfTheWeek']['bf_potw_disable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Disable Pet Of The Week'),
    '#default_value' => variable_get('bf_potw_disable', 0),
    '#required' => FALSE,
  );

  $form['chapter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Chapter'),
    '#weight' => 1,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['chapter']['bf_chapter_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Chapter Name'),
    '#default_value' => variable_get('bf_chapter_name'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => TRUE,
  );

  $form['chapter']['bf_street_address_1'] = array(
    '#type' => 'textfield',
    '#title' => t('Street Address 1'),
    '#default_value' => variable_get('bf_street_address_1'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_street_address_2'] = array(
    '#type' => 'textfield',
    '#title' => t('Street Address 2'),
    '#default_value' => variable_get('bf_street_address_2'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#default_value' => variable_get('bf_city'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_state'] = array(
    '#type' => 'textfield',
    '#title' => t('State'),
    '#default_value' => variable_get('bf_state'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_zipcode'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip Code'),
    '#default_value' => variable_get('bf_zipcode'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone'),
    '#default_value' => variable_get('bf_phone'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_fax'] = array(
    '#type' => 'textfield',
    '#title' => t('Fax'),
    '#default_value' => variable_get('bf_fax'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#default_value' => variable_get('bf_email'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['chapter']['bf_hours'] = array(
    '#type' => 'textarea',
    '#title' => t('Hours'),
    '#default_value' => variable_get('bf_hours'),
    '#required' => FALSE,
  );

  $form['social'] = array(
    '#type' => 'fieldset',
    '#title' => t('Social'),
    '#weight' => 20,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['social']['bf_facebook_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook Profile URL'),
    '#default_value' => variable_get('bf_facebook_profile_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['social']['bf_twitter_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Profile URL'),
    '#default_value' => variable_get('bf_twitter_profile_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['social']['bf_instagram_profile_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Instagram Profile URL'),
    '#default_value' => variable_get('bf_instagram_profile_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['social']['bf_youtube_channel_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Youtube Profile URL'),
    '#default_value' => variable_get('bf_youtube_channel_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['social']['bf_email_signup_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Signup URL'),
    '#default_value' => variable_get('bf_email_signup_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['services'] = array(
    '#type' => 'fieldset',
    '#title' => t('Services'),
    '#weight' => 30,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['services']['bf_google_search_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Search ID'),
    '#default_value' => variable_get('bf_google_search_id'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['services']['bf_google_calendar_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Calendar ID'),
    '#default_value' => variable_get('bf_google_calendar_id'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['other'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other'),
    '#weight' => 50,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['other']['bf_donate_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Donate URL'),
    '#description' => t('The page URL where the donate button should link to.'),
    '#default_value' => variable_get('bf_donate_url'),
    '#size' => 60,
    '#maxlength' => 128,
    '#required' => FALSE,
  );

  $form['other']['bf_footer_links'] = array(
    '#type' => 'text_format',
    '#title' => t('Footer links'),
    '#default_value' => variable_get('bf_footer_links'),
    '#format' => NULL,
    '#required' => FALSE,
  );

  $form = system_settings_form($form);

  return $form;
}