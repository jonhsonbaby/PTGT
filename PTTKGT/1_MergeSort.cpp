#include<iostream>
#define max 100
using namespace std;

void merge(int a[], int head, int mid, int tail)
{
	int arr1[max];
	int arr2[max];
	// Lay du lieu hai mang can ghep
	for(int i = 0; i <= (mid-head); i++)
		arr1[i]=a[head+i];
	for(int j = 0; j <= (tail-mid-1); j++)
		arr2[j]=a[mid+1+j];
	int k = head;
	int i = 0;
	int j = 0;
	// Noi hai mang
	while(i<=(mid-head) && j<=(tail-mid-1))
	{
		if(arr1[i]>arr2[j])
		{
			a[k]=arr2[j];
			j++;
		}
		else
		{
			a[k]=arr1[i];
			i++;
		}
		k++;
	}
	while(i<=(mid-head))
	{
		a[k]= arr1[i];
		i++;
		k++;
	}
	while(j<=(tail-mid-1))
	{
		a[k]= arr2[j];
		j++;
		k++;
	}
}

void mergesort(int a[], int head, int tail)
{
	if(head<tail)
	{
		int mid = (head+tail)/2;
		mergesort(a,head,mid);
		mergesort(a,mid+1,tail);
		
		merge(a, head, mid, tail);
	}
}

void print(int a[], int size)
{
	for(int i = 0 ; i < size; i++)
		cout<<a[i]<<" ";
	cout<<endl;	
}

int main()
{
	int arr[] = {9,8,7,6,5,4,3,2,1};
	mergesort(arr,0,8);
	print(arr,9);
	return 0;
}
