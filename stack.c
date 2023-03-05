#include <stdio.h>

#ifndef QUANT
#define QUANT 10
#endif

int stack[QUANT]={0,0,0,0,0,0,0,0,0,0}, top=0;

void show(void){ // show stack

    printf("\n");
    for(int i=0;i<QUANT;i++){
        printf("-\\%d\\-", stack[i]);
    }
    printf("\n");
    printf("\n");
}

void push(int* num){ // insert on the top

    stack[top] = *num;
    top+=1;
}

void pop(void){ // remove the top element

    if(top>0){

        stack[top-1] = 0;
        top-=1;
    }else{
        puts("The stack is empty.");
    }
}

void clear(void){ // clean the stack

    for(int i=0;i<QUANT;i++){

        stack[i] = 0;
    }
    top=0;
}

void main(){

    int a=10,b=20;

    show();
    push(&a);
    push(&b);
    show();
    pop();
    show();
}