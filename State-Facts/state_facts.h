
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>

struct county {
   string name;
   string *city;
   int cities;
   int population;
   float avg_income;
   float avg_house;
};

struct state {
   string name;
   struct county *c;
   int counties;
   int population;
};

bool is_valid_arguments(char**, int);
state * create_states(int);
void get_state_data(state *, int, ifstream &);
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
void print_stats(state *, county *, int, int);
char *print_or_save(state *, int, ifstream &);
void largest_state_pop(state *, int, char *, ofstream &);
void largest_county_pop(state *, int, char *, ofstream &);
void county_income(state *, int, char *, ofstream &);
void average_house(state *, int, char *, ofstream &);
void sort_state_names(state *, int, char *, ofstream &);
void sort_state_population(state *, int, char *, ofstream &);
void sort_county_population(state *, int, char *, ofstream &);
void delete_info(state **, int);
