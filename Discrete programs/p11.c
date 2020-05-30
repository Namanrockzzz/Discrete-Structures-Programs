#include <stdio.h>
#include <stdlib.h>
int isRing(float G[],int n);
int isGroup(float G[],int n);
int isClosure_add(float G[],int n);
int isClosure_mul(float G[],int n);
int identityelement_exist(float G[],int n);
int inverse_exist(float G[],int n,float element, float identity);
int inG(float G[],int n, float term);
int main()
{
	float G[200];
	int n,i;
	printf("Name - Naman Taneja and Roll no. - 2019UCO1640\n");
	printf("No. of elements in the G : ");
	scanf("%d",&n);
	printf("Enter %d elements of the G :\n",n);
	for (i = 0; i < n; ++i)
	{
		scanf("%f",&G[i]);
	}
	if (isRing(G, n))
	{
		printf("Yes, (G,*,+) is a Ring\n");
	}
	else
	{
		printf("No, (G,*,+) is not a ring\n");
	}
}
int isRing(float G[],int n)
{
	if(isGroup(G,n))
	{
		if(isClosure_mul(G,n))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

int isGroup(float G[],int n)
{
	int index,i;
	if(isClosure_add(G, n))
	{
		index = identityelement_exist(G, n);
		if(index!=-1)
		{
			for (i = 0; i < n; ++i)
			{
				if(inverse_exist(G, n, G[i], G[index])==0)
				{
					return 0;
				}
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{	
		return 0;
	}
	return 1;
}
int isClosure_add(float G[],int n)
{
	float term;
	int i,j;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			term = (G[i])+(G[j]);
			if(inG(G,n,term)==-1)
			{
				return 0;
			}
		}
	}
	return 1;
}
int isClosure_mul(float G[],int n)
{
	int i,j,term;
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			term = (G[i])*(G[j]);
			if(inG(G, n, term)==-1)
			{
				return 0;
			}
		}
	}
	return 1;
}

int identityelement_exist(float G[],int n)
{
	if(inG(G, n, 0)==-1)
	{
		return 0;
	}
	return 1;
}
int inverse_exist(float G[],int n,float element,float identity)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		if((((G[i])+element) - identity)>-0.0000001 && (((G[i])+element) - identity)<0.000001)
		{
			return 1;
		}
	}
	return 0;
}

int inG(float G[],int n, float term)
{
	int i;
	for (int i = 0; i < n; ++i)
	{
		if((G[i]) == term)
		{
			return i;
		}
	}
	return -1;
}