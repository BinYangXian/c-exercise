#include<stdio.h>
#include <stdlib.h>
struct date{ int x; int y; } x;
struct date2{ int x; int y;} y;
int main(int argc,char const *agrv[])
{
x={1,13};
 y={13,13};
	printf("%d=%d+%d+%d",sizeof(x),sizeof(char),sizeof(int),sizeof(long long));
//	printf("%d",&x.fen-&x.ci);
	return 0;
}
