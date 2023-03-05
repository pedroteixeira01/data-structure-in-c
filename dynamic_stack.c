#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct Element {
    int id, consumption, day, month, year; 
    char name[40];
    float unitPrice, totalValue; 
    struct Item *previous;
} element; 

void create(element **top) {
   *top = NULL;
}

int isEmpty(element **top) {
   if(*top == NULL)  
      return TRUE;  
   else  
      return FALSE;  
}

void stackUp(element** top) { 

    int id, consumption, day, month, year;
	char name[40];
	float unitPrice, totalValue;
    element *new;
    new = (element *) malloc(sizeof(element));  

    printf( "Enter the Customer code: ");
    scanf("%d", &id);
    printf( "Enter the Customer's name: ");
    scanf("%s", &name);
    printf( "Enter customer consumption: ");
    scanf("%d", &consumption);
    printf( "Enter the unit value: ");
    scanf("%f", &unitPrice);
    totalValue = unitPrice * (float)consumption;
    printf( "Enter the due date: ");
    scanf("%d", &day);
    printf( "Enter the month of expiration: ");
    scanf("%d", &month);
    printf( "Enter the year of expiration: ");
    scanf("%d", &year);

    new->id = id;
    new->consumption = consumption;
    new->day = day;
    new->month = month;
    new->year = year;
    strcpy(new->name, name);
    new->unitPrice = unitPrice;
    new->totalValue = totalValue;
 
    new->previous = *top; 
	*top = new;
}

void unstack(element **top) {
   element *old;
   old = *top;

   if(isEmpty(top)) { 
        printf("\nEmpty stack \n"); 
   }
   else {
       *top = old->previous;
       free(old);
   }  
}
void showStack(element *top) {
    int i = 0; 
    element *item;
    printf("\n\n Listing...\n\n");
    printf("---------------------------------\n");
    if (isEmpty(&top)) {
        printf ("The stack is empty!\n");
    }
    else { 
        item = top;
        printf("\nItem  Value     active address      previous address\n");
        while(item != NULL) {
            i++;
            printf("Address of Data Stacked in Struct ---- active address: %p previous address: %p \n", item, item->previous);
            printf("[%2d] id -> %2d \n", i, item->id);
            printf("[%2d] name -> %s \n", i, item->name);
            printf("[%2d] consumption -> %.2d \n", i, item->consumption);
            printf("[%2d] Unitary value -> %.2lf \n", i, item->unitPrice);
            printf("[%2d] Total value -> %.2lf \n", i, item->totalValue);
            printf("[%2d] Due date -> %2d/%2d/%2d  \n", i, item->day, item->month, item->year);   
            
            // get previous address
            item = item->previous;
        }
    }
    printf("---------------------------------\n\n\n");
}

void Menu() {
    printf( "\n\nEnter your choice: \n"
        "    1 - Stack element \n"
        "    2 - Unstack \n"
        "    3 - Exit \n"
        "-> ");
}

int main(){

    element *top;
    int flag;

	create(&top);

    Menu();
    scanf("%d", &flag);

    while (flag != 3) {
        switch (flag) {
            case 1: 
                
                stackUp(&top);
                showStack(top);
                break;
            case 2: 
                
    			printf("\nValue of unstacked client code %d", top->id);
    			printf("\nUnstacked name value %s", top->name);
    			printf("\nConsumption value unstacked %d", top->consumption);
    			printf("\nValue of unstacked unit value %.2lf", top->unitPrice);
    			printf("\nTotal value value %.2lf", top->totalValue);
    			printf("\nUnstacked Due Date Value %d/%d/%d", top->day, top->month, top->year);
                unstack(&top);
                showStack(top);
                break;
            default:
                printf( "Wrong option.\n\n");
                break;
        }
        Menu();
        scanf("%d", &flag);   
    }
    return 0;
} 