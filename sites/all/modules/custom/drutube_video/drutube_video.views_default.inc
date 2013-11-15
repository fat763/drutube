<?php
/**
 * @file
 * drutube_video.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function drutube_video_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'catalog';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Videos by taxonomy terms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Видео по Категориям';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Термин таксономии: Содержимое, используя Теги */
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['id'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['field'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['required'] = TRUE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_topics:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Критерий сортировки: COUNT(Содержимое: Nid) */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['relationship'] = 'reverse_field_term_event_node';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';

  /* Display: Tags Page */
  $handler = $view->new_display('page', 'Tags Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по тегам';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Теги */
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['id'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['field'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['relationships']['reverse_field_term_tags_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_tags:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: COUNT(Содержимое: Nid) */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  $handler->display->display_options['path'] = 'video-by-tags';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Catalog';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Core Block */
  $handler = $view->new_display('block', 'Core Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по версии ядра';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Версия ядра */
  $handler->display->display_options['relationships']['reverse_field_term_core_node']['id'] = 'reverse_field_term_core_node';
  $handler->display->display_options['relationships']['reverse_field_term_core_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_core_node']['field'] = 'reverse_field_term_core_node';
  $handler->display->display_options['relationships']['reverse_field_term_core_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_core:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: COUNT(Содержимое: Nid) */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['relationship'] = 'reverse_field_term_core_node';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';
  $handler->display->display_options['block_description'] = 'Видео по версии ядра';

  /* Display: Tags Block */
  $handler = $view->new_display('block', 'Tags Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по тегам';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_tags:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: COUNT(Содержимое: Nid) */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';

  /* Display: Events Block */
  $handler = $view->new_display('block', 'Events Block', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по событиям';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'page_1';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Событие */
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['id'] = 'reverse_field_term_event_node';
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['field'] = 'reverse_field_term_event_node';
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_event:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: COUNT(Содержимое: Nid) */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  $handler->display->display_options['sorts']['nid']['relationship'] = 'reverse_field_term_event_node';
  $handler->display->display_options['sorts']['nid']['group_type'] = 'count';
  $handler->display->display_options['sorts']['nid']['order'] = 'DESC';

  /* Display: Topics Block */
  $handler = $view->new_display('block', 'Topics Block', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по категориям';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Тематика */
  $handler->display->display_options['relationships']['reverse_field_term_topics_node']['id'] = 'reverse_field_term_topics_node';
  $handler->display->display_options['relationships']['reverse_field_term_topics_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_topics_node']['field'] = 'reverse_field_term_topics_node';
  $handler->display->display_options['relationships']['reverse_field_term_topics_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_topics:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;

  /* Display: Types Block */
  $handler = $view->new_display('block', 'Types Block', 'block_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по типу';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Тип видео */
  $handler->display->display_options['relationships']['reverse_field_term_video_type_node']['id'] = 'reverse_field_term_video_type_node';
  $handler->display->display_options['relationships']['reverse_field_term_video_type_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_video_type_node']['field'] = 'reverse_field_term_video_type_node';
  $handler->display->display_options['relationships']['reverse_field_term_video_type_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_video_type:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;

  /* Display: Audience Background Block */
  $handler = $view->new_display('block', 'Audience Background Block', 'block_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по аудитории';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Уровень подготовки */
  $handler->display->display_options['relationships']['reverse_field_term_audience_background_node']['id'] = 'reverse_field_term_audience_background_node';
  $handler->display->display_options['relationships']['reverse_field_term_audience_background_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_audience_background_node']['field'] = 'reverse_field_term_audience_background_node';
  $handler->display->display_options['relationships']['reverse_field_term_audience_background_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_audience_background:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;

  /* Display: Events Page */
  $handler = $view->new_display('page', 'Events Page', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео по событиям';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Термин таксономии: Содержимое, используя Событие */
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['id'] = 'reverse_field_term_event_node';
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['field'] = 'reverse_field_term_event_node';
  $handler->display->display_options['relationships']['reverse_field_term_event_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  /* Поле: COUNT(Содержимое: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'reverse_field_term_tags_node';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[name] ([nid])';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = 'video?f[0]=field_term_event:[tid]';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'videos-by-events';
  $translatables['catalog'] = array(
    t('Master'),
    t('Видео по Категориям'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('field_term_tags'),
    t('ID термина'),
    t('.'),
    t(','),
    t('Nid'),
    t('[name] ([nid])'),
    t('Tags Page'),
    t('Видео по тегам'),
    t('Core Block'),
    t('Видео по версии ядра'),
    t('field_term_core'),
    t('Tags Block'),
    t('Все теги'),
    t('Events Block'),
    t('Видео по событиям'),
    t('Все события'),
    t('field_term_event'),
    t('Topics Block'),
    t('Видео по категориям'),
    t('field_term_topics'),
    t('Types Block'),
    t('Видео по типу'),
    t('field_term_video_type'),
    t('Audience Background Block'),
    t('Видео по аудитории'),
    t('field_term_audience_background'),
    t('Events Page'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
  );
  $export['catalog'] = $view;

  $view = new view();
  $view->name = 'new_videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'New Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Подвал: Глобальный: Текстовое поле */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="more-link">
  <a href="/video">ещё</a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'new-videos';
  $translatables['new_videos'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('<div class="more-link">
  <a href="/video">ещё</a>
</div>'),
    t('Page'),
  );
  $export['new_videos'] = $view;

  $view = new view();
  $view->name = 'profilevideo';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Видео в профиле';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Видео в профиле';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['argument'] = 'Пользователь еще не добавил видео.';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/addedvideo';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Добавленное видео';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Автор публикации */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Связь: Обработчик испорчен или отсутствует */
  $handler->display->display_options['relationships']['reverse_field_profile_field_collection_item']['id'] = 'reverse_field_profile_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_profile_field_collection_item']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_profile_field_collection_item']['field'] = 'reverse_field_profile_field_collection_item';
  $handler->display->display_options['relationships']['reverse_field_profile_field_collection_item']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['reverse_field_profile_field_collection_item']['label'] = 'Field collection item referencing Пользователь from field_profile';
  $handler->display->display_options['relationships']['reverse_field_profile_field_collection_item']['required'] = TRUE;
  /* Связь: Обработчик испорчен или отсутствует */
  $handler->display->display_options['relationships']['field_video_author_node']['id'] = 'field_video_author_node';
  $handler->display->display_options['relationships']['field_video_author_node']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_video_author_node']['field'] = 'field_video_author_node';
  $handler->display->display_options['relationships']['field_video_author_node']['relationship'] = 'reverse_field_profile_field_collection_item';
  $handler->display->display_options['relationships']['field_video_author_node']['label'] = 'field_video_author';
  $handler->display->display_options['relationships']['field_video_author_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'user/%/addedvideo';
  $translatables['profilevideo'] = array(
    t('Master'),
    t('Видео в профиле'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Все'),
    t('Page'),
    t('автор'),
    t('Field collection item referencing Пользователь from field_profile'),
    t('field_video_author'),
  );
  $export['profilevideo'] = $view;

  $view = new view();
  $view->name = 'video_blocks';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video Blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Видео от автора';
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Содержимое: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Результаты голосования';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => 'vote',
    'function' => 'sum',
  );
  /* Связь: Содержимое: Автор публикации */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Поле: Содержимое: Путь */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Видео */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = '';
  $handler->display->display_options['fields']['field_video']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_video']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_video']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video']['type'] = 'media';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'file_view_mode' => 'media_preview',
  );
  /* Поле: Содержимое: Voting */
  $handler->display->display_options['fields']['field_voting']['id'] = 'field_voting';
  $handler->display->display_options['fields']['field_voting']['table'] = 'field_data_field_voting';
  $handler->display->display_options['fields']['field_voting']['field'] = 'field_voting';
  $handler->display->display_options['fields']['field_voting']['label'] = '';
  $handler->display->display_options['fields']['field_voting']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_voting']['click_sort_column'] = 'vud_widget';
  /* Поле: Содержимое: Дата обновления */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd.m.Y';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Обработчик испорчен или отсутствует */
  $handler->display->display_options['fields']['field_abuse_flag']['id'] = 'field_abuse_flag';
  $handler->display->display_options['fields']['field_abuse_flag']['table'] = 'field_data_field_abuse_flag';
  $handler->display->display_options['fields']['field_abuse_flag']['field'] = 'field_abuse_flag';
  $handler->display->display_options['fields']['field_abuse_flag']['label'] = '';
  $handler->display->display_options['fields']['field_abuse_flag']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Версия ядра */
  $handler->display->display_options['fields']['field_term_core']['id'] = 'field_term_core';
  $handler->display->display_options['fields']['field_term_core']['table'] = 'field_data_field_term_core';
  $handler->display->display_options['fields']['field_term_core']['field'] = 'field_term_core';
  $handler->display->display_options['fields']['field_term_core']['delta_offset'] = '0';
  /* Поле: Содержимое: Событие */
  $handler->display->display_options['fields']['field_term_event']['id'] = 'field_term_event';
  $handler->display->display_options['fields']['field_term_event']['table'] = 'field_data_field_term_event';
  $handler->display->display_options['fields']['field_term_event']['field'] = 'field_term_event';
  /* Поле: Содержимое: Теги */
  $handler->display->display_options['fields']['field_term_tags']['id'] = 'field_term_tags';
  $handler->display->display_options['fields']['field_term_tags']['table'] = 'field_data_field_term_tags';
  $handler->display->display_options['fields']['field_term_tags']['field'] = 'field_term_tags';
  $handler->display->display_options['fields']['field_term_tags']['delta_offset'] = '0';
  /* Поле: Содержимое: Тематика */
  $handler->display->display_options['fields']['field_term_topics']['id'] = 'field_term_topics';
  $handler->display->display_options['fields']['field_term_topics']['table'] = 'field_data_field_term_topics';
  $handler->display->display_options['fields']['field_term_topics']['field'] = 'field_term_topics';
  $handler->display->display_options['fields']['field_term_topics']['delta_offset'] = '0';
  /* Поле: Содержимое: Уровень подготовки */
  $handler->display->display_options['fields']['field_term_audience_background']['id'] = 'field_term_audience_background';
  $handler->display->display_options['fields']['field_term_audience_background']['table'] = 'field_data_field_term_audience_background';
  $handler->display->display_options['fields']['field_term_audience_background']['field'] = 'field_term_audience_background';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Поле: Глобальный: Контекстные ссылки */
  $handler->display->display_options['fields']['contextual_links']['id'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['table'] = 'views';
  $handler->display->display_options['fields']['contextual_links']['field'] = 'contextual_links';
  $handler->display->display_options['fields']['contextual_links']['label'] = '';
  $handler->display->display_options['fields']['contextual_links']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['contextual_links']['fields'] = array(
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
    'title' => 0,
    'field_abuse_flag' => 0,
    'field_voting' => 0,
    'field_term_core' => 0,
    'field_video' => 0,
    'changed' => 0,
    'field_term_event' => 0,
    'field_term_tags' => 0,
    'field_term_topics' => 0,
    'field_term_audience_background' => 0,
  );
  /* Критерий сортировки: Результаты голосования: Значение */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['code'] = 'if (arg(0) == \'node\' && is_numeric(arg(1))) {
	$node = node_load(arg(1));
	$uid = $node->uid;
}
return $uid;';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['uid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['uid']['validate']['type'] = 'user';
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video' => 'video',
  );

  /* Display: Видео от автора */
  $handler = $view->new_display('block', 'Видео от автора', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Видео от автора';
  $handler->display->display_options['link_url'] = 'video';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Видео */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = '';
  $handler->display->display_options['fields']['field_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video']['type'] = 'media';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'file_view_mode' => 'media_preview',
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Путь */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
  $path = file_uri_target($data->field_field_video[0][\'rendered\'][\'file\'][\'#path\']);
  echo theme(\'image_style\', array(\'style_name\' => \'media_small\', \'path\' => $path));  
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Содержимое: Дата обновления */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Дата';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd.m.Y';
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Автор';
  /* Поле: Результаты голосования: Значение */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['value']['format_plural_singular'] = '1 голос';
  $handler->display->display_options['fields']['value']['format_plural_plural'] = '@count голоса';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';

  /* Display: Популярное видео */
  $handler = $view->new_display('block', 'Популярное видео', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Популярное видео';
  $handler->display->display_options['link_url'] = 'video';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Путь */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Поле: Содержимое: Видео */
  $handler->display->display_options['fields']['field_video']['id'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['table'] = 'field_data_field_video';
  $handler->display->display_options['fields']['field_video']['field'] = 'field_video';
  $handler->display->display_options['fields']['field_video']['label'] = '';
  $handler->display->display_options['fields']['field_video']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video']['type'] = 'media';
  $handler->display->display_options['fields']['field_video']['settings'] = array(
    'file_view_mode' => 'media_preview',
  );
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
  $path = file_uri_target($data->field_field_video[0][\'rendered\'][\'file\'][\'#path\']);
  echo theme(\'image_style\', array(\'style_name\' => \'media_small\', \'path\' => $path));  
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Содержимое: Дата обновления */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Дата';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd.m.Y';
  /* Поле: Результаты голосования: Значение */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = '';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['format_plural'] = TRUE;
  $handler->display->display_options['fields']['value']['format_plural_singular'] = '1 голос';
  $handler->display->display_options['fields']['value']['format_plural_plural'] = '@count голоса';
  /* Поле: Содержимое: В кадре */
  $handler->display->display_options['fields']['field_author']['id'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['table'] = 'field_data_field_author';
  $handler->display->display_options['fields']['field_author']['field'] = 'field_author';
  $handler->display->display_options['fields']['field_author']['element_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_author']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_author']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Результаты голосования: Значение */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 1;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $translatables['video_blocks'] = array(
    t('Master'),
    t('Видео от автора'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Результаты голосования'),
    t('автор'),
    t('Версия ядра'),
    t('Событие'),
    t('Теги'),
    t('Тематика'),
    t('Уровень подготовки'),
    t('Все'),
    t('Дата'),
    t('Автор'),
    t('.'),
    t(','),
    t('Популярное видео'),
    t('В кадре'),
  );
  $export['video_blocks'] = $view;

  return $export;
}
