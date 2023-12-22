#include <bits/stdc++.h>
using namespace std;
const int oo = 1000;
int a[1000][1000];
int n;
int next1[1000][100];

int main() 
{
	// Lay du lieu tu file
    fstream infile;
    infile.open("input1.txt");
    infile >> n;
   	memset(next1, INT_MAX, sizeof next1);
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= n; j++) 
		{
            infile >> a[i][j];
            if (a[i][j] == 0 && i != j) 
				a[i][j] = oo;
			if (a[i][j] != oo && a[i][j] != 0)
			{ // Co duong di giua i va j
				next1[i][j] = j;
			}
        }
    }
    infile.close();
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
			{
            	if((a[i][j] >  a[i][k] + a[k][j]) && (a[i][k] != oo) && (a[k][j] != oo))
				{
            		a[i][j] = a[i][k] + a[k][j];
                	next1[i][j] = next1[i][k];
            	}
            }
            
    cout << "Ma tran khoang cach: \n";
    for (int i = 1; i <= n; i++)
	{
        for (int j = 1; j <= n; j++)
		{
        	cout << a[i][j] << " ";
    	}
    	cout << endl;
    }   
    
//  Hien thi toan bo duong di    
    for(int i = 1; i <= n; i++)
	{
    	for(int j = 1; j <= n; j++)
		{
    		if (i != j)
			{
    			cout << "Duong " << i << " toi " << j <<": ";
    			for(int tmp = i; tmp != j; tmp = next1[tmp][j])
				{
    				cout << tmp << " ";
				}
			cout << j << endl;
			}
		}
	}

//	int i, j;
//	cout <<"\nHien thi duong di tu "; cin >> i; cout<<"Den "; cin >> j;
//	cout << "Duong " << i << " toi " << j <<": ";
//   	for(int tmp = i; tmp != j; tmp = next1[tmp][j])
//	{
//   		cout << tmp << " ";
//	}
//	cout << j;
}
