#include <stdio.h>
#include <stdlib.h>
struct array
{
	int n;
	int arr[100];
};
void Bubblesort(int arr[], int n);
void swap(int *xp, int *yp);
struct array intersection(int *set1,int *set2,int n1,int n2);
struct array multisetsUnion(int *set1,int *set2,int n1,int n2);
struct array difference(int *set1,int *set2,int n1,int n2);
struct array symmetricDiff(int *set1,int *set2,int n1,int n2);
struct array addition(int *set1,int *set2,int n1,int n2);
int main(int argc, char const *argv[])
{
	int i,j,x;
	struct array s1,s2,s;
	printf("Name - Naman Taneja and Roll number - 2019UCO1640\n");
	printf("Enter the number of elements in multiset1 : ");
	scanf("%d",&s1.n);
	printf("Type %d elements of multiset1\n",s1.n);
	for(i=0;i<s1.n;i++)
	{
		scanf("%d",&s1.arr[i]);
	}
	Bubblesort(s1.arr,s1.n);
	printf("Enter the number of elements in multiset2 : ");
	scanf("%d",&s2.n);
	printf("Type %d elements of multiset2\n",s2.n);
	for(i=0;i<s2.n;i++)
	{
		scanf("%d",&s2.arr[i]);
	}
	Bubblesort(s2.arr,s2.n);
	printf("Multiset1 looks like : { ");
	for(i=0;i<s1.n;i++)
	{
		printf("%d",s1.arr[i]);
		if(i != s1.n-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
	printf("Multiet2 looks like : { ");
	for(i=0;i<s2.n;i++)
	{
		printf("%d",s2.arr[i]);
		if(i != s2.n-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");

	printf("Type any of the following numbers to get the corresponding result :-\n");
	printf("1. Intersection of multiset1 and multiset2\n");
	printf("2. Union of multiset1 and multiset2\n");
	printf("3. Difference of multiset1 and multiset2\n");
	printf("4. Symmetric Difference of multiset1 and multiset2\n");
	printf("5. Addition of multiset1 and multiset2\n");
	printf("6. Exit\n");
	while(1)
	{
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				s=intersection(s1.arr,s2.arr,s1.n,s2.n);
				printf("Intersection looks like : { ");
				for(i=0;i<s.n;i++)
				{
					printf("%d",s.arr[i]);
					if(i != s.n-1)
					{
						printf(", ");
					}
				}
				printf(" }\n");
				printf("Enter your next choice of operation\n");
				break;
			case 2:
				s=multisetsUnion(s1.arr,s2.arr,s1.n,s2.n);
				printf("Multisets Union looks like : { ");
				for(i=0;i<s.n;i++)
				{
					printf("%d",s.arr[i]);
					if(i != s.n-1)
					{
						printf(", ");
					}
				}
				printf(" }\n");
				printf("Enter your next choice of operation\n");
				break;
			case 3:
				printf("Type 1 for multiset1-multiset2 or 2 for multiset2-multiset1 : ");
				scanf("%d",&j);
				if(j==1)
				{
					s=difference(s1.arr,s2.arr,s1.n,s2.n);
				}
				else
				{
					s=difference(s2.arr,s1.arr,s2.n,s1.n);
				}
				printf("Set of required Difference looks like : { ");
				for(i=0;i<s.n;i++)
				{
					printf("%d",s.arr[i]);
					if(i != s.n-1)
					{
						printf(", ");
					}
				}
				printf(" }\n");
				printf("Enter your next choice of operation\n");
				break;
			case 4:
				s=symmetricDiff(s1.arr,s2.arr,s1.n,s2.n);
				printf("Set of Symmetric Difference looks like : { ");
				for(i=0;i<s.n;i++)
				{
					printf("%d",s.arr[i]);
					if(i != s.n-1)
					{
						printf(", ");
					}
				}
				printf(" }\n");
				printf("Enter your next choice of operation\n");
				break;
			case 5:
				s=addition(s1.arr,s2.arr,s1.n,s2.n);
				printf("Addition multiset looks like : { ");
				for(i=0;i<s.n;i++)
				{
					printf("%d",s.arr[i]);
					if(i != s.n-1)
					{
						printf(", ");
					}
				}
				printf(" }\n");
				printf("Enter your next choice of operation\n");
				break;
			case 6:
				exit(1);
				break;
			default:
				printf("Please enter a valid choice\n");
				break;

		}
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
struct array intersection(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0;
	struct array s;
	s.n=0;
	while(i<n1 && j<n2)
	{
		if(set1[i]>set2[j])
		{
			j++;
		}
		else if(set2[j]>set1[i])
		{
			i++;
		}
		else
		{
			s.arr[s.n]=set1[i];
			j++;
			i++;
			s.n++;
		}
	}
	return s;
}
struct array multisetsUnion(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0;
	struct array s;
	s.n=0;
	while(i<n1 && j<n2)
	{
		if(set1[i]>set2[j])
		{
			s.arr[s.n]=set2[j];
			j++;
			s.n++;
		}
		else if(set2[j]>set1[i])
		{
			s.arr[s.n]=set1[i];
			i++;
			s.n++;
		}
		else
		{
			s.arr[s.n]=set1[i];
			i++;
			j++;
			s.n++;
		}
	}
	while(i<n1)
	{
		s.arr[s.n]=set1[i];
		i++;
		s.n++;
	}
	while(j<n2)
	{
		s.arr[s.n]=set2[j];
		j++;
		s.n++;
	}
	return s;

}
struct array difference(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0;
	struct array s;
	s.n=0;
	while(i<n1 && j<n2)
	{
		if(set1[i]<set2[j])
		{
			s.arr[s.n] = set1[i];
			i++;
			s.n++;
		}
		else if(set1[i]>set2[j])
		{
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}
	while(i<n1)
	{
		s.arr[s.n]=set1[i];
		s.n++;
		i++;
	}
	return s;
}
struct array symmetricDiff(int *set1,int *set2,int n1,int n2)
{
	struct array s1,s2,s;
	s1=difference(set1,set2,n1,n2);
	s2=difference(set2,set1,n2,n1);
	s=multisetsUnion(s1.arr,s2.arr,s1.n,s2.n);
	return s;
}
struct array addition(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0;
	struct array s;
	s.n=0;
	while(i<n1 && j<n2)
	{
		if(set1[i]<set2[j])
		{
			s.arr[s.n]=set1[i];
			s.n++;
			i++;
		}
		else if(set1[i]>set2[j])
		{
			s.arr[s.n]=set2[j];
			s.n++;
			j++;
		}
		else
		{
			s.arr[s.n]=set1[i];
			i++;
			s.n++;
		}
	}
	while(i<n1)
	{
		s.arr[s.n]=set1[i];
		i++;
		s.n++;
	}
	while(j<n2)
	{
		s.arr[s.n]=set2[j];
		j++;
		s.n++;
	}
	return s;

}