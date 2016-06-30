#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void mycmp(char *s1,char *s2);
int n1,n2,flag=1;
int main(int agrc,char const *agrv[])
{
	char s1[10000]="";
	char s2[10000]="";
	gets(s1);
	gets(s2);
	n1=strlen(s1);
	n2=strlen(s2); 
	mycmp(s1,s2);
	return 0;
}
void mycmp(char *s1,char *s2)
{
	int k=0;
	int i,j;
	while(k<=n2-n1)
	{
		i=0;
		j=k;
		while(s1[i]!='\0'&&s1[i]==s2[j])
		{
			i++;
			j++;
		}
		if(i==n1)
		{
			printf("%d ",k);
			flag=0;
		}
		k++;
	} 
	if(flag)
		printf("-1");
}
