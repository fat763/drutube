<?php
/**
 * @file
 * drutube_video.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function drutube_video_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_video_author|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_video_author';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'video_author_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['field_collection_item|field_video_author|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'published' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'sharethis' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'links' => array(
      'weight' => '13',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|video|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|video|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'video';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'published' => array(
      'weight' => '3',
      'label' => 'inline',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h3',
        'class' => '',
      ),
    ),
    'links' => array(
      'weight' => '11',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|video|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function drutube_video_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'published';
  $ds_field->label = 'Опубликовано';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:created] -- [node:author]',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['published'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'sharethis';
  $ds_field->label = 'Закладки';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->properties = array(
    'block' => 'sharethis|sharethis_block',
    'block_render' => '3',
  );
  $export['sharethis'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'video_author_link';
  $ds_field->label = 'video_author_link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'field_collection_item' => 'field_collection_item',
  );
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php 
$link = l($entity->field_author_name[LANGUAGE_NONE][0][\'value\'], $entity->field_do_profile[LANGUAGE_NONE][0][\'url\']);
print $link;
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['video_author_link'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function drutube_video_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_video_author|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_video_author';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'video_author_link',
      ),
    ),
    'fields' => array(
      'video_author_link' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['field_collection_item|field_video_author|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'published',
      ),
      'left' => array(
        0 => 'field_voting',
        1 => 'sharethis',
      ),
      'right' => array(
        0 => 'field_video',
        1 => 'field_term_event',
        2 => 'field_author',
        3 => 'field_term_topics',
        4 => 'field_term_video_type',
        5 => 'field_term_audience_background',
        6 => 'field_term_core',
        7 => 'field_term_tags',
        8 => 'field_video_description',
        9 => 'field_presentation',
      ),
      'footer' => array(
        0 => 'links',
      ),
    ),
    'fields' => array(
      'published' => 'header',
      'field_voting' => 'left',
      'sharethis' => 'left',
      'field_video' => 'right',
      'field_term_event' => 'right',
      'field_author' => 'right',
      'field_term_topics' => 'right',
      'field_term_video_type' => 'right',
      'field_term_audience_background' => 'right',
      'field_term_core' => 'right',
      'field_term_tags' => 'right',
      'field_video_description' => 'right',
      'field_presentation' => 'right',
      'links' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|video|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|video|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'video';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col_stacked_fluid';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'header' => array(
        0 => 'title',
      ),
      'left' => array(
        0 => 'field_voting',
        1 => 'field_video',
      ),
      'right' => array(
        0 => 'published',
        1 => 'field_term_event',
        2 => 'field_author',
        3 => 'field_term_topics',
        4 => 'field_term_video_type',
        5 => 'field_term_audience_background',
        6 => 'field_term_core',
        7 => 'field_term_tags',
      ),
      'footer' => array(
        0 => 'links',
      ),
    ),
    'fields' => array(
      'title' => 'header',
      'field_voting' => 'left',
      'field_video' => 'left',
      'published' => 'right',
      'field_term_event' => 'right',
      'field_author' => 'right',
      'field_term_topics' => 'right',
      'field_term_video_type' => 'right',
      'field_term_audience_background' => 'right',
      'field_term_core' => 'right',
      'field_term_tags' => 'right',
      'links' => 'footer',
    ),
    'classes' => array(),
  );
  $export['node|video|teaser'] = $ds_layout;

  return $export;
}
