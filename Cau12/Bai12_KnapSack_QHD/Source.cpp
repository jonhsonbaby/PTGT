#include<iostream>
#include<stdio.h>
#include <fstream>

using namespace std;

int MaxV[100][100];
int n;
int c[100]; //mang gia tri
int w[100]; //mang khoi luong
int L;      //khoi luong toi da
int select[100] = { 0 };

void input()
{
	fstream infile;
    infile.open("input5.txt");
    int t = 0;
    infile >> n >> L;
    for (int i = 1; i <= n; i++)
    {
        infile >> w[i] >> c[i];
    }
    infile.close();
}
int main() {
	input();
    //DP
    for (int i = 0; i < L; i++) { MaxV[i][0] = 0; MaxV[0][i] = 0; }
    for (int i = 1; i <= n; i++)
        for (int b = 1; b <= L; b++)
        {
            MaxV[i][b] = MaxV[i - 1][b];
            if (b >= w[i] && (MaxV[i - 1][b - w[i]] + c[i] > MaxV[i - 1][b]))
            {

                MaxV[i][b] = MaxV[i - 1][b - w[i]] + c[i];
            }
        }

    int i = n, j = L;
    while (i > 0) {
        //neu chon vat thu i 
        if (j >= w[i] && (MaxV[i - 1][j - w[i]] + c[i] > MaxV[i - 1][j])) {
            select[i] = 1; //danh dau la duoc chon
            j = j - w[i]; //khoi luong con lai
        }
        i--;
    }

    int sum = 0;
    cout << "Cac phan tu duoc chon la: ";
    for (int i = 1; i <= n; i++) {
        if (select[i] == 1) {
            cout << i << " ";
            sum += w[i];
        }
    }
    cout << endl << "Tong khoi luong la: " << sum;
    cout << endl << "Tong gia tri la: " << MaxV[n][L];

    return 0;
}

