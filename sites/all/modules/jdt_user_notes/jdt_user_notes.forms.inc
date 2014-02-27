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

    $form['author_uid'] = [
        '#title' => t('User ID'),
        '#description' => 'This is the ID of the user submitting the note',
        '#type' => 'value',
        '#size' => 10,
        '#value' => $user->uid,
        '#required' => TRUE,
    ];

    $form['created'] = array(
        '#title' => t('Note Created'),
        '#description' => 'This is the time the note was created',
        '#type' => 'int',
        '#size' => 11,
        '#value' => REQUEST_TIME,
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
    $user_id = $form_state['values']['article_uid']; // change shorthand to array();

  jdt_user_notes_create($nid, $note_text, $user_id);
  drupal_set_message("It puts itself in the db.");
}

/**
 * The note edit form
 */

function jdt_user_notes_edit_form ($form, &$form_state) {

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

    $form['author_uid'] = array(
        '#title' => t('User ID'),
        '#description' => 'This is the ID of the user submitting the note',
        '#type' => 'int',
        '#size' => 10,
        '#required' => TRUE,
    );

    $form['note_id'] = array(
        '#title' => t('Note ID'),
        '#description' => 'This is the note ID',
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