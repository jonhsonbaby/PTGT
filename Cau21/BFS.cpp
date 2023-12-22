#include<bits/stdc++.h>
using namespace std;
int daxet[100];
int truoc[100];
int Queue[100];
int n;
int start;
int stop;
int a[1000][1000];
void print(int road[])
{
	cout<<stop<<"<-";
	int i=stop;
	while(road[i]!=start)
	{
		cout<<road[i]<<"<-";
		i=road[i];
	}
	cout<<start<<endl;
}

void bfs()
{
	int u,j;
	int dau=1;
	int cuoi=1;
	daxet[start]=1;
	Queue[cuoi]= start;
	while(dau<=cuoi)
	{
		u=Queue[dau];
		dau++;
		for(j=1;j<=n;j++)
		{
			if(a[u][j]!=0&&daxet[j]==0)
			{
				cuoi++;
				Queue[cuoi]=j;
				daxet[j]=1;
				truoc[j]=u;
			}
		}
	}
}

int main()
{
	fstream infile;
    infile.open("input4.txt");
    infile >> n;
    for (int i = 1; i <= n; i++) 
	{
        for (int j = 1; j <= n; j++) 
		{
            infile >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++)
    {
    	daxet[i]=0;
		truoc[i]=-1;	
	}
    cout<<"Chon vi tri bat dau: ";cin>>start;
    cout<<"Chon vi tri ket thuc: ";cin>>stop;
    bfs();
    print(truoc);
    infile.close();
	return 0;
}
