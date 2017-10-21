#include "my_tunez.c"

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
  print_list(starting);

  printf("\n");
  starting = insert_front(starting, "stephen walking","turtle town");
  print_list(starting);

  printf("\n");
  starting = insert_in_order(starting, "the louder the better","too strong");
  print_list(starting);

  printf("\n");
  starting = insert_in_order(starting, "stephen walking","the difference between us and the aliens");
  print_list(starting);

  printf("\n");
  search = find_song(starting, "stephen walking", "the difference between us and the aliens");
  printf("\n");
  //printf("Yay, you found the song you were looking for:\n");
  //print_song(search);

  printf("\n");
  printf("Finding \"stephen walking - turtle town\"\n");
  print_song(find_song(starting,"stephen walking","turtle town"));
  printf("\n");

  printf("\nFinding \"stephen walking\"\n");
  print_list(find_artist(starting,"stephen walking"));

  printf("\nTesting random song function:\n");
  int i;
  for (i=0 ; i<3 ; i++){
    printf("\t");
    print_song(random_song(starting));
    printf("\n");
  }
  printf("\n");
  printf("Printing all songs\n");
  print_list(starting);
  printf("\n\n");
  remove_song(starting, "the louder the better","too strong");
  printf("\n\n");
  remove_song(starting, "the russ liquid test","1984");
  printf("\n\n");
  printf("Printing all songs\n");
  print_list(starting);

  printf("\nFreeing list:\n");
  starting = free_list(starting);


  //////////////////////////--TABLE TESTS--//////////////////////
  printf("\n\n\n------------------TABLE TESTS------------------\n\n");

  struct song_node * many_songs[] = {
    //       artist                  name
    new_song("the louder the better","too strong"                               ),
    new_song("stephen walking",      "turtle town"                              ),
    new_song("lafa taylor",          "already found"                            ),
    new_song("stephen walking",      "the difference between us and the aliens" ),
    new_song("the russ liquid test", "1984"                                     ),
    new_song("sim gretina",          "super special samantha"                   ),
    new_song("sim gretina",          "ichiba"                                   ),
    new_song("shook",                "love for you"                             ),
    new_song("stereocool",           "continuum"                                ),
    new_song("shook",                "milestones"                               ),
    new_song("saib",                 "spring waltz"                             ),
    new_song("shook",                "cloud symphony"                           ),/*
    new_song("",   ""                  ),
    new_song("",   ""                  ),
    new_song("",   ""                  ),
    new_song("",   ""                  ),
    new_song("",   ""                  ),
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

  printf("\nPrinting song library: \n");
  print(table);

  printf("\nAll entries under \"t\":\n");
  print_letter(table, 't');

  printf("\nAll entries under \"s\":\n");
  print_letter(table, 's');

  printf("\nAll songs by \"the louder the better\":\n");
  print_artist(table, "the louder the better");

  printf("\nAll songs by \"stephen walking\":\n");
  print_artist(table, "stephen walking");


  printf("\nShuffle songs: \n");
  shuffle(table);

  printf("\nPrinting original song library: \n");
  print(table);
  printf("\nTesting delete song: \n");
  delete_song(table,"the russ liquid test","1984");
  printf("\n\nNew song library: \n");
  print(table);


  /*for (i=0 ; i<sizeof(many_songs)/sizeof(many_songs[0]) ; i++){
    //for (i=0 ; i<5 ; i++){
    free(many_songs[i]);
  }*/
  /*for (i=0 ; i<26 ; i++){
    //if (table[i])
    table[i] = free_list(table[i]);

  }*/
  //free_list(table[11]);
  //print_list(table[11]);
  printf("\nDeleting all songs:\n");
  delete_all_songs(table);
  printf("Printing table\n");
  print(table);

  return 0;
}
