<?php

/**
 * @file
 * Up Down Widget.
 */


function drutube_misc_drutube_misc_updown_vud_widgets() {
  dpm("Inc!");
  return array(
    'title' => t('Drutube updown'),
    'widget template' => 'drutube_widget',
  );
}