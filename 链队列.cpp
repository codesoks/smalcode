#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	int u=0;
	while(n)
	{
		n=n&(n-1);
		u++;
	}
	printf("%d",u);
	return 0;	
}