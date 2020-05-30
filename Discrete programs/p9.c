#include<stdio.h>
#include <stdlib.h>
float get_nth_term(float a[],float coef[],int order,int term,int t);
int main(int argc, char const *argv[])
{
	int order,i,n,term,t;
	float coef[20],coef_new[20],a[150],result;
	printf("Name - Naman Taneja and Roll no. - 2019UCO1640\n");
	printf("Type the order of equation to solve : ");
	scanf("%d",&order);
	printf("Type the initial conditions\n");
	for(i=0;i<order;i++)
	{
		printf("a%d = ",i);
		scanf("%f",&a[i]);
	}
	printf("Type coefficinets of %d terms i.e nth,(n-1)th,........... in recurrence relation\n",(order+1));
	for(i=0;i<=order;i++)
	{
		scanf("%f",&coef[i]);
	}
	coef_new[0]=1;
	for(i=1;i<=order;i++)
	{
		coef_new[i] = (coef[i]/coef[0])*(-1);
	}
	printf("How many values do you want to get : ");
	scanf("%d",&n);
	t=order;
	for(i=0;i<n;i++)
	{
		printf("Type the value of k to get the kth term (k starts form 0) : k = ");
		scanf("%d",&term);
		result = get_nth_term(a,coef_new,order,term,t);
		t=order>=term?order:term;
		printf("a%d = %.2f \n",term,result);

	}
	return 0;
}
float get_nth_term(float a[],float coef[],int order,int term,int t)
{
	int i,k;
	if(term<t)
	{
		return a[term];
	}
	for(i=t;i<=term;i++)
	{
		a[i]=0;
		for(k=1;k<=order;k++)
		{
			a[i] = a[i]+a[i-k]*coef[k];
		}
	}
	return a[term];
}