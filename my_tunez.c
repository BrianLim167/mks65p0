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
// note: a < b
void insert_in_order(struct song_node * list, char * name, char * artist) {
	struct song_node * new = (struct song_node *)malloc(sizeof(struct song_node));
	new = new_song(name, artist);
	while (list) {
		print_list(list);
		// if name of current song is < name of new song
		if (strcmp(list->name, new->name) > 0) {
			//printf("list name: %s\n", list->name);
			new->next = list;
		} else if (strcmp(list->name, new->name) < 0) {
			//printf("list name: %s, song to be added name: %s\n", list->name, new->name);
			printf("ho");
			struct song_node * temp;
			temp = list->next;
			list->next = new;
			new->next = temp;
		}
		list = list->next;
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

int main(){
  //struct song_node * table[26];
	struct song_node * starting;
	starting = NULL;
	starting = insert_front(starting, "slow dancing in a burning room","john mayer");
	printf("Printing list 1\n");
	print_list(starting);
	starting = insert_front(starting, "don't stop believing","journey");
	printf("Printing list 2 \n");
	print_list(starting);
	//printf("%d\n",strcmp("slow dancing in a burning room", "don't stop believing"));
	insert_in_order(starting, "burning up","jonas brothers");
	printf("Printing list 3\n");
	print_list(starting);

  return 0;
}
