<?php
/**
 * @file
 * jdt_article_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function jdt_article_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function jdt_article_content_type_node_info() {
  $items = array(
    'jdt_article' => array(
      'name' => t('JDT Article'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
