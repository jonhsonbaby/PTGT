#include<iostream>
using namespace std;

void exchange(int arr[], int first, int last, int m)
{
	int j = 0;
	for(int i = first; i < first+m; i++)
	{
		swap(arr[i],arr[last-m+1+j]);
		j++;
	}
}

void doicho(int arr[], int first, int last, int m)
{
	if(m<=(last-first) && m != 0)
	{
		int len = last-first+1;
		if(m>(len-m))
		{
			exchange(arr,first,last,len-m);
			doicho(arr, first, first+m-1, 2*m-len);
		}
		else if(m<(len-m))
		{
			exchange(arr, first, last, m);
			doicho(arr, m+first, last, m);
		}
		else
		{
			exchange(arr, first, last, m);	
		}
	}
}

void print(int arr[], int size)
{
	for(int i = 0; i<size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	doicho(arr,0,7,4);
	print(arr,8);
	return 0;
}
