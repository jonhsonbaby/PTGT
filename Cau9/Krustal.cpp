#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int x;
	int y;
	int lenght;
};

void swap(edge &a, edge &b)
{
	edge c=a;
	a=b;
	b=c;
}

vector<edge> selectionSort(vector<edge> arr)
{
	for(int i=0; i<arr.size(); i++)
	{
		for(int j=i+1; j<arr.size(); j++)
		{
			if(arr[i].lenght>arr[j].lenght)
			swap(arr[i], arr[j]);
		}
	}
	return arr;
}

bool round(edge E)
{
	if(E.x==E.y)
		return true;
	else
		return false;
}

vector<edge> reset(vector<edge> l, edge e, int sh)
{
	for(int i =0; i<l.size();i++)
	{
		if(l[i].x==e.y)
		{
			l[i].x = sh;
		}
		if(l[i].y==e.y)
		{
			l[i].y = sh;
		}
	}
	return l;
}

vector<edge> shortestTree(vector<edge> l, int numberpoint)
{
	// Do dai cay khung
	int road= 0;
	vector<edge> list = l;
	vector<edge> memory;
	// Them canh dau tien vao danh sach
	list = reset(list, list[0], list[0].x);
	memory.push_back(l[0]);
	road+= l[0].lenght;
	for(int i = 1; i < l.size(); i++)
	{
		if(!round(list[i]) && memory.size()< numberpoint-1)
		{
			list = reset(list,list[i], list[i].x);
			memory.push_back(l[i]);
			road+=l[i].lenght;
		}
	}
	cout<<"Do dai cay khung nho nhat "<<road<<endl;
	return memory;
}

vector<edge> input(vector<edge> E, int* socanh, int* sodinh)
{
	fstream file;
    file.open("input3.txt");
    file >> *sodinh;
    file >> *socanh;
	edge temp;
    for (int i = 0; i < *socanh; i++) 
	{
        file >>temp.x;
		file >>temp.y;
		file >>temp.lenght;
		E.push_back(temp);
    }
    file.close();
    return E;
}
int main()
{
	int size,point;
	vector<edge> listEdge;
	listEdge= input(listEdge,&size,&point);
	// Sap xep theo thu tu giam dan chieu dai canh
	listEdge= selectionSort(listEdge);
	vector<edge> stt =  shortestTree(listEdge,point);
	cout<<"Cay khung nho nhat: "<<endl;
	// In ra cay khung nho nhat
	cout<<"Canh | x | y | SIZE |"<<endl;
	for(int j = 0; j< stt.size(); j++)
		cout<<" E"<<j+1<<"    "<<stt[j].x<<"   "<<stt[j].y<<"\t"<<stt[j].lenght<<endl;
	return 0;
}
