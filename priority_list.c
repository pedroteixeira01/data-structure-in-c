#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
	
	char name[30];
	int age;
	struct Person *next;
	struct Person *previous;
}pe;


typedef struct Schedule{
	
	pe *head;
	pe *tail;
}sc;


sc *start_sc(void){
	
	sc *a = (sc*) malloc(sizeof(sc));
	
	if(!a){

		printf("\nInsufficient memory space\n");
		exit(1);
	}else{

		a->head = NULL;
		a->tail = NULL;
		return a;
	}
	
}


pe *start_pe(void){
	
	pe *p = (pe *) malloc(sizeof(pe));
	
	if(!p){

		printf("\nInsufficient memory space\n");
		exit(1);
	}else{

		p->age = -1;
		strcpy(p->name, "\0");
		p->next = NULL;
		p->previous = NULL;
		return p;
	}
	
}


int is_empty(sc *a){
	
	if(a->head == NULL) {
		
		return 0;
	}else {
		
		return 1;
	}
}


void view(sc *a){
	
	pe *aux = (pe *)malloc(sizeof(pe));
	
	if(!aux){
		
		printf("\nInsufficient memory space\n");
		exit(1);
	}else{
		
		if(!is_empty(a)) {
			
			printf("\nThe calendar has no registrations\n");
		}else{
			
			int cont=1;
			aux = a->head;

			printf("\nprinting in ascending mode\n");
			printf("Address of the first of the list : %p", a->head);
			printf("  ||  Last name of the list : %p", a->tail);
			printf("\n\n-------------------------------\n");
			printf("|Name |\tAge |\tActual Address|");
			printf("\n-------------------------------\n");
			
			if(a->head == a->tail){
				
				printf("%d", cont);
				printf(" |%s ", aux->name);
				printf("| %d ", aux->age);
				printf("| %p\n", aux);
				printf("-------------------------------\n");
			}else{
				while (aux->next != NULL){
				
					printf("%d", cont);
					printf(" |%s ", aux->name);
					printf("| %d ", aux->age);
					printf("| %p\n", aux);
					printf("-------------------------------\n");

					aux = aux->next;
					cont++;
				}
				printf("%d", cont);
				printf(" |%s ", a->tail->name);
				printf("| %d ", a->tail->age);
				printf("| %p\n", a->tail);
				printf("-------------------------------\n");
			}
		}
	}
}


void viewr(sc *a){
	
	pe *aux = (pe *)malloc(sizeof(pe));
	
	if(!aux) printf("\nInsufficient memory space\n");
	else{
		
		if(!is_empty(a)) printf("\nThe calendar has no registrations\n");
		else{


			int cont=1;
			aux = a->tail;
			printf("\nprinting in descending mode");
			printf("\nFirst of the list address : %p", a->head);
			printf("  ||  Last name of the list : %p", a->tail);
			printf("\n\n-------------------------------\n");
			printf("|Name |\tAge |\tActual Address|");
			printf("\n-------------------------------\n");
			
			if(a->head == a->tail){
				
				printf("%d", cont);
				printf(" |%s ", aux->name);
				printf("| %d ", aux->age);
				printf("| %p\n", aux);
				printf("-------------------------------\n");
			}else{

				while(aux->previous != NULL){

					printf("%d", cont);
					printf(" |%s ", aux->name);
					printf("| %d ", aux->age);
					printf("| %p\n", aux);
					printf("-------------------------------\n");
				
					aux = aux->previous;
					cont++;
				}
				
				printf("%d", cont);
				printf(" |%s ", a->head->name);
				printf("| %d ", a->head->age);
				printf("| %p\n", a->head);
				printf("-------------------------------\n");
				
			}
		}
	}
} 


pe *add_info(){

	pe *p = (pe*) malloc(sizeof(pe));
	
	if(!p) {
		
		printf("\nInsufficient memory space\n");

	}else{

		printf("Enter the person's name -> ");
		gets(p->name);
		printf("Enter the person's age -> ");
		scanf("%d", &p->age);
		p->next = NULL;
		p->previous = NULL;
		return p;
	}
}


void insert_pe(sc *a){
	
	pe *new = add_info();
	
	if(!new) printf("\nInsufficient memory space\n");
	else{

		if(!is_empty(a)){

			a->head = new;
			a->tail = new;
			
		}else{
			
			pe *aux = a->head;
			int ins = 0;
			
			if(a->head == a->tail){

				if(new->age == aux->age){
					if(strcmp(new->name, aux->name) < 0){

						aux->previous = new;
						new->next = aux;
						a->head = new;
					}else{

						aux->next = new;
						new->previous = aux;
						a->tail = new;
					}
				}else{

					if(new->age < aux->age){

						aux->previous = new;
						new->next = aux;
						a->head = new;
					}else{

						aux->next = new;
						new->previous = aux;
						a->tail = new;
					}
				}

			}else{

				while(aux->next != NULL){
					
					if(new->age == aux->age){
						if(strcmp(new->name, aux->name) < 0){

							new->previous = aux->previous;
							new->previous->next = new;
							aux->previous = new;
							new->next = aux;

							ins++;
							break;							
						}else{
							
							new->next = aux->next;
							aux->next->previous = new;
							aux->next = new;
							new->previous = aux;

							ins++;
							break;
						}
					}else if(new->age < aux->age){

						new->previous = aux->previous;
						new->previous->next = new;
						aux->previous = new;
						new->next = aux;
						
						ins++;
						break;
					}

					aux = aux->next;
				}

				if(!ins){

					if(new->age == a->tail->age){
						if(strcmp(new->name, a->tail->name) < 0){

							new->next = a->tail;
							new->previous = a->tail->previous;
							a->tail->previous->next = new;
							a->tail->previous = new;
						}else{

							a->tail->next = new;
							new->previous = a->tail;
							a->tail = new;
						}
					}else{
				
						if(new->age < a->tail->age) {

							new->previous = a->tail->previous;
							new->next = a->tail;
							new->previous->next = new;
							a->tail->previous = new;
						}else{

							a->tail->next = new;
							new->previous = a->tail;
							a->tail = new;
						}	
			
					}
				}
				
			}
			
		}
	}
		puts("\nSuccessfully registered person");
}



void remove_pe(sc *a){ 

	if(!is_empty(a)){

		puts("\nThe calendar has no registrations");
	}else{

		printf("\nAddress to be removed : %p\n", a->tail);
		pe *p = a->tail;

		if(a->head == a->tail){

			a->head = NULL;
			a->tail = NULL;
			free(p);
			
		}else{
		
			a->tail = a->tail->previous;
			a->tail->next = NULL;
			free(p);
			
		}
		puts("\nPerson successfully removed");
	}
}


void menu(void){
	
	printf("\nChoose an option:\n0 - Exit\n1 - Insert\n2 - Remove\n3 - View people\n-> ");
}


int main(){

	int opc;
	sc *a = start_sc();
	pe *p = start_pe();
	
	puts("\nOrdered priority list");

	do{
		
		menu();
		scanf("%d", &opc);
		fflush(stdin);
		getc(stdin);

		switch (opc)
		{
		case 0:
			puts("\nExiting the priority queue...");
			break;
		
		case 1:
			insert_pe(a);
			break;

		case 2:
			remove_pe(a);
			break;
		
		case 3:
			viewr(a);
			break;

		default:
			puts("\nInvalid option. Try again.");
			break;
		}
	}while(opc !=0 );
	
	return 0;
}