#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "my_tunez.h"



// insert new song - helper function for inserting node at front/in order
struct song_node * new_song(char * artist, char * name){
  struct song_node * new = (struct song_node *) malloc( sizeof(struct song_node) );
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
  return new;
}

// insert node in alphabetical order (based on song, then artist)
// note: a < b
struct song_node * insert_in_order(struct song_node * list, char * artist, char * name) {

  struct song_node * front = list;

  struct song_node * new = new_song(artist, name);
  struct song_node * prev = NULL;

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
  while (list) {
    if (!strcmp(list->name,name) && !strcmp(list->artist,artist)){
      return list;
    }
    list = list->next;
  }
  return NULL;
}

struct song_node * find_artist(struct song_node * list, char * artist) {
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

struct song_node * free_list(struct song_node * node){
  struct song_node * front = node;
  struct song_node * money;
  while (node){
    money = node;
    node = node->next;
    free(money);
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

void remove_song(struct song_node * list, char * artist, char * name) {
  struct song_node * to_be_removed = new_song(artist, name);
  if (length(list) > 1) {
    while (list->next) {
      if ((strcmp((list->next)->artist, to_be_removed->artist) == 0) && (strcmp((list->next)->name, to_be_removed->name) == 0)) {
        list->next = (list->next)->next;
        return;
      }
    list = list->next;
    }
  } else if (length(list) == 1) {
    printf(":(\n");
    list = NULL;
  }
  else {
    printf("No songs to remove!\n");
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
  int i;
  for (i = 0; i < 26; i++){
    if (length(table[i]) > 0) {
      print_list(table[i]);
    }
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

void delete(struct song_node ** table, char * artist, char * name) {
  remove_song(search_artist(table, artist), artist, name);
  print(table);
  /*struct song_node * to_be_removed = new_song(artist, name);
  struct song_node * list = search_artist(table, artist);
  while (list->next) {
    if ((strcmp((list->next)->artist, to_be_removed->artist) == 0) && (strcmp((list->next)->name, to_be_removed->name) == 0)) {
      list->next = (list->next)->next;
      printf("hooray!\n");
      return;
    }
    list = list->next;
  }
  //printf("Song name: %s, Artist name: %s", list->name, list->artist); */
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

///////////////////////////////////////
// MAIN
///////////////////////////////////////

int main(){
  srand(time(NULL));

  struct song_node * starting;
  starting = NULL;
  struct song_node * search;
  search = NULL;
  starting = insert_front(starting, "the russ liquid test","1984");
  //printf("Printing list 1\n");
  //print_list(starting);
  starting = insert_front(starting, "stephen walking","turtle town");
  //printf("Printing list 2 \n");
  //print_list(starting);

  printf("\n");

  //printf("%d\n",strcmp("the louder the better - too strong", ""));
  starting = insert_in_order(starting, "the louder the better","too strong");
  printf("Printing list 3\n");
  print_list(starting);
  starting = insert_in_order(starting, "stephen walking","the difference between us and the aliens");
  printf("Printing list 4\n");
  print_list(starting);
  search = find_song(starting, "stephen walking", "the difference between us and the aliens");
  printf("Yay, you found the song you were looking for:\n");
  print_song(search);
  printf("\n");

  printf("\nFinding \"stephen walking - turtle town\"\n");
  print_song(find_song(starting,"stephen walking","turtle town"));
  printf("\n");

  printf("Finding \"stephen walking\"\n");
  print_list(find_artist(starting,"stephen walking"));

  printf("\nSome random songs:\n");
  int i;
  for (i=0 ; i<3 ; i++){
    printf("\t");
    print_song(random_song(starting));
    printf("\n");
  }

  printf("printing all songs\n");
  print_list(starting);
  remove_song(starting, "the louder the better","too strong");
  remove_song(starting, "the russ liquid test","1984");
  printf("printing all songs\n");
  print_list(starting);

  //free_list(starting);


  //////////////////////////--TABLE TESTS--//////////////////////
  printf("\n------------------TABLE TESTS------------------\n\n");

  struct song_node * many_songs[] = { // FREEEEE MEEEEE
    //       artist                  name
    new_song("the louder the better","too strong"                               ),
    new_song("stephen walking",      "turtle town"                              ),
    new_song("lafa taylor",          "already found"                            ),
    new_song("stephen walking",      "the difference between us and the aliens" ),
    new_song("the russ liquid test", "1984"                                     ),/*
    new_song("",   ""                  ),
    new_song("",   ""                  ),
    new_song("",   ""                  ),
    new_song("",   ""                  ),
    new_song("",   ""                  ),
    new_song("",   ""                  ),*/

  };

  struct song_node * table[26];

  for (i=0 ; i<26 ; i++){
    table[i] = NULL;
  }

  for (i=0 ; i<sizeof(many_songs)/sizeof(many_songs[0]) ; i++){
  //for (i=0 ; i<5 ; i++){
    add(table, many_songs[i]->artist, many_songs[i]->name);
  }

  //add(table, "abc", "def");

  //for (i=0 ; i<26 ; i++){
    //printf("%u - ",table[i]);
  //}
  //printf("\n" );

  printf("\n~~TABLE~~\n");
  print(table);

  printf("\n~start with 't'~\n");
  print_letter(table, 't');

  printf("\n~start with 's'~\n");
  print_letter(table, 's');

  printf("\n~Artist: the louder the better~\n");
  print_artist(table, "the louder the better");

  printf("\n~Artist: stephen walking~\n");
  print_artist(table, "stephen walking");


  printf("testing shuffle: \n");
  shuffle(table);

  printf("~~TABLE~~\n");
  print(table);
  printf("testing delete\n");
  delete(table,"lafa taylor","already found");
  //printf("~~TABLE~~\n");
  //print(table);


  return 0;
}
