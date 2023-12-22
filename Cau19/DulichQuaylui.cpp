#include<bits/stdc++.h>
using namespace std;
int daxet[1000];
int road[1000];
int n;
int gttam;
int start;
int a[1000][1000];

void print(int road[])
{
	int j=1;
	while(j<=n)
	{
		cout<<road[j]<<" <- ";
		j++;
	}
	cout<<start<<endl;
}

void trydo(int i, int* gtmin)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(daxet[j]==0&&a[road[i-1]][j]!=0)
		{
			road[i]=j;
			daxet[j]=1;
			gttam+=a[road[i]][road[i-1]];
			if(i==n)
			{
				if(a[road[n]][road[1]]!=0)
				{
					gttam+=a[road[n]][road[1]];
					if(gttam<*gtmin)
					{
						*gtmin=gttam;
					}	
				}
			}
			else
			{
				trydo(i+1,gtmin);
			}
			gttam-=a[road[i]][road[i-1]];
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
    infile.close();
    // Khoi tao mang da xet bang 0 chua phan tu nao duoc xet
    for(int i=1;i<=n;i++)
    {
    	daxet[i]=0;
	}
    // Cho dia chi xuat phat vao mang road de luu duong di
    cout<<"Nhap dia chi di : ";cin>>start;
    daxet[start]=1;
    road[1]=start;
    // Khoi tao do dai duong di luc dau
    gttam=0;
    int gtmin=1000;
    // Su dung thuat toan de tim duong di ngan nhat
    trydo(2, &gtmin);
    
    cout<<"Quang duong di nho nhat tu "<<start<<endl;
    print(road);
    cout<<"Do dai duong di: "<<gtmin;
	return 0;
}
