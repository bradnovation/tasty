<?php
/**
 * Created by PhpStorm.
 * User: BradleyAppnovation
 * Date: 2/27/2014
 * Time: 10:25 AM
 */


/**
 * API Stuff
 * Create, Read, Update/Modify & Delete
 * in a "helpers .inc"
 */

function jdt_user_notes_create($nid, $uid, $note_text) {

    $query = db_insert('jdt_user_notes')
        ->fields(array(
            'article_id' => $nid,
            'author_id' => $uid,
            'note_text' => $note_text
        ))
        ->execute();

}

function jdt_user_notes_get($nid) {
    if ($node_type == "jdt_article"){
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