/******************************
 * Program: list.c
 * Author: claire cahill
 * Date: 06/09/2017
 * Description: implements all functions
 * for a linked list in c
 * Input: string of []{}()
 * Output: accepted or rejected message
 * ****************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************
 * Function: main
 * Description: initializes list, 
 * calls mini compiler, deletes list
 * Parameters: none
 * Pre-Conditions: mini_compiler.c must exist
 * Post-Conditions: list is freed from memory
 * **************************/

int main(){

   struct list l;
   init(&l);

   //second part of assignment
   mini_compiler(&l);

   delete(&l);
}

/*****************************
 * Function: init
 * Description: initializes list
 * Parameters: struct list *l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: struct returned as null
 * **************************/

void init(struct list *l){

   l->head = NULL;
   l->tail = NULL;
}

/*****************************
 * Function: size
 * Description: counts the number of nodes in the list
 * Parameters: struct list l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: none
 * **************************/

int size(struct list l){

   struct node *iter;
   iter = l.head;
   int counter = 0;
   if(l.head == NULL){
      counter = 0;
   }
   else if(l.head != NULL){
      while(iter != NULL){
	 counter++;
	 iter = iter->next;
      }
   }
   return counter;
}

/*****************************
 * Function: print
 * Description: prints contents of list
 * Parameters: struct list l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: none
 * **************************/

void print(struct list l){

   struct node *iter;
   iter = l.head;
   if(l.head == NULL){
      printf("List is empty.\n");
   }
   while(iter != NULL){
      printf("List value: %d\n", iter->val);
      iter = iter->next;   
   }
}

/*****************************
 * Function: push_front
 * Description: adds a node to the front of the list
 * Parameters: struct list l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: list exists with new head
 * **************************/

void push_front(struct list *l, int num){

   struct node *iter;
   iter = (struct node*) malloc(sizeof(struct node));
   struct node *temp;
   temp = (struct node*) malloc(sizeof(struct node));
   int num_nodes = size(*l);
   if(l->head == NULL){  					//condition if there are no nodes in the list
      iter->val = num;
      l->head = iter;						//sets head and tail to same val
      iter->next = NULL;
      l->tail = iter;
   }
   else if(num_nodes == 1){
      temp->val = num;
      temp->next = l->head;
      l->head = temp;
   }
   else{
      iter = l->head;      					//saves list in iter
      iter->next = l->head->next;//nothing here yet!!
      iter = iter->next;
      temp->val = num;
      while(iter != NULL){
	 iter = iter->next;
	 temp->next = iter;
	 if(iter->next == NULL){
	    l->tail->val = iter->val;
	    l->tail->next == NULL; 				//creates tail in list
	    break;
	 }
      }
      l->head = temp;						//creates new list, with a new head 
   }

   free(temp);
   free(iter);
}

/*****************************
 * Function: push_back
 * Description: new node added to back of list
 * Parameters: struct list l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: list exists with new tail
 * **************************/

void push_back(struct list *l, int num){

   struct node *iter;
   iter = (struct node*) malloc(sizeof(struct node));
   iter->val = num;
   if(l->head == NULL){  					//condition if there are no nodes in the list
      l->head = iter;					      //sets head and tail to same val
      iter->next = NULL;
      l->tail = iter;
   }
   else{
      l->tail->next = iter;
      l->tail = iter;					//changes tail value of list
      l->tail->next = NULL;
   }

   //free(iter);
}

/*****************************
 * Function: front
 * Description: prints the front value of the list
 * Parameters: struct list l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: none
 * **************************/

int front(struct list l){

   printf("Front value: %d\n", l.head->val);
   return l.head->val;
}

/*****************************
 * Function: back
 * Description: prints the back value of the list
 * Parameters: struct list l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: none
 * **************************/

int back(struct list l){

   printf("Back value: %d\n", l.tail->val);
   return l.tail->val;
}

/*****************************
 * Function: pop_back
 * Description: removes the value at the back of the list
 * Parameters: struct list l
 * Pre-Conditions: struct must exist 
 * Post-Conditions: list has new tail value
 * **************************/

int pop_back(struct list *l){

   int value = 0;
   struct node *iter;
   int num_nodes = size(*l);
   iter = (struct node*) malloc(sizeof(struct node));
   if(l->head == NULL){					//checks if list is null
      printf("List is null\n");
   }
   else{
      iter = l->head;
      if(num_nodes == 1){ 				//checks if there is only one node
	 value = l->head->val;
	 l->head = NULL;
	 l->tail = NULL;
	 return value;
      }
      while(iter->next->next != NULL){
	 iter = iter->next;
      }
      if(iter->next->next == NULL){
	 l->tail = iter;
	 l->tail->next = NULL;
      }
   }

   return value;
}

/*******************************
 * Function: remove_front
 * Description: removes node at the front of the list
 * Parameters: struct list l
 * Pre-Conditions: list struct must exist
 * Post-Conditions: list exists with new head
 * ******************************/

int remove_front(struct list *l){

   int value = 0;
   struct node *iter;
   iter = (struct node*) malloc(sizeof(struct node));
   if(l->head == NULL){					//checks if list is null
      printf("List is null\n");
   }
   value = l->head->val;
   if(l->head->next != NULL){
      iter = l->head->next;
      l->head = iter;
   }
   else{
      l->head = NULL;
      l->tail = NULL;
   }

   return value;
}

/*******************************
 * Function: empty
 * Description: returns 0 is list is not empty
 * returns 1 is list is empty
 * Parameters: struct list l
 * Pre-Conditions: list struct must exist
 * Post-Conditions: none
 * ******************************/

int empty(struct list l){

   int num_nodes = size(l);
   if(num_nodes > 0){
      return 0;
   }
   else if(num_nodes == 0){
      return 1;
   }
}

/*******************************
 * Function: delete
 * Description: deletes all nodes from list
 * Parameters: struct list l
 * Pre-Conditions: list struct must exist
 * Post-Conditions: list head and tail set to NULL
 * ******************************/

void delete(struct list *l){

   int check = empty(*l);
   if(empty == 0){
      free(l);
      l->head = NULL;
      l->tail = NULL;
   }
}

