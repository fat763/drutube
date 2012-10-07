<?php
/**
 * @file
 * drutube_abuse.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function drutube_abuse_default_rules_configuration() {
  $items = array();
  $items['rules_unpublish_video_node_if_more_then_x_abuse_reported_cloned_'] = entity_import('rules_config', '{ "rules_unpublish_video_node_if_more_then_x_abuse_reported_cloned_" : {
      "LABEL" : "Unpublish video-node if more then X abuse reported",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "TAGS" : [ "abuse" ],
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : [ "flag_flagged_abuse" ],
      "IF" : [
        { "flag_threshold_node" : {
            "flag" : "abuse",
            "node" : [ "flagged-node" ],
            "number" : "10",
            "operator" : "\\u003E="
          }
        }
      ],
      "DO" : [
        { "node_unpublish" : { "node" : [ "flagged-node" ] } },
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "abuse", "node" : [ "flagged-node" ] },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "user_who_flagged" : "Current user who abused the video" },
            "DO" : [
              { "flag_unflagnode" : {
                  "flag" : "abuse",
                  "node" : [ "flagged-node" ],
                  "flagging_user" : [ "user-who-flagged" ],
                  "permission_check" : 0
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
