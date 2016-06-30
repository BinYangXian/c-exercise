#include<stdio.h>
int main()
{
	int poly0[101][2],poly1[101][2];
//	for(int n=0;n<2;n++)
//	{
//		for(int i=0;i<101;i++)
//		{
//			for(int j=0;j<2;j++)
//			{
//				if(n==0)
//					poly0[i][j]=1;
//				else 
//					poly1[i][j]=1;		
//			}
//		}
//	}
	int max0,max1;
	for(int n=0;n<2;n++)
	{
		for(int i=0;i<101;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(n==0)
					scanf("%d",&poly0[i][j]);
				else 
					scanf("%d",&poly1[i][j]);
			}
			if(n==0)
			{
				if(poly0[i][1]==0)
					i--;
				else if(poly0[i][0]==0)
				{
					max0=i+1;
					break;
				}
			}
			else
			{
				if(poly1[i][1]==0)
					i--;
				else if(poly1[i][0]==0)
				{
					max1=i+1;
					break;	
				}
			} 
		}
	}
		int f;
		f=max0-1;
		for(f;f>0;f--)
		{
			for(int i=f;i>0;i--)
			{
				if(poly0[i][0]>poly0[i-1][0])
				{
					for(int j=0;j<2;j++)
					{
					int t=poly0[i][j];
					poly0[i][j]=poly0[i-1][j];
					poly0[i-1][j]=t;}
				}
				
			}			
		}
		f=max1-1;
		for(f;f>0;f--)
		{
			for(int i=f;i>0;i--)
			{
				if(poly1[i][0]>poly1[i-1][0])
				{
					for(int j=0;j<2;j++)
					{
					int t=poly1[i][j];
					poly1[i][j]=poly1[i-1][j];
					poly1[i-1][j]=t;}
				}
			}		
		}


	for(int y=0;y<max1;y++)
	{
		int output=0;
		for(int n=0;n<2;n++)
		{		
			int equ=0;
			for(int i=0 ;i<max0;i++)
			{
				if(poly0[i][0]==poly1[y][0])
				{
					equ++;
					output++;
					if(output==1)
					{
						if(poly0[i][0]==1)
						{
							printf("%dx+",poly0[i][1]+poly1[y][1]);
						}
						else
						{
							if(poly0[i][0]!=0)
							{
								printf("%dx%d+",poly0[i][1]+poly1[y][1],poly0[i][0]);
							}
							else 
							{
								printf("%d",poly0[i][1]+poly1[y][1]);
							}	
						}
						break;
					}
					else break;
					
				}	
			}
			if(equ==0)
				printf("%dx%d+",poly0[y][1],poly0[y][0]);
			{
				int t;
				t=max1;
				max1=max0;
				max0=t;
				int temp[101][2];
				for(int n=0;n<3;n++)
				{
					for(int i=0;i<101;i++)
					{
						for(int j=0;j<2;j++)
						{
							if(n==0)
								temp[i][j]=poly1[i][j];
							else if(n==1)
								poly1[i][j]=poly0[i][j];
							else poly0[i][j]=temp[i][j];	
						}
					}
				}
			}
		}
	}
	return 0;
}