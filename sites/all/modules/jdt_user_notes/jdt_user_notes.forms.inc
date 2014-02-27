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

function jdt_user_notes_new_form_submit($form, &$form_state){
    drupal_set_message("It puts itself in the db.")
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