#include <bits/stdc++.h>
#include <string>

using namespace std;

const int N = 100;

string str1 = "";
string str2 = "";

int arr[N][N];

void LCS(int n, int m)
{
    for (int i = 0; i < n; i++)
        arr[i][0] = 0;
    for (int j = 0; j < m; j++)
        arr[0][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (str1[i - 1] == str2[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
            {
                if (arr[i - 1][j] >= arr[i][j - 1])
                    arr[i][j] = arr[i - 1][j];
                else
                    arr[i][j] = arr[i][j - 1];
            }
}

string Back_tracking(int n, int m)
{
    int i = n;
    int j = m;
    string ret = "";
    while (arr[i][j] != 0)
    { // Điều kiện dừng
        if (str1[i - 1] == str2[j - 1])
        {                            
            ret += str1[i - 1]; 
            i--;
            j--;
        }
        else
        {                                  
            if (arr[i - 1][j] >= arr[i][j - 1]) 
                i--;
            else
                j--;
        }
    }
    return ret;
}

int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);

    getline(cin, str1);
    getline(cin, str2);

    time_t st,ed;
    st = clock();
    int n = str1.length();
    int m = str2.length();

    LCS(n, m);
    string ret = Back_tracking(n,m);
    ed = clock();
    
    cout << str1 << endl
         << str2 << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    reverse(ret.begin(),ret.end());
    cout<<"LCS: "<<ret<<endl;
    cout<<"Time: "<<setprecision(8)<<(double) ed-st<<endl;
}