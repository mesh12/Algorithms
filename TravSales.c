/*
 Travelling salesman problem
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void permute(int,int,int[],int[30][30]);
void swap(int,int,int[]);
int r=0;

int main()
{
	int i,j,t,t1,sum,distance[50],c[50][50],array[50],a[30][30],min;
	char city[50][50]={"A","B","C","D","E"},ct[50],ct1[50];
	min=123456;
	int weight[5][5];
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				weight[i][j]=0;
			}
			
			else
			scanf("%d",&weight[i][j]);
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",weight[i][j]);
		}
		
		printf("\n");
	}
	
	for(i=0;i<5;i++)
	{
		array[i]=i;
	}
	
	printf("\n\n");
	j=0;
	permute(3,3,array,a);
	
	for(i=0;i<r;i++)
	{
		sum=0;
		
		for(j=0;j<3;j++)
		{
			t1=t;
			t=a[i][j];
			printf("%s\t",city[t]);
			ct[j]=city[i][t];
			if(j!=0)
			{
				sum+=weight[t1][t];
			}
		}
		if(sum<min)
		{
			min=sum;
			strcmp(ct1,ct);
		}
		printf("\n");
		distance[i]=sum;
	}
	
	printf("\n%d\t%s\n",min,ct1);
	
	
}

void permute(int k,int size,int array[50],int a[30][30])
{
    int i;

    if (k==0)
        {
        	for (i=0;i<size;i++)
		{
			a[r][i]=array[i];
		}
		r++;
        }
    else{
        for(i=k-1;i>=0;i--)
        {
            swap(i,k-1,array);
            permute(k-1,size,array,a);
            swap(i,k-1,array);
        }
    }

    return;
}

void swap(int x, int y,int array[50])
{
    int temp = array[x];
    array[x]=array[y];
    array[y]=temp;

    return;
}


