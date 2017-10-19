#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_tunez.h"

/* void add_to_table(struct song_node * table,
		  struct song_node * song){
  //insert_front( table[ (song->name)[0] - 'a' ], song );
} */

// insert new song - helper function for inserting node at front/in order
struct song_node * new_song(char * name, char * artist){
  struct song_node * new = (struct song_node *) malloc( sizeof(struct song_node) );
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  return new;
}

// insert node at front
struct song_node * insert_front(struct song_node * list, char * name, char * artist) {
	struct song_node * new = (struct song_node *)malloc(sizeof(struct song_node));
	new = new_song(name, artist);
  new->next = list;
  return new;
}

// insert node in alphabetical order (based on song, then artist)
// note: a < b, strcmp(str1, str2) --> str1 - str2
// list-> name = don't stop believing
// new->name = burning up
struct song_node * insert_in_order(struct song_node * list, char * name, char * artist) {
	struct song_node * new = (struct song_node *)malloc(sizeof(struct song_node));
	new = new_song(name, artist);
  int inserted_in_front = 0;
	if (strcmp(list->name, new->name) > 0) {
		//printf("hi!");
		new->next = list;
    inserted_in_front = 1;
	}
  //else if (strcmp(list->name, new->name) < 0) {
	else {
    struct song_node * before;
    before = list;
    struct song_node * after;
    after = list->next;
    while (after->next != NULL && strcmp(before->name, new->name) < 0) {
      //printf("Curr: %s, Prev: %s, Next: %s\n", new->name, before->name, after->name);
      before = after;
      after = after->next;
      //printf("After!: %s\n", after->name);
    }
    before->next = new;
    new->next = after;
    //printf("2Curr: %s, Prev: %s, Next: %s\n", new->name, before->name, after->name);
	}
  if (inserted_in_front == 1) {
    return new;
  } else {
    return list;
  }
}

/* void song_to_string(struct song_node * song){
  chr ans[] =;
  song->name song->artist;
} */

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
	printf("%d\n",strcmp("don't stop believing", "burning up"));
	starting = insert_in_order(starting, "burning up","jonas brothers");
	printf("Printing list 3\n");
	print_list(starting);
  starting = insert_in_order(starting, "in your atmosphere","john mayer");
	printf("Printing list 4\n");
	print_list(starting);
  search = find_song_with_name(starting, "in your atmosphere", "john mayer");
  printf("Yay, you found the song you were looking for: %s - %s\n", search->name, search->artist);

  return 0;
}
