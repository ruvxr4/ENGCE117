#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentnode {
   
    char name[20];

    int age;    

    char sex;

    float gpa;

    struct studentnode *next;

    struct studentnode *back;

}typedef stnode;


void ShowAll(stnode *walk);

stnode* AddNode(stnode **start, char name[], int age, char sex, float gpa);

void InsNode(stnode **now, stnode **start, char name[], int age, char sex, float gpa);

void DelNode(stnode **now, stnode **start);

void GoBack(stnode **now);

void GoNext(stnode **now);

int main(){

    stnode *start, *now;

    start = NULL;

    now = AddNode(&start, "one", 6, 'm', 3.11); ShowAll(start);

    now = AddNode(&start, "two", 8, 'f', 3.22); ShowAll(start);

    InsNode(&now, &start, "three", 10, 'm', 3.33); ShowAll(start);

    InsNode(&now, &start, "four", 12, 'f', 3.44); ShowAll(start);

    GoBack(&now); 

    DelNode(&now, &start); ShowAll(start); 
    
    DelNode(&now, &start); ShowAll(start);
   
    DelNode(&now, &start); ShowAll(start);

    return 0;
}

void ShowAll(stnode *walk) {
    
    stnode *temp = walk; 

    while (temp != NULL) {

        printf("[%s] ", temp->name);

        temp = temp->next;

    }

    printf("\n");
}

stnode* AddNode(stnode **start, char name[], int age, char sex, float gpa) {
   
    stnode *newnode = (stnode*)malloc(sizeof(stnode));

    strcpy(newnode->name, name);

    newnode->age = age;

    newnode->sex = sex;

    newnode->gpa = gpa;

    newnode->next = NULL;

    newnode->back = NULL;
    
    if (*start == NULL) {

        *start = newnode;

        return newnode;
    }
    
    stnode *temp = *start;

    while (temp->next != NULL) {

        temp = temp->next;
    }
    
    temp->next = newnode;

    newnode->back = temp;
    
    return newnode; 
}


void InsNode(stnode **now, stnode **start, char name[], int age, char sex, float gpa) {
    
    stnode *newnode = (stnode*)malloc(sizeof(stnode));

    strcpy(newnode->name, name);

    newnode->age = age;

    newnode->sex = sex;

    newnode->gpa = gpa;

    newnode->next = *now;

    if (*now != NULL) {

        newnode->back = (*now)->back;
        
        if ((*now)->back != NULL) {

            (*now)->back->next = newnode;

        } else {
            
            *start = newnode;

        }
        
        (*now)->back = newnode;

    } else {

        newnode->back = NULL;
       
        if (*start == NULL) *start = newnode;

    }

    *now = newnode; 
}

void GoBack(stnode **now) {

    if (*now != NULL && (*now)->back != NULL) {

        *now = (*now)->back;
    }
}


void DelNode(stnode **now, stnode **start) {

    stnode *temp;

    if (*now == NULL) return; 

    temp = *now;
    
    if (temp->back != NULL) {

        temp->back->next = temp->next;

    } else {
        
        *start = temp->next;
    }
    
   
    if (temp->next != NULL) {

        temp->next->back = temp->back;
    }
    
    if (temp->next != NULL) {

        *now = temp->next; 

    } else if (temp->back != NULL) {

        *now = temp->back; 

    } else {

        *now = NULL; 

        *start = NULL; 
    }
    
    free(temp);
}

void GoNext(stnode **now) {

    if (*now != NULL && (*now)->next != NULL) {

        *now = (*now)->next;

    }
}