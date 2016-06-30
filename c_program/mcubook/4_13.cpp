#include<stdio.h>
void main()
{

	unsigned char table[5],i,j,temp;
	printf("input three numble:\n");
	for(i=0;i<5;i++)
		scanf("\n%d",&table[i]);
	for(j=0;j<4;j++)	
		for(i=0;i<4-j;i++)
			if(table[i]>table[i+1])
			{
				temp=table[i];
				table[i]=table[i+1];
				table[i+1]=temp;
			}
	printf("output %d,%d,%d,%d,%d\n",table[0],table[1],table[2],table[3],table[4]);

}