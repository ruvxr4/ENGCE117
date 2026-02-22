#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
}typedef stnode ;

class LinkedList {
protected:
    stnode *start, *now; 
public:
    LinkedList();
    ~LinkedList();
    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    void GoFirst();
    void GoLast();
    void ShowAll();
    int FindNode(char n[]);
    stnode *NowNode();
    void EditNode(char n[], int a, char s, float g);
};

LinkedList::LinkedList() {
    start = NULL;
    now = NULL;
}

LinkedList::~LinkedList() {
    stnode *curr = start;
    stnode *next;
    while (curr != NULL) {
        next = curr->next;
        delete curr; 
        curr = next;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    stnode *newNode = new stnode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    if (start == NULL) {
        start = newNode;
        now = newNode;
    } else {
        stnode *curr = start;
        while (curr->next != NULL) { 
            curr = curr->next;
        }
        curr->next = newNode; 
        now = newNode;
    }
}

void LinkedList::DelNode() {

    char n[20];

    printf("Enter Student Name to delete: ");

    scanf("%s", n);

    stnode *curr = start;

    stnode *prev = NULL;

    while (curr != NULL && strcmp(curr->name, n) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {

        printf("Student '%s' not found.\n", n);

        return;
    }

    if (prev == NULL) {

        start = curr->next; 

    } else {

        prev->next = curr->next; 

    }

    if (now == curr) {

        now = start; 

    }

    delete curr;

    printf("Student '%s' deleted successfully.\n", n);

}

void LinkedList::GoNext() {

    if (now != NULL) {

        now = now->next;

    }
}

void LinkedList::GoFirst() {

    now = start;

}

void LinkedList::GoLast() {

    if (start == NULL) {

        now = NULL;

        return;

    }

    stnode *curr = start;

    while (curr->next != NULL) {

        curr = curr->next;

    }

    now = curr;
}

void LinkedList::ShowAll() {

    stnode *curr = start;

    if (curr == NULL) {

        printf("List is empty.\n");

        return;

    }

    printf("\n--- All Students ---\n");

    while (curr != NULL) {

        printf("Name: %-10s | Age: %2d | Sex: %c | GPA: %.2f\n", curr->name, curr->age, curr->sex, curr->gpa);

        curr = curr->next;

    }

    printf("--------------------\n");

}

int LinkedList::FindNode(char n[]) {

    struct studentNode *curr = start;

    while (curr != NULL) {

        if (strcmp(curr->name, n) == 0) {

            now = curr; 

            return 1;

        }

        curr = curr->next;

    }

    return 0; 
}

struct studentNode *LinkedList::NowNode() {

    return now;
}

void LinkedList::EditNode(char n[], int a, char s, float g) {

    if (now != NULL) { 

        strcpy(now->name, n);

        now->age = a;

        now->sex = s;

        now->gpa = g;
    }
}



void EditData(LinkedList *ll);

void AddData(LinkedList *ll);

void FindData(LinkedList *ll);

void readfile(LinkedList *ll);

void writefile(LinkedList *ll);

void RunMenu(LinkedList *ll); 

int main() {

    LinkedList listA;
    
    readfile(&listA);  

    RunMenu(&listA);    

    writefile(&listA);  
    
    return 0;

}

void RunMenu(LinkedList *ll) {

    int menu;

    do {

        printf("\nMenu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");

        scanf("%d", &menu);
        
        switch(menu) {

            case 1 : AddData(ll); break;

            case 2 : EditData(ll); break;

            case 3 : ll->DelNode(); break;

            case 4 : FindData(ll); break;

            case 5 : ll->ShowAll(); break;

            case 0 : printf("exiting program.\n"); break;

            default: printf("invalid menu option.try again later.\n"); break;

        }

    } while(menu != 0); 
}

void AddData(LinkedList *ll) {

    char n[20], s;

    int a;
    
    float g;
    
    printf("Enter Name: "); scanf("%s", n);

    printf("Enter Age: "); scanf("%d", &a);

    printf("Enter Sex (M/F): "); scanf(" %c", &s);

    printf("Enter GPA: "); scanf("%f", &g);
    
    ll->InsNode(n, a, s, g);

    printf("Data added successfully.\n");

}

void EditData(LinkedList *ll) {

    char n[20];

    printf("Enter Student Name to edit: ");

    scanf("%s", n);
    
    if(ll->FindNode(n)) {

        char newN[20], newS;

        int newA;

        float newG;
        
        printf("Student Found! Enter New Data\n");

        printf("Enter New Name: "); scanf("%s", newN);

        printf("Enter New Age: "); scanf("%d", &newA);

        printf("Enter New Sex (M/F): "); scanf(" %c", &newS);

        printf("Enter New GPA: "); scanf("%f", &newG);
        
        ll->EditNode(newN, newA, newS, newG);

        printf("Data edited successfully.\n");

    } else {

        printf("Student '%s' not found.\n", n);

    }
}

void FindData(LinkedList *ll) {

    char n[20];

    printf("Enter Student Name to find: ");

    scanf("%s", n);
    
    if(ll->FindNode(n)) {

        stnode *node = ll->NowNode();

        printf("\n--- Student Info ---\n");

        printf("Name: %s\n", node->name);

        printf("Age: %d\n", node->age);

        printf("Sex: %c\n", node->sex);

        printf("GPA: %.2f\n", node->gpa);

        printf("--------------------\n");

    } else {

        printf("Student '%s' not found.\n", n);
    }
}

void readfile(LinkedList *ll) {

    FILE *fp = fopen("D:\\cpe\\engce117\\student.dat", "r");   

    if(fp == NULL) {

        printf("Note: Data file (D:\\cpe\\engce117\\student.dat) not found. Starting fresh.\n");

        return; 

    }
    
    char n[20], s;

    int a;

    float g;
    
    while(fscanf(fp, "%s %c %d %f", n, &s, &a, &g) != EOF) {

        ll->InsNode(n, a, s, g);

    }

    fclose(fp);

    printf("Data loaded from D:\\cpe\\engce117\\student.dat successfully.\n");

}

void writefile(LinkedList *ll) {
   
    FILE *fp = fopen("D:\\cpe\\engce117\\student.dat", "w");

    if(fp == NULL) {
        
        printf("Can't create file D:\\cpe\\engce117\\student.dat!\n");

        printf("Please make sure the folder 'D:\\cpe\\engce117' exists.\n"); 

        return;
    }

    ll->GoFirst();

    stnode *curr = ll->NowNode();
    
    while(curr != NULL) {

        fprintf(fp, "%s %c %d %f\n", curr->name, curr->sex, curr->age, curr->gpa);

        ll->GoNext();

        curr = ll->NowNode();

    }
    
    fclose(fp);

    printf("\nData saved to D:\\cpe\\engce117\\student.dat successfully.\n");
}