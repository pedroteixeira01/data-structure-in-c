#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{

    int code, usage, day, month, year;
    float u_price, total;
    char name[40];
    struct Node* next;
    struct Node* previous;
}n;

n* head;
n* tail;
int length;

void create(){
    
    head = NULL;
    tail = NULL;
    length = 0;
}

int empty(){
    
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void show(n* aux){
    puts("\n##############################");
    printf("#Client's code-> %d\n", aux->code);
    printf("#Client's name-> %s\n", aux->name);
    printf("----------------------------\n");
    printf("#Area usage (kWh)-> %d\n", aux->usage);
    printf("#Unit price-> %.2f\n", aux->u_price);
    printf("#Total value-> %.2f\n", aux->total);
    printf("#Due date-> %2d/%2d/%4d\n", aux->day, aux->month, aux->year);
    printf("#Pointer-> %p\n", aux);
    puts("##############################");
}

void list(){

    if(empty()){
        puts("\nThe queue is empty now.");
    }else{
        n* aux = head;
        for(int i=0;i<length; i++)
        {
            show(aux);
            aux = aux->next;
        }
        
    }
}

void ins_end(){

    n* n1 = (n*) malloc(sizeof(n));

    if(!n1){
        printf("The memory is already full.\n");
        exit(1);
    }else{
        int code, usage, day, month, year;
        float u_price, total;
        char name[40];

        printf("\nInsert the client's name-> ");
        scanf("%s", name);
        printf("Insert the client's code-> ");
        scanf("%d", &code);
        printf("Insert the usage in kWh-> ");
        scanf("%d", &usage);
        printf("Insert the unit price-> ");
        scanf("%f", &u_price);
        printf("Insert the total value-> ");
        scanf("%f", &total);
        printf("Insert the due day-> ");
        scanf("%d", &day);
        printf("Insert the due month-> ");
        scanf("%d", &month);
        printf("insert the due year-> ");
        scanf("%d", &year);

        strcpy(n1->name, name);
        n1->code = code;
        n1->usage = usage;
        n1->u_price = u_price;
        n1->total = total;
        n1->day = day;
        n1->month = month;
        n1->year = year;       
        n1->next = NULL;
        n1->previous = NULL;

        if(head == NULL){
            head = n1;
            tail = n1;
        }else{
            tail->next = n1;
            n1->previous = tail;
            tail = n1;
        }
        length++;
        puts("\nBill successfully added in the list.");
    }

}

void remo_beg(){

    if(empty()){
        puts("\nThe queue is empty now.");
    }else{
        n* aux = head->next;
        head = aux;
        head->previous = NULL;
        length--;
    }
}

void add_beet(n* position){

    n* n1 = (n*) malloc(sizeof(n));

    if(!n1){
        printf("\nThe memory is already full.\n");
        exit(1);
    }else{
        int code, usage, day, month, year;
        float u_price, total;
        char name[40];

        printf("\nInsert the client's name-> ");
        scanf("%s", name);
        printf("Insert the client's code-> ");
        scanf("%d", &code);
        printf("Insert the usage in kWh-> ");
        scanf("%d", &usage);
        printf("Insert the unit price-> ");
        scanf("%f", &u_price);
        printf("Insert the total value-> ");
        scanf("%f", &total);
        printf("Insert the due day-> ");
        scanf("%d", &day);
        printf("Insert the due month-> ");
        scanf("%d", &month);
        printf("insert the due year-> ");
        scanf("%d", &year);

        strcpy(n1->name, name);
        n1->code = code;
        n1->usage = usage;
        n1->u_price = u_price;
        n1->total = total;
        n1->day = day;
        n1->month = month;
        n1->year = year;       
        n1->next = NULL;
        n1->previous = NULL;

        if(head == NULL){
            head = n1;
            tail = n1;
        }else{

            if(position->previous == NULL){
                n1->next = position;
                position->previous = n1;
                head = n1;
            }else if(position->next == NULL){
                n1->previous = position;
                position->next = n1;
                tail = n1;
            }else{
                n1->previous = position;
                n1->next = position->next;
                position->next->previous = n1;
                position->next = n1; 
            }
        }
        length++;
        puts("\nBill successfully added in the list.\n");
    }
}

void each(){

    if(empty()){
        puts("\nThe queue is empty now.");
    }else{
        int opc=1, opc2;
        n* node = head;
        show(node);
        do{
            printf("\nChoose the option:\n1: Next\n2: Previous\n3: Insert in this position\n-1: Back\n-> ");
            scanf("%d", &opc2);
            switch (opc2)
            {
                case 1:
                    if(node->next != NULL){
                        node = node->next;
                        show(node);

                    }else{
                        puts("\nEnd of the list");
                    }
                    break;
                case 2:
                    if(node->previous != NULL){
                        node = node->previous;
                        show(node);

                    }else{
                        puts("\nStart of the list");
                    }
                    break;
                case 3:
                    add_beet(node);
                    show(node);
                    break; 
                case -1:
                    opc = 0;
                    break;
                default:
                    puts("\nERROR. The chosen option doesn't exist");
                    break;
        }
    }while(opc);
    }
}

void main(void){

   int opc=1, opc2;

    puts("\n#######################");
    printf("# My electricity bills #\n");
    puts("#######################");
    create(); 

    do{

        printf("\nNumber of bills registred-> %d\n", length);
        printf("\nChoose the option number:\n1: Insert one bill\n2: Remove one bill\n3: List existing bills\n4: Each element\n-1: Quit\n-> ");
        scanf("%d", &opc2);
        
        switch(opc2){
            case 1:
                ins_end();
                break;
            case 2:
                remo_beg();
                break;
            case 3:
                list();
                break;
            case 4:
                each();
                break;
            case -1:
                 opc=0;
                 break;
            default:
                puts("\nERROR. The chosen option doesn't exist");
        }
    }while(opc);
}