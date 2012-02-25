<?php
/**
 * @file
 * drutube_abuse.features.inc
 */

/**
 * Implements hook_views_api().
 */
function drutube_abuse_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}

/**
 * Implements hook_flag_default_flags().
 */
function drutube_abuse_flag_default_flags() {
  $flags = array();
  // Exported flag: "Жалобы".
  $flags['abuse'] = array(
    'content_type' => 'node',
    'title' => 'Жалобы',
    'global' => '0',
    'types' => array(
      0 => 'video',
    ),
    'flag_short' => 'Пожаловаться',
    'flag_long' => 'Если вы считаете бла...',
    'flag_message' => 'Жалоба принята',
    'unflag_short' => 'Отменить жалобу',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '1',
        1 => '2',
        2 => '3',
      ),
      'unflag' => array(
        0 => '1',
        1 => '2',
        2 => '3',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'api_version' => 2,
    'module' => 'drutube_abuse',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;
}

/**
 * Implements hook_node_info().
 */
function drutube_abuse_node_info() {
  $items = array(
    'video' => array(
      'name' => t('Video'),
      'base' => 'node_content',
      'description' => t('Видео-контент включает код-плеера, автора, теги, событие, комментарии disquess.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
