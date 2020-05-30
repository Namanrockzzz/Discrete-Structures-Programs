#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
int func(int G[][7], int visited[], int parent, int current, int check);
void detectcycle(int G[][7], int visited[]);
void findpath(int G[][7], int current, int parent, int checker[]);
void display(int checker[], int end);
int main()
{
	int G[][7] = { {0,1,1,0,0,0,0},
	               {1,0,1,0,1,0,0},
				   {1,1,0,1,0,0,0},
				   {0,0,1,0,0,1,1},
				   {0,1,0,0,0,0,0},
				   {0,0,0,1,0,0,0},
				   {0,0,0,1,0,0,0}	};
    
    int visited[7] = {0},checker[7] = {-1, -1, -1, -1, -1, -1, -1};
    int start, end;
    printf("Name - Naman Taneja and Roll no. - 2019UCO1640\n");
    detectcycle(G, visited);
    printf("Starting node =\n");
    scanf("%d",&start);
    printf("Ending node =\n");
    scanf("%d",&end);
    findpath(G,start,-2,checker);
    display(checker, end);	   
    return 0;
}
int func(int G[][7], int visited[], int parent, int current, int check)
{
    int i;
    if(check==1) 
        return 0;
    visited[current] = 1;
    for(i = 0; i < 7; i++)
    {   if(check==1) 
            return 0;
        if(G[current][i] == 1 && visited[i] == 1 && i != parent)
        {
            check = 1;
            return 0;
        }
        if(G[current][i] == 1 && visited[i] == 0)
        {
            func(G, visited, current, i, check);
        }
    }
    return 1;
}
void detectcycle(int G[][7], int visited[])
{
    int var = 0;
    var = func(G, visited, -1, 0, var);
    if(var) 
        printf("No cycles in this graph\n");
    else
        printf("This graph has a cycle.\n");
}
void findpath(int G[][7], int current, int parent, int checker[])
{
    int i;
    checker[current] = parent;
    for(i = 0; i < 7; i++)
    {
        if(G[current][i] == 1 && checker[i] == -1)
        {   
            findpath(G, i, current, checker);
        }
    }
}
void display(int checker[], int end)
{
    if(checker[end] >= 0)
    {
        display(checker, checker[end]);
        printf("%d\n",end);
    }
    else
    printf("%d\n",end);
}