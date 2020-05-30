#include <stdio.h>
#include <stdlib.h>
void Bubblesort(int arr[], int n);
int find(int *arr,int n,int x);
void swap(int *xp, int *yp);
int supremum(int arr[][20],int n_ele);
int infinum(int arr[][20],int n_ele);
int isAntiSymmetrical(int arr[][20],int n_ele);
int isReflexive(int arr[][20],int n_ele);
int isTransitive(int arr[][20],int n_ele);
void print_2d_array(int a[][20],int rows) {
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < rows; ++j) 
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char const *argv[])
{
	int i,j,n_ele,n_rel,set[20],arr[20][20],min=2000,max=-2000,temp1,temp2,a=-1,b=-1;
	int antisymmetrical,reflexive,transitive,sup,inf;
	printf("Name - Naman Taneja and Roll no. - 2019UCO1640\n");
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			arr[i][j] = 0;
		}
	}
	printf("Relation R  is defined on set A containing ____ elements .\n");
	scanf("%d",&n_ele);
	printf("Enter the set A as space seperated distinct values :\n");
	for (i = 0; i < n_ele; ++i)
	{
		scanf("%d",&set[i]);
		min = min<set[i]?min:set[i];
		max = max>set[i]?max:set[i];
	}
	Bubblesort(set,n_ele);
	printf("Number of relations we have are _____ . \n");
	scanf("%d",&n_rel);
	printf("Enter %d relations as two space seperated values from your set\n",n_rel);
	for (i = 0; i < n_rel; i++)
	{
		while(a==-1 || b==-1)
		{
			scanf("%d",&temp1);
			scanf("%d",&temp2);
			a=find(set,n_ele,temp1);
			b=find(set,n_ele,temp2);
			if(a==-1 || b==-1)
			{
				printf("You eneterd wrong values please check again and retype\n");
			}
			else
			{
				if(arr[a][b]==0)
				{
					arr[a][b] = 1;
				}
				else
				{
					printf("This relation has already bean marked. Type the different relatio\n");
					a=-1;
					b=-1;
				}
			}
		}
		a=-1;
		b=-1;
	}
	antisymmetrical = isAntiSymmetrical(arr,n_ele);
	reflexive = isReflexive(arr,n_ele);
	transitive = isTransitive(arr,n_ele);
	if(antisymmetrical && reflexive && transitive)
	{
		printf("(A,R) is a POSET ");
		sup = supremum(arr,n_ele);
		inf = infinum(arr,n_ele);
		if(sup && inf)
		{
			printf("and a Lattice\n");
		}
		else
		{
			printf("but not a Lattice\n");
		}

	}
	else
	{
		printf("Sorry,but (A,R) isn't even a POSET\n");
	}
	return 0;
}
void Bubblesort(int arr[], int n)
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++) 
			if (arr[j] > arr[j+1]) 
				swap(&arr[j], &arr[j+1]);
}
void swap(int *xp, int *yp)
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
}
int find(int *arr,int n,int x)
{
	int min,max,mid;
	min=0;
	max=n-1;
	
	while(min<=max)
	{
		mid=(min+max)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid]>x)
		{
			max=mid-1;
		}
		else
		{
			min=mid+1;
		}
	}
	return -1;
}
int supremum(int arr[][20],int n_ele)
{
	int i,j,a,t=0;
	for (i = 0; i < n_ele; i++)
	{
		for (j = 0; j < n_ele; ++j)
		{
			t=0;
			if(arr[i][j]==0 && arr[j][i]==0)
			{
				for (int a = 0; a < n_ele; a++)
				{
					if(arr[i][a] ==1 && arr[j][a]==1)
					{
						t=1;
					}
				}
				if(t==0)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
int infinum(int arr[][20],int n_ele)
{
	int i,j,a,t=0;
	for (i = 0; i < n_ele; i++)
	{
		for (j = 0; j < n_ele; ++j)
		{
			t=0;
			if(arr[i][j]==0 && arr[j][i]==0)
			{
				for (int a = 0; a < n_ele; ++a)
				{
					if(arr[a][i] ==1 && arr[a][j]==1)
					{
						t=1;
					}
				}
				if(t==0)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
int isAntiSymmetrical(int arr[][20],int n_ele)
{
	int i,j,temp=0;
	for ( i = 0; i < n_ele; i++)
	{
		for ( j = 0; j < n_ele; j++)
		{
			if(arr[i][j]==1 && arr[j][i]==1)
			{
				if(i!=j)
				{
					return 0;
				}
			}
		}
	}
	return 1;	
}
int isReflexive(int arr[][20],int n_ele)
{
	int i,j;
	for ( i = 0; i < n_ele; i++)
	{
		if(arr[i][i]!=1)
		{
			return 0;
		}
	}
	return 1;
}
int isTransitive(int arr[][20],int n_ele)
{
	int i,j,t,mul[20][20];
	for(i=0;i<n_ele;i++)
	{
		for(j=0;j<n_ele;j++)
		{
			mul[i][j]=0;
		}
	}
	for ( i = 0; i < n_ele; i++)
	{
		for ( j = 0; j < n_ele; j++)
		{
			for(t=0;t<n_ele;t++)
			{
				mul[i][j]=mul[i][j]+arr[i][t]*arr[t][j];
			}
		}
	}
	for(i=0;i<n_ele;i++)
	{
		for(j=0;j<n_ele;j++)
		{
			if(arr[i][j])
			{
				if(!mul[i][j])
				{
					return 0;
				}
			}
		}
	}
	return 1;
}