struct song_node{
  char name[256];
  char artist[256];
  struct song_node * next;
};

void add_to_table(struct song_node * table,
		  struct song_node * song);

struct song_node * new_song(char * name, char * artist);

struct song_node * insert_front(struct song_node * list, char * name, char * artist);

void print_song(struct song_node * song);

void print_list(struct song_node * start);

struct song_node * insert_in_order(struct song_node * list, char * name, char * artist);
<<<<<<< HEAD
=======

struct song_node * find_song_with_name(struct song_node * list, char * name, char * artist)
>>>>>>> 0276c0088bff4e116134b0c319034824c06ccc59

int main();
