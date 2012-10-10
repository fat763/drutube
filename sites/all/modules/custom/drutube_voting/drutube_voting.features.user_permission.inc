<?php
/**
 * @file
 * drutube_voting.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function drutube_voting_user_default_permissions() {
  $permissions = array();

  // Exported permission: use vote up/down.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      0 => 'administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'vud',
  );

  return $permissions;
}
