#include<iostream>
#define max 100

using namespace std;

int GTS(int matran[max][max], int n, int tour[max], int Ddau)
{
	int index, dangxet, chon;
	int mini;
	int cost = 0;
	int daxet[max];
	for(index=1;index<=n;index++)
		daxet[index]=0;
	
	int i;
	dangxet= Ddau;
	i = 1;
	tour[i]= dangxet;
	daxet[dangxet] = 1;
	
	while(i<n)
	{
		mini = 1000;
		for(index = 1; index<=n; index++)
		{
			if(daxet[index]==0)
			{
				if(mini > matran[dangxet-1][index-1])
				{
					mini = matran[dangxet-1][index-1];
					chon = index;
				}
			}
		}
		dangxet = chon;
		i++;
		tour[i] = dangxet;
		daxet[dangxet] = 1;
		cost+= mini;
	}
	cost+=matran[dangxet][Ddau];
	tour[i+1] = Ddau;
	return cost;
}

int main()
{
	int matran[max][max]={{1000,1,2,7,5},{1,1000,4,4,3},{2,4,1000,1,2},{7,4,1,1000,3},{5,3,2,3,1000}};
	int n = 5;
	int tour[5];
	int ddau = 3;
	GTS(matran,n,tour,ddau);
	for(int i = 1; i<=6; i++)
		cout<<tour[i]<<" ";
	
	return 0;
}
