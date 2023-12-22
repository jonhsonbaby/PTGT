#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

const int MAX = 100;

struct Edge {
	int u, v;
	int w;
};


void sapxepchon(Edge arr[], int n)
{
	int i, j, max_index;
	for (int i = 1; i < n; i++)
	{
		max_index = i;
		for (j = i + 1; j <= n; j++)
		{
			if (arr[j].w > arr[max_index].w)
			{
				max_index = j;
			}
		}
		swap(arr[max_index], arr[i]);
	}
}

int main()
{
	int n, m;
	Edge G[MAX];
	ifstream file("dothi.txt");
	file >> n;
	file >> m;
	int i = 1;
	int d2, c2, f2;
	while (file >> d2 >> c2 >> f2)
	{
		G[i].u = d2;
		G[i].v = c2;
		G[i].w = f2;
		i++;
	}
	cout << "So dinh: " << n << endl;
	cout << "So canh: " << m << endl;
	sapxepchon(G, m);
	cout << "Danh sach canh " << endl;
	for (int i = 1; i <= m; i++)
	{
		cout << G[i].u << "\t" << G[i].v << "\t" << G[i].w << endl;

	}

	cout << "\n\n";
	//---------------------------
	int VF[MAX] = { 0 };
	i = 1;
	Edge P[MAX];
	P[i] = G[1];
	VF[G[1].u] = 1;
	VF[G[1].v] = 1;
	while (i < n - 1)
	{
		int j = 2;
		while (VF[G[j].u] == VF[G[j].v])
		{
			j++;
		}
		i++;
		P[i] = G[j];
		VF[G[j].u] = 1;
		VF[G[j].v] = 1;
	}
	//in ket qua
	cout << "Ket qua thoa man: \n";
	for (int i = 1; i <= n - 1; i++)
	{
		cout << P[i].u << " " << P[i].v << " " << P[i].w << endl;
	}
	return 0;
}