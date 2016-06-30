#include<stdio.h>
main()
{
	int i,j;
	float s[5],t;
	printf("enter 5 numbers:\n");
	for(i=0;i<5;i++)
			scanf("%f",&s[i]);
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(s[j]<s[i])
			{
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	for(i=0;i<5;i++)
		printf("%10.5f\n",s[i]);
}

