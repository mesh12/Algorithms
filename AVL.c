/*
 Author: shobhana ganesh
 Question : http://www.spoj.com/problems/PESADA09/
 Program to check if the given binary search tree is an AVL tree
 */

#include<stdio.h>

int isBalanced(int[],int,int);
int getLeft(int);
int getRight(int);
int height(int[],int,int);

int main()
{
	int a[100],t,n,i,res,k;
	
	scanf("%d",&t);
	for(i=0;i<100;i++)
	{
		a[i]=-1;
	}
	while(t>0)
	{
		k=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		res=isBalanced(a,n,k);
		if(res==0)
		printf("F\n");
		else
		printf("T\n");
		t--;
	}
	return 0;
}

int isBalanced(int a[100],int n,int k)
{
	int i,j,k1;
	//i=left child
	//j=right child
	
	if (k>=100)
      return 1;
      
	if(a[k]==-1)
	return 1;
	
	k1=k;
	i=height(a,n,getLeft(k));
	k=k1;
	j=height(a,n,getRight(k));
	
	if( ( (i-j)==1||(i-j)==-1||(i-j)==0) && isBalanced(a,n,getLeft(k)) && isBalanced(a,n,getRight(k)) )
	{
		return 1;
	}
	
	return 0;
	
	
}

int getLeft(int pos)
{
	return ((2*pos)+1);
}
	
int getRight(int pos)
{
	return ((2*pos)+2);
}

int height(int a[100],int n,int k)
{
	int left,right;
	
	if(k>=n)
      return 0;
      
	if(a[k]==-1)
	{
		return 0;
	}
	
	else
	{
		left=height(a,n,getLeft(k));
		right=height(a,n,getRight(k));
		
		if(left>right)
		return left+1;
		
		else
		return right+1;
	}
		
}
