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
function jdt_user_notes_create($nid, $note_text, $author_id, $op) {
  switch ($op) {
    case "insert":
      $query = db_insert('jdt_user_notes')
        ->fields(array(
          'article_nid' => $nid,
          'author_id' => $author_id,
          'note_text' => $note_text,
          'created' => REQUEST_TIME,
        ))
        ->execute();
      break;

    case "edit":

      break;

    default:
      break;
  }
}

/**
 * Function to retrieve notes.
 *
 * Get notes associated with node.
 */
function jdt_user_notes_get($nid) {
  if ($node_type == "jdt_article") {
    $query = db_select('jdt_user_notes', 'n');
    $query->join('field_data_body', 'b', 'b.entity_id = b.entity_id');
    $query
        ->fields('n', array('nid', 'title'))
        ->condition('n.type', 'node')
        ->orderBy('n.created', 'DESC')
        ->addTag('node_access');
  }
}

function jdt_user_notes_modify() {

}

function jdt_user_notes_delete(){

}