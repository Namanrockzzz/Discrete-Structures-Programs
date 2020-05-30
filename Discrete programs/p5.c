#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int compare (const void *a, const void * b);
void swap (char* a, char* b);
int GreaterChar(char str[], char first, int l, int h);
void printPermutations( char str[] ); 
int main() 
{ 
	char str[20];
	printf("Name - Naman Taneja and Roll number - 2019UCO1640\n");
	printf("Type string to check all it lexicographic :\n"); 
	scanf("%s",str);
	printf("Here's your result :- \n");
	printPermutations(str); 
	return 0; 
} 
int compare (const void *a, const void * b) 
{ 
	const char *c1,*c2;
	c1=(char*)a;
	c2=(char*)b;
	return strcmp(c1,c2);
} 
void swap (char* a, char* b) 
{ 
	char t = *a; 
	*a = *b; 
	*b = t; 
} 

int GreaterChar (char str[], char first, int l, int maxindex) 
{ 
	int Index;
	Index=l;
	for (int i = l+1; i <= maxindex; i++) 
	if (str[i] > first && str[i] < str[Index]) 
	{
			Index = i;
	}
	return Index; 
} 
void printPermutations ( char str[] ) 
{ 
	int size,isFinished,i; 
	size = strlen(str);
	isFinished = 0;
	qsort( str,size,sizeof( str[0] ),compare);
	while ( ! isFinished ) 
	{ 
		printf ("%s \n", str);
		for (i = size-2;i>= 0;i--)
		{
			if (str[i] < str[i+1])
			{
				break; 
			}
		}
		if(i == -1) 
			isFinished = 1; 
		else
		{ 
			int greaterchar = GreaterChar(str,str[i], i + 1, size - 1 ); 
			swap( &str[i], &str[greaterchar] ); 
			qsort( str + i + 1, size - i - 1, sizeof(str[0]), compare ); 
		} 
	} 
} 