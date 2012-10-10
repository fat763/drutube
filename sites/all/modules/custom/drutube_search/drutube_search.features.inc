<?php
/**
 * @file
 * drutube_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function drutube_search_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function drutube_search_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function drutube_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Video Index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "local_server",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "default" : "0", "bundles" : { "video" : "video" } }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "-49", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "-48", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-47", "settings" : { "fields" : [] } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-46", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "search_api_viewed" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "search_api_viewed" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        }
      },
      "fields" : {
        "nid" : { "type" : "integer" },
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_term_event" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_term_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_term_topics" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_term_video_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_term_audience_background" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_term_core" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_author" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "body:value" : { "type" : "text" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function drutube_search_default_search_api_server() {
  $items = array();
  $items['local_server'] = entity_import('search_api_server', '{
    "name" : "Local Server",
    "machine_name" : "local_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "2",
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index_type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_title",
            "type" : "text",
            "boost" : "5.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index_created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index_changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index_author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index_search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_term_event" : {
            "table" : "search_api_db_default_node_index_field_term_event",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_term_tags" : {
            "table" : "search_api_db_default_node_index_field_term_tags",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_term_topics" : {
            "table" : "search_api_db_default_node_index_field_term_topics",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_term_video_type" : {
            "table" : "search_api_db_default_node_index_field_term_video_type",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_term_audience_background" : {
            "table" : "search_api_db_default_node_index_field_term_audience_background",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_term_core" : {
            "table" : "search_api_db_default_node_index_field_term_core",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "search_api_viewed" : {
            "table" : "search_api_db_default_node_index_search_api_viewed",
            "type" : "text",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_default_node_index_nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_author" : {
            "table" : "search_api_db_default_node_index_field_author",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
