#include <stdio.h> 
#include <stdlib.h>
int count(int a[], int n, int m);
int main() 
{ 
	int a[50],m,n,i;
	printf("Name - Naman Taneja and Roll no. - 2019UCO1640\n");
	printf("How many prime numbres do you want to enter : ");
	scanf("%d",&n);
	printf("Type %d distinct prime numbers :- \n",n);
	for(i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	printf("What is the last natural number you want to call for : ");
	scanf("%d",&m);
	printf("%d\n",count(a, n, m)); 
	return 0; 
} 
int count(int a[], int n, int m)
{ 
	int odd = 0, even = 0; 
	int counter, i, j, p = 1; 
	int pow_set_size = (1 << n); 
	for (counter = 1; counter < pow_set_size;counter++) 
	{ 
		p = 1; 
		for (j = 0; j < n; j++) 
		{ 

			// Check if jth bit in the 
			// counter is set If set 
			// then pront jth element from set 
			if (counter & (1 << j)) 
			{ 
				p *= a[j]; 
			} 
		} 

		// if set bits is odd, then add to 
		// the number of multiples 
		if (__builtin_popcount(counter) & 1) 
			odd += ( m / p ); 
		else
			even += ( m / p ); 
	}
	return odd - even; 
} 