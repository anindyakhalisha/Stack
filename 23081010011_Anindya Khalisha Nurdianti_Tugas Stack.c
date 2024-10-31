#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 10

//========================================================

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

struct Stack {
    Node* top;
    int count;
};
typedef struct Stack Stack;

void createStack(Stack* stack);
void pushStack(Stack* stack);
void popStack(Stack* stack);
void stackTop (Stack* stack);
bool emptyStack(Stack* stack);
bool fullStack(Stack* stack);
int stackCount(Stack* stack);
void destroyStack(Stack* stack);


//========================================================

int main(){

    Stack stack;
	createStack(&stack);
    char pilih;
    int data;

  do{
     system("cls");
     printf("Masukkan Pilihan\n");
     printf("1. Push Stack\n");
     printf("2. Pop Stack\n");
     printf("3. Stack Top\n");
	 printf("4. Empty Stack\n");
	 printf("5. Full Stack\n");
     printf("6. Stack Count\n");
     printf("7. Destroy Count\n");
     printf("MASUKKAN PILIHAN (Tekan q untuk keluar) : ");
     fflush(stdin);
     scanf("%c", &pilih);
	 if (pilih == '1'){
            pushStack(&stack);
     }else if (pilih == '2'){
			popStack(&stack);
	 }else if (pilih == '3'){
     		stackTop(&stack);
     }else if (pilih == '4'){
     		printf("Empty Stack: %s\n", emptyStack(&stack) ? "True" : "False");
     }else if (pilih == '5'){
     		printf("Full Stack: %s\n", fullStack(&stack) ? "True" : "False");
	 }else if (pilih == '6'){
     		printf("Stack Count: %d\n", stackCount(&stack));
	 }else if (pilih == '7'){
     		destroyStack(&stack);
     		printf("Stack destroyed.\n");
	 }
      getch();
      
  } while (pilih != 'q');
  
  return 0;
}

//========================================================

void createStack(Stack* stack) {
    
	stack->top = NULL;
    stack->count = 0;
    
}

//========================================================

void pushStack(Stack* stack){
	
	if (fullStack(stack)) {
		
        system("cls");
		printf("Stack Penuh!!\n");
        getch();
        
    } else {
	
		int data;
        system("cls");
		printf("Masukkan data: ");
        scanf("%d", &data);
        
		Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = stack->top;
        stack->top = newNode;
        stack->count++;
        printf("Data berhasil ditambahkan.\n");
		getch();
		
	}	
}

//========================================================

void popStack(Stack* stack){
	
	if (emptyStack(stack)) {
		
        system("cls");
		printf("Stack Kosong!!\n");
        getch();
        
    } else {
		
		Node* dltPtr = stack->top;
        int dataOut = stack->top->data;
        stack->top = stack->top->next;
        stack->count--;
        free(dltPtr);
        
		system("cls");
		printf("Data yang di-pop: %d\n", dataOut);
		getch();
		
	}
}

//========================================================

void stackTop(Stack* stack) {
	
	if (emptyStack(stack)) {
        printf("Stack Kosong!!\n");
    } else {
        printf("Top element: %d\n", stack->top->data);
    }
    
}

//========================================================

bool emptyStack(Stack* stack) {
	return stack->count == 0;
}

//========================================================

bool fullStack(Stack* stack) {
	return stack->count == MAX_STACK_SIZE;
}
    
//========================================================

int stackCount(Stack* stack) {
 	return stack->count;
}

//========================================================

void destroyStack(Stack* stack) {
 
  while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    stack->count = 0;

}

//========================================================

