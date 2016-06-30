#include<stdio.h>
#include<string.h>
char *mycat(char *s1,const char *s2);
int main(int agrc,char const *agrv[])
{
//	char s[80]={};
	char s1[]="Hello ";
//	printf("%d",strlen(s1));
	const	char *s2="World";
	mycat(s1,s2);
//	cat(s,s2); 
	printf("%s",s1);
	printf(" %d",strlen(s1));
	printf(" %d",sizeof(s1));
}
char *mycat(char *s1,const char *s2)
{
	char *p=s1;
	while(*s1!='\0')
		s1++;	
	while(*s2!='\0')
		*s1++=*s2++;
	*s1='\0';
	return p;
}
