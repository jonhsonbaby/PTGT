//bai toan tim duong di ngan nhat tren do thi (giai thuat Dijkstra)
#include <iostream>
using namespace std;
#define MAX 100
int n; // so dinh do thi
int a[MAX][MAX]; //ma tran trong so do thi
int Daxet[MAX]; //danh dau cac dinh da xet
int L[MAX]; //mang ghi nhan cac dinh
int Truoc[MAX]; //chua dinh ngay truoc
int s, t;

void Input()
{
	int i, j;
	freopen("input5.txt", "r", stdin);
	cin>>n;
	cout<<"- So dinh cua do thi la: "<< n;
	cout<<"\n- Ma tran ke la:";
	for(i=1; i<=n; i++)
	{
		cout<<"\n";
		for(j=1; j<=n; j++)
		{
			cin>>a[i][j];
			cout<<"\t"<<a[i][j];
			if(a[i][j]==0&&(i!=j)) 
			{
				a[i][j]=320000;
			}
		}
	}
}

void Init()
{
    for(int i=1;i<=n;i++)
    {
        L[i]= MAX;
        Daxet[i]=0;
        Truoc[i]=0;
    }
}

void Print(int s, int k, int Truoc[MAX])
{
	int i;
	cout<<"\nDuong di ngan nhat tu "<<s<<" den "<<k<<" la :";
	i=k;
	while(i!=s)
	{
		cout<<i<<"<--";
		i=Truoc[i];
	}
	cout<<s;
		
}

void Dijkstra() {
    int i,k, minp, dht;
    int h = 1;
    for ( i = 1; i <= n; i++) {
        Daxet[i] = 0;
        L[i] = INT_MAX;
    }
    Daxet[s] = 1;
    L[s] = 0;
    dht = s;
    while (h < n) {
        minp = INT_MAX; // Thay MAX b?ng INT_MAX
        for (i = 1; i <= n; i++) {
            if (!Daxet[i]) {
                if ((L[dht] + a[dht][i]) < L[i]) {
                    L[i] = L[dht] + a[dht][i];
                    Truoc[i] = dht;
                }
                if (L[i] < minp) {
                    minp = L[i];
                    k = i;
                }
            }
        }
        Print(s, k, Truoc);
        cout << "\n Trong so: " << L[k];
        dht = k;
        Daxet[dht] = 1;
        h++;
    }
}


int main()
{
	cout<<"* Input: \n- Nhap dinh dau: ";
	cin>>s;
	Input();
	cout<<"\n-------------------------------------\n* Output: \n";
	Init();	
	Dijkstra();
}
