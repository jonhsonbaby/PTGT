#include<bits/stdc++.h>
using namespace std;
int daxet[100];
int truoc[100];
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
trydo(int pre)
{
	daxet[pre]=1;
	for(int j=1; j<=n;j++)
	{
		if(a[pre][j]!=0&&daxet[j]==0)
		{
			truoc[j]=pre;
			if(j==stop)
				print(truoc);
			else
				trydo(j);
			daxet[j]=0;	
		}
	}
}
int main()
{
	fstream infile;
    infile.open("input1.txt");
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
    trydo(start);
    infile.close();
	return 0;
}
