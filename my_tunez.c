#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_tunez.h"

/* void add_to_table(struct song_node * table,
struct song_node * song){
//insert_front( table[ (song->name)[0] - 'a' ], song );
} */

void make_lower(char * str){
  return; // FIX ME ! FIX ME ! FIX ME ! FIX ME ! FIX ME ! FIX ME !
/*
  char ans[strlen(str)+1];
  int i=0;
  while (str[i]){
    ans[i] = tolower(str[i]);
    i++;
  }
  strcpy(str,ans);
  ans[strlen(str)] = 0;*/
}

// insert new song - helper function for inserting node at front/in order
struct song_node * new_song(char * name, char * artist){
  struct song_node * new = (struct song_node *) malloc( sizeof(struct song_node) );
  make_lower(name);
  make_lower(artist);
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  new->next = NULL;
  return new;
}

// insert node at front
struct song_node * insert_front(struct song_node * list, char * name, char * artist) {
  struct song_node * new = new_song(name, artist);
  new->next = list;
  return new;
}

// insert node in alphabetical order (based on song, then artist)
// note: a < b
struct song_node * insert_in_order(struct song_node * list, char * name, char * artist) {
  struct song_node * front = list;

  struct song_node * new = new_song(name, artist);
  struct song_node * prev = NULL;

  while (list) {
    print_list(list);
    // if name of current song is > name of new song, new song belongs right before
    // current song
    if (strcmp(list->name, new->name) > 0) {
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

struct song_node * find_song(struct song_node * list, char * name, char * artist) {
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

void print_list(struct song_node * start) {
  while (start) {
    printf("%s - %s | ", start->name, start->artist);
    start = start->next;
  }
  printf("\n");
}

struct song_node * find_song_with_name(struct song_node * list, char * name, char * artist) {
  while (list && (strcmp(list->name, name) != 0) && (strcmp(list->artist, artist) != 0)) {
    list = list->next;
  }
  //printf("Good news everyone! %s - %s has been found!\n", list->name, list->artist);
  return list;
}

int main(){
  //struct song_node * table[26];
	struct song_node * starting;
	starting = NULL;
  struct song_node * search;
	search = NULL;
	starting = insert_front(starting, "slow dancing in a burning room","john mayer");
	//printf("Printing list 1\n");
	//print_list(starting);
	starting = insert_front(starting, "don't stop believing","journey");
	//printf("Printing list 2 \n");
	//print_list(starting);

  printf("\nFinding \"don't stop believing - journey\"\n");
  print_list(find_song(starting,"don't stop believing","journey"));

  printf("Finding \"journey\"\n");
  print_list(find_artist(starting,"journey"));

  printf("\n");

	printf("%d\n",strcmp("don't stop believing", "burning up"));
	starting = insert_in_order(starting, "burning up","jonas brothers");
	printf("Printing list 3\n");
	print_list(starting);
  starting = insert_in_order(starting, "in your atmosphere","john mayer");
	printf("Printing list 4\n");
	print_list(starting);
  search = find_song_with_name(starting, "in your atmosphere", "john mayer");
  printf("Yay, you found the song you were looking for: %s - %s\n", search->name, search->artist);

  free_list(starting);

  return 0;
}
