#include <stdio.h>
#include <stdlib.h>

/*
  Each node stores three information: 
  in that case a number (num), 
  pointer to subtree on the right (sad) and 
  pointer to subtree on the left (sae).
*/
   
typedef struct tree{

  int num;
  struct tree* sad;
  struct tree* sae;
} tree;

/* 
  The structure of the tree is represented by a pointer to the root node.
  With this pointer, we have access to the too many of us. 
*/

// Function creating a tree.

tree* createTree(){
/* 
  A tree and represented by the address of the root node,
  this function creates a tree with no element, that is, 
  it creates an empty tree, so it returns NULL.
*/
  return NULL;
}


//  Function that checks whether a tree is empty.

int isEmpty(tree* t){
// Returns 1 if the tree is empty and 0 otherwise.
  return t == NULL;

}

// function that shows tree information
void showTree(tree* t){
  /* This function prints the elements recursively */
  
  printf("<");
  if(!isEmpty(t)){
    /* Shows elements in pre-order*/
    printf("%d ", t->num); /* show root */
    showTree(t->sae); /* show sae (subtree on the left) */
    showTree(t->sad); /* show sad (subtree on the right) */
  }
  printf(">");
}

/* function that inserts a given into the tree */
void addTree(tree** t, int num)
{
  /* This function inserts the elements in a recursive manner */
  if(*t == NULL){
    *t = (tree*)malloc(sizeof(tree));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
  }else {
    if(num < (*t)->num){ /* If the number is smaller then it goes left */
      /* Scrolls through the subtree on the left */
      addTree(&(*t)->sae, num);
    }
    if(num > (*t)->num){ /* If the number is higher then it goes right */
    
      /* Scroll through the subtree on the right */
      addTree(&(*t)->sad, num);
    }
  }
}

/* function that checks whether or not an element belongs to the tree */
int isIntree(tree* t, int num) {
  
  if(isEmpty(t)) { /* If the tree is empty, then returns 0 */
    return 0;
  }
  
  /* The logical operator || stops the search when the element is found */
  return t->num==num || isIntree(t->sae, num) || isIntree(t->sad, num);
}

int main(){
  tree* t = createTree(); /* create tree */
  
  addTree(&t, 12); /* inserts element 12 into the tree */
  addTree(&t, 15); /* inserts element 15 into the tree */
  addTree(&t, 10); /* inserts element 10 into the tree */
  addTree(&t, 13); /* inserts element 13 into the tree */
   
  showTree(t); /* Shows tree elements in pre-order */
  
  if(isEmpty(t)) /* Checks to see if the tree is empty */
  {
    printf("\n\ntree empty!!\n");
  } else {
    printf("\n\ntree not empty!!\n");
  }
  
  if(isIntree(t, 15)) { /* Checks if the number 15 belongs to the tree */
    printf("\nNumber 15 belongs to tree!\n");
  } else {
     printf("\nNumber 15 doesn't belong to tree!\n");
  }
  
  if(isIntree(t, 22)) { /* Checks if the number 22 belongs to the tree */
    printf("\nNumber 22 belongs to tree!\n\n");
  } else {
     printf("\nNumber 22 doesn't belong to tree!\n\n");
  }
  
  free(t); /* Frees memory */
  
  return 0;
}
