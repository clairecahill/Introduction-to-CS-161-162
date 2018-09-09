#include "mini_compiler.h"

/*******************************
 * Function: mini_compiler
 * Description: checks three conditions of the input statement
 * Parameters: struct list l
 * Pre-Conditions: list struct must exist
 * Post-Conditions: none
 * ******************************/

void mini_compiler(struct list *l){

   int i;
   char *message = get_message();
   int size = strlen(message);

   if(message[0] != '{' && message[0] != '(' && message[0] != '['){
      printf("Rejected message.\n");
      exit(0);
   }

   for(i = 0; i < size; i++){
      check_opening(message, l, i);
      check_closing(message, l, i);
   }

   int a = empty(*l);
   if(a == 0){
      printf("Rejected message.\n");
   }
   else if(a == 1){ 
      printf("Accepted message.\n");
   }

   free(message);
}

/*******************************
 * Function: get_message
 * Description: gets input from user
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: message stored in c string
 * ******************************/

char* get_message(){

   char *input = (char*) malloc(sizeof(char) * 300);
   printf("Enter string: \n");
   scanf("%s", input);

   return input;
}

/*******************************
 * Function: check_opening
 * Description: pushes value onto the front of the list
 * based on what character it is
 * Parameters: struct list l, message, i
 * Pre-Conditions: list struct must exist
 * Post-Conditions: list exists with different values
 * ******************************/

void check_opening(char *message, struct list *l, int i){

   if(message[i] == '['){
      push_back(l, 0);
   }
   else if(message[i] == '{'){
      push_back(l, 1);
   }
   else if(message[i] == '('){
      push_back(l, 2);
   }
}

/*******************************
 * Function: check_closing
 * Description: pops value off the end of the list
 * based on what character it is
 * Parameters: struct list l, message, i
 * Pre-Conditions: list struct must exist
 * Post-Conditions: list exists with different values
 * ******************************/

void check_closing(char *message, struct list *l, int i){

   if(message[i] == ']'){
      if(l->tail->val == 0){
	 pop_back(l);
      }
      else{
	 printf("Rejected message.\n");
	 exit(0);
      }
   }
   else if(message[i] == '}'){
      if(l->tail->val == 1){
	 pop_back(l);
      }
      else{
	 printf("Rejected message.\n");
	 exit(0);
      }
   }
   else if(message[i] == ')'){
      if(l->tail->val == 2){
	 pop_back(l);
      }
      else{
	 printf("Rejected message.\n");
	 exit(0);
      }
   }
}

