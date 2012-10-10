<?php
/**
 * @file
 * drutube_voting.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function drutube_voting_field_default_fields() {
  $fields = array();

  // Exported field: 'node-video-field_voting'.
  $fields['node-video-field_voting'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_voting',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'vud_field',
      'settings' => array(
        'votingapi_tag' => 'vote',
        'vud_widget' => 'updown',
      ),
      'translatable' => '0',
      'type' => 'vud_field',
    ),
    'field_instance' => array(
      'bundle' => 'video',
      'default_value' => array(
        0 => array(
          'vud_widget' => 'updown',
          'votingapi_tag' => 'vote',
        ),
      ),
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'vud_field',
          'settings' => array(),
          'type' => 'default',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'vud_field',
          'settings' => array(),
          'type' => 'default',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_voting',
      'label' => 'Voting',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
        'votingapi_tag' => 'vote',
        'vud_widget' => 'drutube_misc_updown',
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'vud_field',
        'settings' => array(),
        'type' => 'vud_field_default_widget',
        'weight' => '11',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Voting');

  return $fields;
}
