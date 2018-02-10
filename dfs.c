/*
 Depth first search
 */

#include<stdio.h>

void dfs(int[][100],int[],int);
void depth(int[][100],int[],int,int);
int count;

int main()
{
	int graph[100][100],t,i,j,n,v[100];
	
	scanf("%d",&t); // number of test cases
	
	while(t>0)
	{
		scanf("%d",&n); // order of adjacency matrix
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&graph[i][j]);
			}
		}
		dfs(graph,v,n);
		printf("\n");
		t--;
	}
	
	return 0;
}


void dfs(int graph[100][100],int v[100],int n)
{
	int i,count;
	count=0;
	
	for(i=0;i<n;i++)
	{
		v[i]=2;
	}
	
	for(i=0;i<n;i++)
	{
		if(v[i]==2)//2 for not visited
		{
			depth(graph,v,i,n);
			count++;	
		}
	}
	printf("%d",count);
}

void depth(int graph[100][100],int v[100],int i,int n)
{
	int j;
	
	v[i]=3;//3 for vertex visited and processing
	
	for(j=0;j<n;j++)
	{
		if(v[j]==2 && graph[i][j]==1)
		depth(graph,v,j,n);
	}
	
	v[j]=4;//4 for dead end and done processing
}
