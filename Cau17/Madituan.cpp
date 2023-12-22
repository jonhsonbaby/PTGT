#include<iostream>
using namespace std;
int a[8]= {-1,-2,-2,-1,1,2,2,1};
int b[8]= {2,1,-1,-2,-2,-1,1,2};
int h[8][8];
void print()
{
	for(int i = 0; i < 5;i++)
	{
		for(int j = 0 ;  j < 5; j++)
		{
			cout << h[i][j]<<" ";
		}
		cout<<endl;	
	}
}
void trydo(int i, int x, int y, int n)
{
	int u,v;
	for(int k = 0; k < 8; k++)
	{
		u = x+a[k];
		v = y+b[k];
		if(h[u][v] ==0 && u<n && u >=0 && v<n && v >=0)
		{
			h[u][v] = i;
			if(i<n*n)
				trydo(i+1,u,v,n);
			else
			{
				print();
				getchar();
			}	
			// Sau khi in xong tra lai vi tri de lay truong hop tiep theo
			h[u][v] = 0;
		}
	}
}
int main()
{
	for(int i = 0; i < 5;i++)
		for(int j = 0 ;  j < 5; j++)
			h[i][j] = 0;
	trydo(1,1,2,5);
	return 0;
}

