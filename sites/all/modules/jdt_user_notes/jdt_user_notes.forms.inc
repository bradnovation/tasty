<?php

/**
 * @file
 * Implement Form API
 * The Form Builder
 */

/**
 * Build the 'new note' form.
 */
function jdt_user_notes_gen_form ($form, &$form_state, $node) {
  global $user;
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
    '#type' => 'value',
    '#size' => 10,
    '#value' => $node->nid,
    '#required' => TRUE,
  );

  $form['author_id'] = array(
    '#title' => t('Author ID'),
    '#description' => 'UID of the author',
    '#type' => 'value',
    '#size' => 10,
    '#value' => $user->uid,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add note'),
    '#validate' => 'jdt_user_notes_new_form_validate()',
  );

  return $form;
}

function jdt_user_notes_gen_edit_form ($form, &$form_state, $nid) {
  global $user;

  module_load_include('inc', 'jdt_user_notes', 'jdt_user_notes.helpers');

  $result = jdt_user_notes_get($nid);

  $form['note_text'] = array(
    '#title' => t('User note'),
    '#description' => 'Please enter some text',
    '#type' => 'textarea',
    '#default_value' => $result->note_text,
    '#required' => TRUE,
  );

  $form['article_nid'] = array(
    '#title' => t('Article title'),
    '#description' => 'Node ID of the article',
    '#type' => 'value',
    '#size' => 10,
    '#value' => $result->article_nid,
    '#required' => TRUE,
  );

  $form['author_id'] = array(
    '#title' => t('Author ID'),
    '#description' => 'UID of the author',
    '#type' => 'value',
    '#size' => 10,
    '#value' => $user->uid,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Edit'),
  );

  return $form;
}

/**
 * Build the 'edit note' form.
 */

/**
 * Form to display all notes associated with article
 */
function jdt_user_notes_article_notes_form ($form, &$form_state, $nid) {

}

/**
 * Implements hook_validate().
 */
function jdt_user_notes_gen_form_validate($form, &$form_state) {
  $note_contents = $form_state['values']['note_text'];
  if (!isset($note_contents)) {
    form_set_error(t('Please add an annotation.'));
  }
}

/**
 * Submit the form.
 */
function jdt_user_notes_gen_form_submit($form, &$form_state) {

  module_load_include('inc', 'jdt_user_notes', 'jdt_user_notes.helpers');

  $note_text = $form_state['values']['note_text'];
  $nid = $form_state['values']['article_nid'];
  $author_id = $form_state['values']['author_id'];

  jdt_user_notes_create($nid, $note_text, $author_id);
}

/**
 * Edit the note from the form.
 */
function jdt_user_notes_gen_edit_form_submit(&$form, $form_state, $nid) {

  module_load_include('inc', 'jdt_user_notes', 'jdt_user_notes.helpers');

  $note_text = $form_state['values']['note_text'];
  $nid = $form_state['values']['article_nid'];
  $author_id = $form_state['values']['author_id'];

  jdt_user_notes_modify($nid, $note_text, $author_id);

}



