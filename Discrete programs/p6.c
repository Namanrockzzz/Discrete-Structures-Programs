#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare (const void *a, const void * b);
int find(char arr[],char ele,int n);
void printResult(char* result, int len);
void stringCombination(char result[], char distinct_char[], int freq[], int level, int original_l, int length);
void combination(char *str) ;
int main() 
{ 
	char str[20];
    printf("Name - Naman Taneja and Roll number - 2019UCO1640\n");
	printf("Type string to check all it lexicographic combinations :\n"); 
	scanf("%s",str);
	qsort( str,strlen(str),sizeof(str[0]),compare);
	printf("Here's your result :- \n");
    combination(str); 

    return 0; 
} 
int compare (const void *a, const void * b) 
{ 
    const char *c1,*c2;
    c1=(char*)a;
    c2=(char*)b;
    return strcmp(c1,c2);
} 
int find(char arr[],char ele,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            return i;
        }
    }
    return -1;
}
void printResult(char* result, int len) 
{ 
    int i;
    for (i = 0; i <= len; i++) 
        printf("%c",result[i]); 
    printf("\n");
} 
void stringCombination(char result[], char distinct_char[], int freq[], 
                    int level, int original_l, int length) 
{ 
    int i;
    if (level == original_l) 
        return; 

    for (i = 0; i < length; i++) 
    { 
        if (freq[i] == 0) 
            continue; 
        freq[i]--; 
        result[level] = distinct_char[i]; 
        printResult(result, level); 
        stringCombination(result, distinct_char,freq, 
                        level + 1, original_l, length); 

        freq[i]++; 
    } 
} 

void combination(char *str) 
{ 
    char distinct_char[strlen(str)],result[strlen(str)];
    int freq[strlen(str)],count=0,i,a;

    for (i = 0; i < strlen(str); i++)
    { 
        a=find(distinct_char,str[i],count);
        if(a!=-1)
        {
            freq[a]+=1;
        } 
        else
        {
            distinct_char[count]=str[i];
            freq[count]=1;
            count+=1;
        }
    } 
    stringCombination(result,distinct_char,freq, 
                    0,strlen(str),count); 
} 