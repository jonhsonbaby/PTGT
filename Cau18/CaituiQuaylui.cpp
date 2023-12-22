#include<iostream>
using namespace std;
int n;
int ma;
void print(int khoiluong[])
{
	for(int i = 0; i<n; i++)
		cout<<khoiluong[i]<<" ";
	cout<<endl;
}

trydo(int i, int khoiluong[], int giatri[], int kltam, int gttam, int ketquamax[2])
{
	for(int j =0; j <=1; j++)
	{
		kltam += j*khoiluong[i];
		gttam += j*giatri[i];
		if(i<n-1)
			trydo(i+1, khoiluong, giatri, kltam, gttam, ketquamax);
		else
		{
			if(kltam<= ma && gttam>ketquamax[1])
			{
				ketquamax[0] = kltam;
				ketquamax[1] = gttam;
			}
		}
	}
}

int main()
{
	cout<<"Nhap n: "; cin >> n;
	cout<<"Nhap khoi luong toi da: ";cin>>ma;
	int khoiluong[n]={1,3,4,2,9,1,5};
	int giatri[n]   ={6,7,4,5,7,2,1};
	int ketquamax[2] = {0,0};
	trydo(0,khoiluong,giatri,0,0,ketquamax);
	cout<<"Khoi luong max: "<<ketquamax[0]<<"; Gia tri max: "<<ketquamax[1];
	return 0;
}
