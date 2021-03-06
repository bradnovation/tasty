<?php
/**
 * @file
 * jdt_article_content_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function jdt_article_content_type_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_addl|node|jdt_article|form';
  $field_group->group_name = 'group_addl';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'jdt_article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional Info',
    'weight' => '8',
    'children' => array(
      0 => 'field_contributer',
      1 => 'field_related_articles',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Additional Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-addl field-group-fieldset',
        'description' => 'Stuff You\'ll Like',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_addl|node|jdt_article|form'] = $field_group;

  return $export;
}
