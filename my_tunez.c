#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_tunez.h"



// insert new song - helper function for inserting node at front/in order
struct song_node * new_song(char * artist, char * name){
  struct song_node * new = (struct song_node *)malloc(sizeof(struct song_node) );
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = NULL;
  return new;
}

///////////////////////////////////////
// SONG LIST FUNCTIONS
///////////////////////////////////////

// insert node at front
struct song_node * insert_front(struct song_node * list, char * artist, char * name) {
  struct song_node * new = new_song(artist, name);
  new->next = list;
  printf("inserting in front: %s - %s:\n",new->artist,new->name);
  return new;
}

// insert node in alphabetical order (based on song, then artist)
// note: a < b
struct song_node * insert_in_order(struct song_node * list, char * artist, char * name) {

  struct song_node * front = list;

  struct song_node * new = new_song(artist, name);
  struct song_node * prev = NULL;
  printf("inserting in alphabetical order: %s - %s:\n",new->artist,new->name);

  if (!list) {
    return new;
  }

  while (list) {
    //print_list(list);
    // if name of current artist is > name of new artist, new song belongs right before
    // current song
    if ( ( strcmp(list->artist, new->artist) > 0 ) ||
  ( strcmp(list->artist, new->artist) == 0 && strcmp(list->name, new->name) > 0 ) ) {
      //printf("list name: %s\n", list->name);
      new->next = list;
      if (prev) {
        prev->next = new;
        return front;
      }
      // prev does not exist, which means new song must be the frontmost node
      return new;
    }
    prev = list;
    list = list->next;
  }

  // while loop didn't find a place for new song, so it must belong at the end
  if (prev) {
    prev->next = new;
  }
  return front;
}

struct song_node * find_song(struct song_node * list, char * artist, char * name) {
  printf("Searching for %s - %s\n", artist,name);
  while (list) {
    if (!strcmp(list->name,name) && !strcmp(list->artist,artist)){
      printf("Good news everyone! %s - %s has been found!\n",list->artist,list->name);
      return list;
    }
    list = list->next;
  }
  return NULL;
}

struct song_node * find_artist(struct song_node * list, char * artist) {
  printf("Searching for songs by %s\n", artist);
  while (list) {
    if (!strcmp(list->artist,artist)){
      return list;
    }
    list = list->next;
  }
  return NULL;
}

int length(struct song_node * list){
  int len = 0;
  while (list){
    len++;
    list = list->next;
  }
  return len;
}

struct song_node * random_song(struct song_node * list){
  int r = rand();
  int ind = rand() % length(list);
  int i;
  for (i=0 ; i!=ind ; i++){
    list = list->next;
  }
  return list;
}

/* void song_to_string(struct song_node * song){
chr ans[] =;
song->name song->artist;
} */

struct song_node * free_list(struct song_node * front) {
  struct song_node * temp;
  while (front) {
    temp = front->next;
    free(front);
    front = temp;
  }
  return front;
}

void print_song(struct song_node * song ) {
  if (song){
    printf("%s - %s ||| ", song->artist, song->name);
  } /*else {
    printf("NULL ||| ");
  } */
}

void print_list(struct song_node * start) {
  while (start) {
    print_song(start);
    start = start->next;
  }
  printf("\n");
}

struct song_node * remove_song(struct song_node * list, char * artist, char * name) {
  printf("Removing %s - %s",artist,name);
  struct song_node * front = list;
  if (length(list) > 1) {
    if ((strcmp(artist, list->artist) == 0) && (strcmp(name, list->name)==0)) {
      struct song_node * temp = list->next;
      free(list);
      return temp;
    }
    while (list->next) {
      if ((strcmp((list->next)->artist, artist) == 0) && (strcmp((list->next)->name, name) == 0)) {
        struct song_node * temp = list->next;
        list->next = (list->next)->next;
        free(temp);
        return front;
      }
      list = list->next;
    }
    return list;
  }
  else if (length(list) == 1) {
      if ((strcmp(artist, list->artist) == 0 ) && (strcmp(name, list->name)==0)) {
        free(list);
        return NULL;
      }
      return list;
    }
  else {
    return NULL;
  }
}


/*
struct song_node * find_song_with_name(struct song_node * list, char * artist, char * name) {
  while (list && (strcmp(list->name, name) != 0) && (strcmp(list->artist, artist) != 0)) {
    list = list->next;
  }
  //printf("Good news everyone! %s - %s has been found!\n", list->name, list->artist);
  return list;
}
*/

///////////////////////////////////////
// SONG TABLE FUNCTIONS
///////////////////////////////////////

void add(struct song_node ** table, char * artist, char * name){
  table[ (artist)[0] - 'a' ] = insert_in_order( table[ (artist)[0] - 'a' ] , artist, name );
}

struct song_node * search(struct song_node ** table, char * artist, char * name){
  return find_song(table[artist[0] - 'a'], artist, name);
}

struct song_node * search_artist(struct song_node ** table, char * artist){
  return find_artist(table[artist[0] - 'a'], artist);
}

void print(struct song_node ** table){
  char i;
  for (i = 0; i < 26; i++){
    printf("%c: ",'a'+i);
    print_list(table[i]);
  }
}

void shuffle(struct song_node ** table) {
  int r;
  int counter = 0;
  struct song_node * start;
  start = NULL;
  while (counter !=3){
    r = rand() % 26;
    //printf("value of rand: %d\n",r);
    //printf("length of list at table[%d]: %d\n", r, length(table[r]));
    if (length(table[r]) > 0) {
      start = random_song(table[r]);
      printf("%s - %s ||| \n", start->artist, start->name);
      start = start->next;
      counter++;
    }
  }
}

void delete_song(struct song_node ** table, char * artist, char * name) {
  table[(artist)[0] - 'a'] = remove_song(table[(artist)[0] - 'a'], artist, name);
}

void print_letter(struct song_node ** table, char letter){
  print_list(table[letter - 'a']);
}

void print_artist(struct song_node ** table, char * artist){
  struct song_node * node = search_artist(table, artist);
  while ( node && strcmp(node->artist,artist) == 0 ){
    print_song(node);
    node = node->next;
  }
  printf("\n");
}

void delete_all_songs(struct song_node ** table) {
  int i;
  for (i=0 ; i<26 ; i++){
    //if (table[i])
    table[i] = free_list(table[i]);

  }
}
