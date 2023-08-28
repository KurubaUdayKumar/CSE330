#include<iostream>
using namespace std;

void merge(int array[],int left,int right,int mid)
{
	int n1 = mid-left+1;
	int n2 = right-mid;
	
	int *leftArray = new int[n1];
	int *rightArray = new int[n2];
	
	for(int i=0;i<n2;i++)
	{
		leftArray[i] = array[left+i];
	}
	for(int i=0;i<=n2;i++)
	{
		rightArray[i] = array[mid+1+i];
	}
	int i=0;
	int j=0;
	int k=left;
}
