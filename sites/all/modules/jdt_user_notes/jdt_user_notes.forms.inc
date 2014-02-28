<?php

/**
 * Implement Form API
 */


function jdt_user_notes_new_form ($form, &$form_state, $node) {
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
    );

  return $form;
}

function jdt_user_notes_new_form_submit($form, &$form_state) {

  module_load_include('inc', 'jdt_user_notes','jdt_user_notes.helpers');

  $note_text = $form_state['values']['note_text'];
  $nid = $form_state['values']['article_nid'];
  $author_id = $form_state['values']['author_id'];

dpm($form_state);

  jdt_user_notes_create($nid, $note_text, $author_id, "insert");
  drupal_set_message("It puts itself in the db.");
}

