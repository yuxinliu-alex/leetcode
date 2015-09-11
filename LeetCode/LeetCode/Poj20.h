#define STACK_MAX 100
#include <stdbool.h>
struct Stack {
    char     data[STACK_MAX];
    int     size;
};
typedef struct Stack Stack;

void Stack_Init(Stack *S){
    S->size = 0;
}

char Stack_Top(Stack *S){
    if (S->size == 0)
        return '\0';
    return S->data[S->size-1];
}

void Stack_Pop(Stack *S){
    if(S->size > 0)
        S->size--;
}


void Stack_Push(Stack *S, char d){
    if (S->size < STACK_MAX)
        S->data[S->size++] = d;
}

bool isValid(char* s) {
    Stack S_p;
    Stack_Init(&S_p);
    while (*s!='\0') {
        if (*s=='('||*s=='['||*s=='{')
            Stack_Push(&S_p,*s);
        else if(*s==')'){
            if(Stack_Top(&S_p)!='\0'&&Stack_Top(&S_p)==*s-1)
                Stack_Pop(&S_p);
            else
                return false;
        }
        else if(*s==']'||*s=='}'){
            if(Stack_Top(&S_p)!='\0'&&Stack_Top(&S_p)==*s-2)
                Stack_Pop(&S_p);
            else
                return false;
        }
        s++;
    }
    if (Stack_Top(& S_p)=='\0')
        return true;
    return false;
}