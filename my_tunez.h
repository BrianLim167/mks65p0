struct song_node{
  char name[256];
  char artist[256];
  struct song_node * next;
};

void make_lower(char * str);

void add_to_table(struct song_node * table,
		  struct song_node * song);

struct song_node * new_song(char * name, char * artist);

struct song_node * insert_front(struct song_node * list, char * name, char * artist);

struct song_node * insert_in_order(struct song_node * list, char * name, char * artist);

struct song_node * find_song_with_name(struct song_node * list, char * name, char * artist);


struct song_node * find_song(struct song_node * list, char * name, char * artist);
struct song_node * find_artist(struct song_node * list, char * artist);

int length(struct song_node * list);
struct song_node * random_song(struct song_node * list);

struct song_node * free_list(struct song_node * node);

void print_song(struct song_node * song);

void print_list(struct song_node * start);

int main();
