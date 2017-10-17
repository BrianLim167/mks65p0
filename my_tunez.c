#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_tunez.h"

void add_to_table(struct song_node * table,
		  struct song_node * song){
  //insert_front( table[ (song->name)[0] - 'a' ], song );
}

struct song_node * new_song(char * name, char * artist){
  struct song_node * new = (struct song_node *) malloc( sizeof(struct song_node) );
  strcpy(new->name, name);
  strcpy(new->artist, artist);
  return new;
}

struct song_node * insert_front(struct song_node * list,
				struct song_node * song){
  song->next = list;
  return song;
}

void song_to_string(struct song_node * song){
  chr ans[] =;
  song->name song->artist;
}

int main(){
  struct song_node * table[26];

  print_song(new_song("vfbn","auietyvgie"));
  
  return 0;
}
