<?php
/**
 * @file
 * drutube_video.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function drutube_video_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_video';
  $page->task = 'page';
  $page->admin_title = 'Add Video';
  $page->admin_description = '';
  $page->path = 'add-video';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Добавить видео',
    'name' => 'main-menu',
    'weight' => '-100',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_add_video_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'add_video';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Добавить новое видео';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'Спасибо, что решили добавить новое видео на DruTube.

Пожалуйста, ознакомьтесь с правилами добавления видео материалов:

<ul>
  <li>Публикуемое видео должно соответствовать тематике CMS Drupal.</li>
  <li>Видео должно быть свободно-распространяемым и предварительно загруженным на один из видео-хостингов: YouTube, Vimeo, Yandex Video.</li>
  <li>Содержание видео не должно нарушать существующие законы или оскорблять чувства зрителей.</li>
  <li>Перед добавлением, воспользуйтесь <a href="video">поиском</a> и убедитесь в том, что вы не создаете дубликат.</li>
</ul>

<strong>Для того, чтобы добавить видео, пожалуйста, <a href="user/register">зарегистрируйтесь</a> или <a href="user/login">войдите</a> на сайт.</strong>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_video'] = $page;

  return $pages;

}
