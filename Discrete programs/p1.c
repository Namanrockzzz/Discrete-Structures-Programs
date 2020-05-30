#include <stdio.h>
#include <stdlib.h>
struct array
{
	int n;
	int arr[200];
};
struct array delDuplicates(int *arr,int n);
void Bubblesort(int arr[], int n);
void swap(int *xp, int *yp);
int BinarySearch(int *arr,int n,int x);
void intersection(int *set1,int *set2,int n1,int n2);
void setsunion(int *set1,int *set2,int n1,int n2);
void difference(int *set1,int *set2,int n1,int n2);
void symmetricDiff(int *set1,int *set2,int n1,int n2);
void addition(int *set1,int *set2,int n1,int n2);
void subtraction(int *set1,int *set2,int n1,int n2);
int main(int argc, char const *argv[])
{
	int set1[100],set2[100],i,j,x,n1,n2;
	struct array s1,s2;
	printf("Name - Naman Taneja and Roll number - 2019UCO1640\n");
	printf("Enter the number of elements in set1 : ");
	scanf("%d",&n1);
	printf("Type %d elements of set1\n",n1);
	for(i=0;i<n1;i++)
	{
		scanf("%d",&set1[i]);
	}
	Bubblesort(set1,n1);
	s1=delDuplicates(set1,n1);
	printf("Enter the number of elements in set2 : ");
	scanf("%d",&n2);
	printf("Type %d elements of set2\n",n2);
	for(i=0;i<n2;i++)
	{
		scanf("%d",&set2[i]);
	}
	Bubblesort(set2,n2);
	s2=delDuplicates(set2,n2);
	printf("Set1 looks like : { ");
	for(i=0;i<s1.n;i++)
	{
		printf("%d",s1.arr[i]);
		if(i != s1.n-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
	printf("Set2 looks like : { ");
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
	printf("1. Intersection of set1 and set2\n");
	printf("2. Union of set1 and set2\n");
	printf("3. Difference of set1 and set2\n");
	printf("4. Symmetric Difference of set1 and set2\n");
	printf("5. Addition of set1 and set2\n");
	printf("6. Subtraction of set1 and set2\n");
	printf("7. Exit\n");
	while(1)
	{
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				intersection(s1.arr,s2.arr,s1.n,s2.n);
				printf("Enter your next choice of operation\n");
				break;
			case 2:
				setsunion(s1.arr,s2.arr,s1.n,s2.n);
				printf("Enter your next choice of operation\n");
				break;
			case 3:
				printf("Type 1 for set1-set2 or 2 for set2-set1 : ");
				scanf("%d",&j);
				if(j==1)
				{
					difference(s1.arr,s2.arr,s1.n,s2.n);
				}
				else
				{
					difference(s2.arr,s1.arr,s2.n,s1.n);
				}
				printf("Enter your next choice of operation\n");
				break;
			case 4:
				symmetricDiff(s1.arr,s2.arr,s1.n,s2.n);
				printf("Enter your next choice of operation\n");
				break;
			case 5:
				addition(s1.arr,s2.arr,s1.n,s2.n);
				printf("Enter your next choice of operation\n");
				break;
			case 6:
				printf("Type 1 for subtraction of set2 from set1 or 2 for subtraction of set1 from set2 : ");
				scanf("%d",&j);
				if(j==1)
				{
					subtraction(s1.arr,s2.arr,s1.n,s2.n);
				}
				else
				{
					subtraction(s2.arr,s1.arr,s2.n,s1.n);
				}
				printf("Enter your next choice of operation\n");
				break;
			case 7:
				exit(1);
				break;
			default:
				printf("Please enter a valid choice\n");
				break;

		}
	}

	return 0;
}
struct array delDuplicates(int *arr,int n)
{
	int i=0,temp;
	struct array s;
	s.n=0;
	while(i<n)
	{
		if(i<n-1)
		{
			s.arr[s.n]=arr[i];
			s.n++;
			temp = arr[i];
			while(temp==arr[i])
			{
				i++;
			}		
		}
		else
		{
			if(arr[i]==arr[i-1])
			{
				i++;
			}
			else
			{
				s.arr[s.n]=arr[i];
				s.n++;
				i++;
			}
		}

	}
	return s;
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
int BinarySearch(int *arr,int n,int x)
{
	int min,max,mid;
	min=0;
	max=n-1;
	
	while(min<=max)
	{
		mid=(min+max)/2;
		if(arr[mid]==x)
		{
			return 1;
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
	return 0;
}
void intersection(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0,k=0,set3[200];
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
			while(set1[i]==set2[j])
			{
				set3[k]=set1[i];
				i++;
				k++;
			}
		}
	}
	printf("Intersection looks like : { ");
	for(i=0;i<k;i++)
	{
		printf("%d",set3[i]);
		if(i != k-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");

}
void setsunion(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0,k=0,set3[200];
	while(i<n1 && j<n2)
	{
		if(set1[i]>set2[j])
		{
			set3[k]=set2[j];
			j++;
			k++;
		}
		else if(set2[j]>set1[i])
		{
			set3[k]=set1[i];
			i++;
			k++;
		}
		else
		{
			set3[k]=set1[i];
			i++;
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		set3[k]=set1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		set3[k]=set2[j];
		j++;
		k++;
	}
	printf("Union looks like : { ");
	for(i=0;i<k;i++)
	{
		printf("%d",set3[i]);
		if(i != k-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");

}
void difference(int *set1,int *set2,int n1,int n2)
{
	int i=0,k=0,set3[200];
	while(i<n1)
	{
		if(BinarySearch(set2,n2,set1[i])==1)
		{
			i++;
		}
		else
		{
			set3[k]=set1[i];
			k++;
			i++;
		}
	}
	printf("Set of required Difference looks like : { ");
	for(i=0;i<k;i++)
	{
		printf("%d",set3[i]);
		if(i != k-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
}
void symmetricDiff(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0,k=0,k3=0,k4=0,set3[200],set4[200],set5[200];
	while(i<n1)
	{
		if(BinarySearch(set2,n2,set1[i])==1)
		{
			i++;
		}
		else
		{
			set3[k3]=set1[i];
			k3++;
			i++;
		}
	}
	i=0;
	while(i<n2)
	{
		if(BinarySearch(set1,n1,set2[i])==1)
		{
			i++;
		}
		else
		{
			set4[k4]=set2[i];
			k4++;
			i++;
		}
	}
	i=0;
	j=0;
	while(i<k3 && j<k4)
	{
		if(set3[i]>set4[j])
		{
			set5[k]=set4[j];
			j++;
			k++;
		}
		else if(set4[j]>set3[i])
		{
			set5[k]=set3[i];
			i++;
			k++;
		}
		else
		{
			set5[k]=set3[i];
			i++;
			j++;
			k++;
		}
	}
	while(i<k3)
	{
		set5[k]=set3[i];
		i++;
		k++;
	}
	while(j<k4)
	{
		set5[k]=set4[j];
		j++;
		k++;
	}
	printf("Set of Symmetric Difference looks like : { ");
	for(i=0;i<k;i++)
	{
		printf("%d",set5[i]);
		if(i != k-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
}
void addition(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0,k=0,set3[200];
	struct array s;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			set3[k]=set1[i]+set2[j];
			k++;
		}
	}
	Bubblesort(set3,k);
	s=delDuplicates(set3,k);
	printf("Addition set looks like : { ");
	for(i=0;i<s.n;i++)
	{
		printf("%d",s.arr[i]);
		if(i != s.n-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
}
void subtraction(int *set1,int *set2,int n1,int n2)
{
	int i=0,j=0,k=0,set3[200];
	struct array s;
	for (i = 0; i < n1; i++)
	{
		for (j = 0; j < n2; j++)
		{
			set3[k]=set1[i]-set2[j];
			k++;
		}
	}
	Bubblesort(set3,k);
	s=delDuplicates(set3,k);
	printf("Subtraction set looks like : { ");
	for(i=0;i<s.n;i++)
	{
		printf("%d",s.arr[i]);
		if(i != s.n-1)
		{
			printf(", ");
		}
	}
	printf(" }\n");
}
