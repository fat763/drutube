<?php
/**
 * @file
 * drutube_video.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function drutube_video_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-video-field_author'
  $field_instances['node-video-field_author'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_author',
    'label' => 'В кадре',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-video-field_presentation'
  $field_instances['node-video-field_presentation'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Ссылка на презентацию или дополнительные материалы.',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_presentation',
    'label' => 'Презентация',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-video-field_term_audience_background'
  $field_instances['node-video-field_term_audience_background'] = array(
    'bundle' => 'video',
    'default_value' => array(
      0 => array(
        'tid' => 27,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_audience_background',
    'label' => 'Уровень подготовки',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-video-field_term_core'
  $field_instances['node-video-field_term_core'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_core',
    'label' => 'Версия ядра',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-video-field_term_event'
  $field_instances['node-video-field_term_event'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_event',
    'label' => 'Событие',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-video-field_term_tags'
  $field_instances['node-video-field_term_tags'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_tags',
    'label' => 'Теги',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-video-field_term_topics'
  $field_instances['node-video-field_term_topics'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_topics',
    'label' => 'Тематика',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-video-field_term_video_type'
  $field_instances['node-video-field_term_video_type'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'drutube_misc',
        'settings' => array(),
        'type' => 'drutube_misc_taxonomy_term_reference_link',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_video_type',
    'label' => 'Тип видео',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-video-field_video'
  $field_instances['node-video-field_video'] = array(
    'bundle' => 'video',
    'deleted' => 0,
    'description' => 'Видео с поддерживаемых видеосервисов',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'media',
        'settings' => array(
          'file_view_mode' => 'media_original',
        ),
        'type' => 'media',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'media',
        'settings' => array(
          'file_view_mode' => 'media_preview',
        ),
        'type' => 'media',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_video',
    'label' => 'Видео',
    'required' => 0,
    'settings' => array(
      'file_extensions' => 'mov m4v mp4 mpeg avi ogg wmv',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'private' => 0,
          'public' => 0,
          'vimeo' => 'vimeo',
          'yandex' => 'yandex',
          'youtube' => 'youtube',
        ),
        'allowed_types' => array(
          'audio' => 0,
          'default' => 0,
          'image' => 0,
          'video' => 'video',
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'media_generic',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-video-field_video_description'
  $field_instances['node-video-field_video_description'] = array(
    'bundle' => 'video',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_video_description',
    'label' => 'Описание',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('В кадре');
  t('Версия ядра');
  t('Видео');
  t('Видео с поддерживаемых видеосервисов');
  t('Описание');
  t('Презентация');
  t('Событие');
  t('Ссылка на презентацию или дополнительные материалы.');
  t('Теги');
  t('Тематика');
  t('Тип видео');
  t('Уровень подготовки');

  return $field_instances;
}
