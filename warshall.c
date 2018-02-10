/*
 Find the transitive closure of a given directed graph (digraph). The digraph is given in the form of a
 adjacency matrix and the transitive closure of the graph is expected in the matrix form.
 Warshall's algorithm
 */

#include<stdio.h>

void warshall(int[][100],int);
void display(int[][100],int);

int main()
{
    int t,n,graph[100][100],i,j;
    
    scanf("%d",&t);
    
    while(t>0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&graph[i][j]);
            }
        }
        
        
        warshall(graph,n);
        display(graph,n);
        t--;
    }
    return 0;
}

void warshall(int graph[100][100],int n)
{
    int i,j,k;
    
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                graph[i][j]=graph[i][j]||(graph[i][k] && graph[k][j]);
            }
        }
    }
}

void display(int graph[100][100],int n)
{
    int  i,j;
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d  ",graph[i][j]);
        }
        printf("\n");
    }
}
