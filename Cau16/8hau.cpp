#include<iostream>
using namespace std;
// Mang a de luu gia tri cot da dat quan hau
// Mang b, c de luu gia tri cac duong cheo da dat hau
// Chua dat = 1; da dat = 0
void trydo(int i, int a[], int b[], int c[], int x[])
{
		for(int j = 0; j < 8; j++)
		{
			if(a[j] == 1 && b[i+j] == 1 && c[i-j+7] == 1)
			{
				x[i] = j;
				a[j] = 0;
				b[j+i] = 0;
				c[i-j+7] = 0;
				if(i < 7)
					trydo(i+1,a,b,c,x);
				else
				{
					for(int i = 0; i < 8; i++)
						cout<<x[i]+1<<" ";
					cout<<endl;
				}
				a[j] = 1; b[i+j] = 1; c[i-j+7] = 1;
			}
		}
}
int main()
{
	int a[8];
	int b[15];
	int c[15];
	for(int i = 0; i < 8; i++)
		a[i] = 1;
	for(int i = 0; i < 15; i++)
	{ 
		b[i] = 1; 
		c[i] = 1;
	}
	int x[8];
	trydo(0,a,b,c,x);
	return 0;
}
