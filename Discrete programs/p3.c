#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 

struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 
int C(int a, int b);
int D(int a,int  b);
int I(int a,int b);
int E(int a, int b);
int N(int a);
struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int item);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
void Check(char expr[],struct Stack* stack);
int Power(int a,int b);
int counter0 = 0;
int counter1 = 0;

int main() 
{ 
	struct Stack* stack;
	char expr[111];
	stack = createStack(100);
    printf("Name - Naman Taneja and Roll number - 2019UCO1640\n");
	printf("Here operators are represented as follows :-\n");
	printf("And 'C'\nOr 'D'\nImplies 'I'\nIf and only if 'E'\nNot 'N'\n\n");
	printf("Type your expression as a prefix :\n");
	scanf("%s",expr);
    Check(expr,stack);
    if(counter0==0)
    {
        printf("Expression is tautology\n");
    }
    else if (counter1==0)
    {
        printf("Expression is contradiction\n");
    }
    else
    {
        printf("Expression is contingency\n");
    }
    return 0;
}

int C(int a, int b){
    return a & b;
}
int D(int a,int  b) {
    return a | b;
}
int  I(int a,int b){
    return !a | b;
}
int E(int a, int b) {
    return !(a ^ b);
}
int N(int a)  {
    return !a;
}
struct Stack* createStack(unsigned capacity) 
{ 
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
	stack->capacity = capacity; 
	stack->top = -1; 
	stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
	return stack; 
} 
int isFull(struct Stack* stack) 
{ 
	return stack->top == stack->capacity - 1; 
} 

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1; 
} 

void push(struct Stack* stack, int item) 
{ 
	if (isFull(stack)) 
		return; 
	stack->array[++stack->top] = item; 
} 
int pop(struct Stack* stack) 
{ 
	if (isEmpty(stack)) 
		return-2000; 
	return stack->array[stack->top--]; 
} 
int peek(struct Stack* stack) 
{ 
	if (isEmpty(stack)) 
		return -2000; 
	return stack->array[stack->top]; 
}
int Power(int a,int b)
{
	if(a==0)
	{
		return 0;
	}
	if(b==0)
	{
		return 1;
	}
	return a*Power(a,b-1);
}
void Check(char expr[],struct Stack *stack)
{
    int uniquevar[26],n,val[n],i,j,k,val1,val2;
    for(int i = 0; i < 26; ++i)
    {
		uniquevar[i] = -1;
    }
    n = 0;
    for(int i = 0; i < strlen(expr); ++i)
    {
        if(expr[i] >= 'a' && uniquevar[expr[i] - 'a'] == -1)
        {
            uniquevar[expr[i] - 'a'] = n++;
        }
    }
    for(i = 0; i <(1 << n); ++i)
    {
        for(j = 0;j<n;++j)
            val[j] = (i >> j) & 1;
        for(k = strlen(expr)-1; k >= 0; --k)
        {
            if(expr[k] >= 'a')
            {
                push(stack,val[uniquevar[expr[k] - 'a']]);
                continue;
            }

            val1 = peek(stack);
            pop(stack);
            switch(expr[k])
            {
                case 'C':
                    val2 = peek(stack);
                    pop(stack);
                    push(stack,C(val1, val2));
                    break;
                case 'D':
                    val2 = peek(stack);
                    pop(stack);
                    push(stack,D(val1, val2));
                    break;
                case 'I':
                    val2 = peek(stack);
                    pop(stack);
                    push(stack,I(val1, val2));
                    break;
                case 'E':
                    val2 = peek(stack);
                    pop(stack);
                    push(stack,E(val1, val2));
                    break;
                case 'N':
                    push(stack,N(val1));
                    break;
                default:
                    break;

            }
        }

        if(peek(stack) == 0)
        {
            counter0++;
        } else
            counter1++;
    }

}