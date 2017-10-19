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

int main();
