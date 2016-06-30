#include<stdio.h>
main()
{
	int a[][3]={1,2,3,4,5,6};
	int b[][2]={7,8,9,10,11,12};
	int c[2][2],i,j,k,s;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			s=0;
			for(k=0;k<3;k++)
				s=s+a[i][k]*b[k][j];
		c[i][j]=s;
		}
	for(i=0;i<2;i++)
	{
		printf("\n");
		for(j=0;j<2;j++)
			printf("c[%d][%d]=%4d",i,j,c[i][j]);
	}
}