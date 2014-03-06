<?php
/**
 * @file
 * Dealing with CRUD.
 */


/**
 * API for CRUD functions.
 *
 * Create, Read, Update/Modify & Delete
 * in a "helpers .inc".
 */
function jdt_user_notes_create($nid, $note_text, $author_id) {
  $query = db_insert('jdt_user_notes')
    ->fields(array(
      'article_nid' => $nid,
      'author_id' => $author_id,
      'note_text' => $note_text,
      'created' => REQUEST_TIME,
    ))
    ->execute();
  drupal_set_message(t('You have successfully added an annotation.'));
}

/**
 * Function to retrieve notes.
 *
 * Get specific note.
 */
function jdt_user_notes_get($nid) {
  $query = db_select('jdt_user_notes', 'n');
  $query
    ->condition('n.note_id', $nid, '=')
    ->fields('n', array(
        'note_id',
        'article_nid',
        'author_id',
        'note_text',
        'created')
    );
  $result = $query->execute();
  $record = $result->fetchObject();
  return $record;

}

/**
 * Function to retrieve notes.
 *
 * Get notes associated with node.
 */
function jdt_user_notes_gimme($aid) {
  $query = db_select('jdt_user_notes', 'n');
  $query
    ->condition('n.article_nid', $aid, '=')
    ->fields('n', array(
      'note_id',
      'article_nid',
      'author_id',
      'note_text',
      'created')
    );
  $result = $query->execute();
  $record = $result->fetchObject();
  return $record;
}

/**
 * Modify selected note.
 */
function jdt_user_notes_modify($nid, $text, $author){
  $query = db_update('jdt_user_notes')
    ->condition('$note_id', $nid, '=')
    ->fields(array(
      'author_id' => $author,
      'note_text' => $text,
      'created' => REQUEST_TIME,
    ));
  $query->execute();

}


/**
 * Delete selected note.
 */
function jdt_user_notes_delete(){

}