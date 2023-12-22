#include <iostream>
#include <vector>
#include <climits>
#include <fstream>
using namespace std;

const int N = 100;
const int INF = INT_MAX; 

int n;
int C[N+1][N+1];
int x[N+1]; 
bool Daxet[N+1]; 
int S; 
int Gttu; 
int Httu[N+1]; 
int Cmin; 

int k =1; 


void Gan(int x[], int Httu[], int n)
{
    for (int i = 1; i <= n; i++) {
        Httu[i] = x[i];
    }
}

void TRYY(int i)
{
    for (int j = 2; j <= n; j++)
    {   
        if (!Daxet[j]&&C[j][x[i-1]]!=0) 
        {
            x[i] = j; 
            Daxet[j] = true;
            S += C[x[i - 1]][x[i]]; 

            if (i == n) 
            {
                if (S + C[x[n]][x[1]] < Gttu)
                {
                    Gttu = S + C[x[n]][x[1]];
                    Gan(x, Httu, n);
                }
            }
            
            else if (S + (n - i+1) * Cmin < Gttu) 
            {
                TRYY(i + 1);
            }
            
            S -= C[x[i - 1]][x[i]];
            Daxet[j] = false;
        }
    }
}

void Init()
{     
        for(int i =1;i<=n;i++)
        {
            Daxet[i]=false;
        }
          for (int i = 1; i <= n; i++)
        for (int i = 1; i <= n; i++)
        {
            for(int j =1;j<=n;j++)
            {
                if(Cmin > C[i][j])
                    Cmin = C[i][j];
            }
        }
        Gttu = INF; 
        S =0;
        Daxet[k]=true;
        x[1]=k;
}

int main()
{
    ifstream inputFile("input1.txt");
    if (!inputFile)
    {
        cout << "loi mo file" << endl;
        return 1;
    }
    inputFile >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            inputFile >> C[i][j];
        }
    }
    inputFile.close();
    Init();
    TRYY(2);
    cout<<"Ma tran chi phi:"<<endl;
    for(int i =1 ;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        cout<<C[i][j]<<" ";

    }
    cout<<endl;
}
    cout << "\nLich trinh du lich toi uu: ";
    for (int i = 1; i <= n; i++) {
        cout << Httu[i] << " ";
    }
    cout << Httu[1] << endl;
    cout << "Chi phi toi uu: " << Gttu << endl;
    return 0;
}

//void trydo(int i, int* gtmin)
//{
//	int j;
//	for(j=1;j<=n;j++)
//	{
//		if(daxet[j]==0&&a[road[i-1]][j]!=0)
//		{
//			road[i]=j;
//			daxet[j]=1;
//			gttam+=a[road[i]][road[i-1]];
//			if(i==n)
//			{
//				if(a[road[n]][road[1]]!=0)
//				{
//					gttam+=a[road[n]][road[1]];
//					if(gttam<*gtmin)
//					{
//						*gtmin=gttam;
//					}	
//				}
//			}
//			else
//			{
//				trydo(i+1,gtmin);
//			}
//			gttam-=a[road[i]][road[i-1]];
//			daxet[j]=0;
//		}
//	}
//}
