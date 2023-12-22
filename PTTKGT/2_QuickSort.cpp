#include<iostream>
using namespace std;

int index(int arr[], int first, int last)
{
	int j = first;
	int c;
	for(int i = first; i < last; i++)
	{
		if(arr[i]<arr[last])
		{
			swap(arr[i],arr[j]);
			j++;
		}
	}
	swap(arr[last],arr[j]);
	return j;
}

void quicksort(int arr[], int first, int last)
{
	if(first<=last)
	{
		int next = index(arr,first, last);
		quicksort(arr, first, next-1);
		quicksort(arr, next+1, last);
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
	int arr[] = {8,7};
	quicksort(arr,0,1);
	print(arr,2);
	return 0;
}
