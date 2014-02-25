<?php
/**
 * Implement Form API
 */


function jdt_user_notes_new_form ($form, &$form_state) {

  $form['note_text'] = array(
    '#title' => t('User note'),
    '#description' => 'Please enter some text',
    '#type' => 'textarea',
    '#default_value' => '',
    '#required' => TRUE,
  );

  $form['article_nid'] = array(
  '#title' => t('Article title'),
    '#description' => 'Node ID of the article',
    '#type' => 'int',
    '#size' => 10,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add note'),
  );

  return $form;
}