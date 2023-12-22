#include <bits/stdc++.h>
using namespace std;
#define Max 99999
int T[100][100];
int matrix[100][100];

// ham truy vet
vector<int> trace(int u, int v) {
    vector<int> path;
    do {
        path.push_back(v);
        v = T[u][v];
    } while (v != -1);
    path.push_back(u);
    return path;
}

int main()
{
	// khai bao
    fstream infile;
    infile.open("input1.txt");
    int size;
	infile >> size;
    for (int i = 1; i <= size; i++) 
	{
        for (int j = 1; j <= size; j++) 
		{
            infile >> matrix[i][j];
            if (matrix[i][j] == 0 && i != j) 
				matrix[i][j] = Max;
        }
    }
    infile.close();
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=size;j++)
		{
			T[i][j] = -1;
		}
	}
	
	// hien thi ma tran trong so
	cout<<"Ma tran trong so:";
	for(int i=1; i<=size; i++)
	{
		cout<<endl;
		for(int j=1; j<=size; j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
	}
	
//	// Thuat toan floy
	for(int k=1; k<=size;k++)
	{
		for(int i=1; i<=size; i++)
		{
			for(int j=1; j<=size; j++)
			{
				if(matrix[i][j]>matrix[i][k]+matrix[k][j])
				{
					matrix[i][j] = matrix[i][k]+matrix[k][j];
					T[i][j] = k;
				}
					
			}
		}
	}

	//Ma tran chua  duong di ngan nhat giua cac cap dinh trong do thi
	cout<<"\n\n\nMa tran ket qua:";
	for(int i=1; i<=size; i++)
	{
		cout<<endl;
		for(int j=1; j<=size; j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
	}
	//Truy vet duong di
	int a, b;
	cout<<"\n\nDuong di tu ";cin>>a; cout<<"den ";cin>>b;
	vector<int> path = trace(a,b);
	for(int i = path.size()-1; i>=1; i--)
	{
		cout<<path[i]<<"->";
	}
	cout<<path[0];
	
}
