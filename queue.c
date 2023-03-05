#include <stdio.h>

#ifndef QUANT
#define QUANT 10
#endif

int queue[QUANT] = {0,0,0,0,0,0,0,0,0,0}, h=0, t=0;

void show(void){ // show queue

    printf("\n");
    for(int i=0;i<QUANT;i++){
        printf("-\\%d\\-", queue[i]);
    }
    printf("\n");
    printf("\n");
}

void insert(int* num){ // inserts an element into the queue

    queue[t] = *num;
    t += 1;
}

void remo(void){ // removes an element from the queue without ordering it
    if(h>0){

        queue[h] = 0;
        h += 1;
    }else{
        puts("The queue is empty.");
    }
}

void remo_o(void){ // removes the element from the queue by ordering it 

    if(h>0){ 

        for(int i=0;i<t;i++){
            queue[h] = queue[i+1];
            h++;
        }
        h=0;
        t--;
    }else{
        printf("The queue is empty.");
    }
}

void clear(void){ // Clean the queue

    if(h<t){
        for(int i=0;i<QUANT;i++){
            queue[i] = 0;
        }
        h = 0;
        t = 0;
    }else{
        printf("Already cleaned...\n");
    }
}


void main(void){

    int a=20,b=10;
    show();
    insert(&a);
    

}