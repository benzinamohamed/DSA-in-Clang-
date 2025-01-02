#include <stdio.h> 
#include <stdlib.h>


typedef struct Node{
   
  int data ;
  struct Node *left;
  struct Node *right;
} Node;




Node* createNode(int value){
  Node* newNode = (Node*)malloc(sizeof(Node));

  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}


  Node* InsertNode(Node* root , int value){   // im making in it returns a pointer to a node to avoid dealing with ugly code like node** 
   if(root == NULL) {
    
    return createNode(value);
   };
   
   if(value < root->data){
    root->left = InsertNode(root->left,value);
   }else {
   root->right = InsertNode(root->right,value);
   }


   return root;
}


Node* NonRecurusiveInsertNode (Node* root ,int value){
  if(root == NULL) return createNode(value);
  
  Node* tempNode = root;
  Node* parent;
  while (tempNode != NULL) {
    parent = tempNode;
    if(value <tempNode->data)  {

      tempNode = root->left;

    }else {

      tempNode = root->right;
    }
  }
    
    if (value<parent->data) {
 parent->left =createNode(value);
    } else {
      parent->right = createNode(value);
    }
    
  return root;

}


void printTree(Node* root){
  if(root == NULL) return ;
  printTree(root->left);
  printf("%d\n",root->data);
  printTree(root->right);
}


void printTree2(Node* root){
  
  if(root == NULL) return ;

  printTree(root->right);
  
  printf("%d\n",root->data);

   printTree(root->left);                                                                                                                                                       }



int numberOfNodes (Node* root){
   if(root == NULL) return 0;
  return numberOfNodes(root->left) + numberOfNodes(root->right)+ 1;
}

int numberOfleaves (Node* root){
 if(root == NULL) return 0;
 if(numberOfleaves(root->left)+numberOfleaves(root->right) == 0) return 1;

  return numberOfleaves(root->left) + numberOfleaves(root->right); 
   }


int sumOfContent(Node* root){
   if(root == NULL) return 0;
   return root->data + sumOfContent(root->left) + sumOfContent(root->right);
}

int max(int a , int b){
 return (a>=b)? a : b;
}

int depthOfTree(Node* root){
  if(root == NULL) return 0;
  if(root->left ==NULL && root->right ==NULL) return 0;
  return max(1+depthOfTree(root->right),depthOfTree(root->left)+1);


}
int main () {

  printf("hello this is a small implmentation of binary trees!\n");

   Node* Root = NULL;
   
 /* Root = InsertNode(Root , 14); 
   Root = InsertNode(Root , 13);
  Root = InsertNode(Root,16);
  Root = InsertNode(Root ,0);
  Root = InsertNode(Root , 17);
  Root = InsertNode(Root , 12);
  Root = InsertNode(Root , 12);
  Root = InsertNode(Root , 13);
  Root = InsertNode(Root , 1);

 Root = InsertNode(Root , -1);
  Root = InsertNode(Root , 13);
  Root = InsertNode(Root ,15);
  Root = InsertNode(Root ,12);  
  Root = InsertNode(Root , 12);
  Root = InsertNode(Root , 12);
  */     

Root = NonRecurusiveInsertNode(Root , 14);
Root = NonRecurusiveInsertNode(Root , 13);
Root = NonRecurusiveInsertNode(Root, 16);

printf("number of leaves is : %d\n",numberOfleaves(Root));

printf("number of  is nodes  : %d\n",numberOfNodes(Root));

printf("sum of content is %d\n" ,sumOfContent(Root));
printf("the depth of this binary tree is  %d\n", depthOfTree(Root));
 printTree2(Root);



  return 0;
     }
  




 

