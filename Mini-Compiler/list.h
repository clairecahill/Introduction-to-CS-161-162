#ifndef LIST_H
#define LIST_H

struct node{
   int val;
   struct node *next;
};

struct list{
   struct node *head;
   struct node *tail;
};

void init(struct list *);
int size(struct list);
void print(struct list);
void push_front(struct list *, int);
void push_back(struct list *, int);
int front(struct list);
int back(struct list);
int pop_back(struct list *);
int remove_front(struct list *);
int empty(struct list);
void delete(struct list *);

#endif
