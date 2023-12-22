#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
 
using namespace std;

void swap(int &a, int &b)
{
	int c=a;
	a=b;
	b=c;
}

void sapxep(int arr[],int brr[], int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=i+1; j<size; j++)
		{
			if((float)(arr[i]/brr[i])<(float)(arr[j]/brr[j]))
			{
				swap(arr[i], arr[j]);
				swap(brr[i], brr[j]);
			}
		}
	}
}

void thamlam(int giatri[], int khoiluong[], int toida, int size)
{
	int tonggiatri= 0;
	int tongkhoiluong = 0;
	for(int i = 0; i < size; i++)
	{
		if(khoiluong[i]+tongkhoiluong <= toida)
		{
			tongkhoiluong+= khoiluong[i];
			tonggiatri += giatri[i];
		}
	}
	cout<<"Khoiluong = "<<tongkhoiluong<<", giatri = "<<tonggiatri;
}

void thamlam3(int giatri[], int khoiluong[], int toida, int size)
{
	sapxep(giatri,khoiluong, size);
	thamlam(giatri,khoiluong,toida,size);
}

// ------------------ Input
void input(int arr[], int size)
{
	for(int i = 0; i< size; i++)
		arr[i] = rand()%(size+1-1)+1;		
}

void print(int arr[], int size)
{
	for(int i = 0; i< size; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int toida = 50;
	int size = 20;
	
	int giatri[size];
	int khoiluong[size];
	// Random value
	input(giatri,size);
	input(khoiluong,size);
	
	cout<<"Gia tri   : ";
	print(giatri,size);
	cout<<"Khoi luong: ";
	print(khoiluong, size);
	cout<<"Su dung tham lam theo ti gia do vat duoc: "<<endl;
	thamlam3(giatri,khoiluong,toida,size);
	return 0;
}
