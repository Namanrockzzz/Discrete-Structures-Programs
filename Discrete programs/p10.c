#include <stdio.h>
int is_group(int G[],char c,int n);
int is_closure(int G[],char c,int n);
int associativity_satisfied(int G[],char c,int n);
int identityelement_exist(int G[],char c,int n);
int inverse_exist(int G[],char c,int n);
int inG(int G[],int n,int ele);
int main(int argc, char const *argv[])
{
	int G[100],n,i;
	char ch;
	printf("Name - Naman Taneja and Roll no. - 2019UCO1640\n");
	printf("Choose an operator from +,-,*,/,| : ");
	ch = getchar();
	printf("Number of elements in set G are : ");
	scanf("%d",&n);
	printf("Type %d elements of your set : ",n);
	for ( i = 0; i < n; i++)
	{
		scanf("%d",&G[i]);
	}
	if(is_group(G,ch,n))
		printf("Yes, (G,%c) is a group\n",ch);
	else
		printf("No, (G,%c) is not a group\n",ch);
	return 0;
}
int is_group(int G[],char c,int n)
{
	if(is_closure(G,c,n))
	{
		if(associativity_satisfied(G,c,n))
		{
			if(identityelement_exist(G,c,n))
			{
				if(inverse_exist(G,c,n))
					return 1;
				else
					return 0;
			}
			else
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}
int is_closure(int G[],char c,int n)
{
	int i,j;
	switch(c)
	{
		case '*':
			for ( i = 0; i < n; i++)
			{
				for ( j = 0; j < n; j++)
				{
					if(!(inG(G,n,G[i]*G[j])))
						return 0;
				}
			}
			break;
		case '+':
			for ( i = 0; i < n; i++)
			{
				for ( j = 0; j < n; j++)
				{
					if(!(inG(G,n,G[i]+G[j])))
						return 0;
				}
			}
			break;
		case '|':
			for ( i = 0; i < n; i++)
			{
				for ( j = 0; j < n; j++)
				{
					if(!(inG(G,n,G[i]%G[j])))
						return 0;
				}
			}
			break;
		case '/':
			for ( i = 0; i < n; i++)
			{
				for ( j = 0; j < n; j++)
				{
					if(G[i] == 0 || G[j]==0)
						return 0;
					if(!(inG(G,n,G[i]/G[j])))
						return 0;
				}
			}
			break;
		case '-':
			for ( i = 0; i < n; i++)
			{
				for ( j = 0; j < n; j++)
				{
					if(!(inG(G,n,G[i]-G[j])))
						return 0;
				}
			}
			break;
		default :
			return 0;
			break;
	}
	return 1;
}
int associativity_satisfied(int G[],char c,int n)
{
	int i,j,k;
	switch(c)
	{
		case '*':
			return 1;
			break;
		case '+':
			return 1;
			break;
		case '|':
			for ( i = 0; i < n; i++)
			{
				for ( j = 0; j < n; j++)
				{
					for (k = 0; k < n; k++)
					{
						if(((G[i]%G[j])%G[k])!=(G[i]%(G[j]%G[k])))
							return 0;
					}
				}
			}			
			break;
		case '/':
			if(!(n==1 && G[0]==1))
				return 0;
			break;
		case '-':
			if(!(n==1 && G[0]==0))
				return 0;
			break;
		default :
			return 0;
			break;
	}
	return 1;
}
int identityelement_exist(int G[],char c,int n)
{
	switch(c)
	{
		case '*':
			if(inG(G,n,1))
			{
				return 1;
			}	
			else
			{
				return 0;
			}		
			break;
		case '+':
			if(inG(G,n,0))
				return 1;
			else
				return 0;
		case '/':
			if(!(n==1 && G[0]==1))
				return 0;
			break;
		case '-':
			if(!(n==1 && G[0]==0))
				return 0;
			break;
		default :
			return 0;
			break;
	}
	return 1;
}
int inverse_exist(int G[],char c,int n)
{
	int i;
	switch(c)
	{
		case '*':
			if(!(n==1 && G[0]==1))
				return 0;
			break;
		case '/':
			if(!(n==1 && G[0]==1))
				return 0;
			break;
		case '+':
			if(!(n==1 && G[0]==0))
				return 0;
			break;
		case '-':
			if(!(n==1 && G[0]==0))
				return 0;
			break;
		default :
			return 0;
			break;
	}
	return 1;
}
int inG(int G[],int n,int ele)
{
	int y=0,i;
	for (i = 0; i < n; i++)
	{
		if(G[i]==ele)
		{
			y=1;
			break;
		}
	}
	return y;
}