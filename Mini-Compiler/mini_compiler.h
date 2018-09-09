#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mini_compiler(struct list *l);
char* get_message();
int* change_message(char*);
void check_opening(char*, struct list*, int);
void check_closing(char*, struct list*, int);
void check_size(struct list);

