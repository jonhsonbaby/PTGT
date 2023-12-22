#include <iostream>
#include <fstream>

using namespace std;

#define max 100

int n;

struct Activity
{
	char id[max];
	int start;
	int finish;
};

Activity a[max];

void Init()
{
	fstream f;
	f.open("Input1.txt", ios::in);
	f >> n;
	for (int i = 0; i < n; i++)
	{
		f >> a[i].id;
		f >> a[i].start;
		f >> a[i].finish;
	}
	f.close();
}
void activitySelection(Activity a[], int n)
{
	int i, j;
	Activity temp;
	//step 1
	//sort the a as per finishing time in ascending order
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (a[j].finish > a[j + 1].finish) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

	//sorted
	cout << "Sorted a as per finish time (ascending order)\n";
	cout << "\tActivity" << "\tStart" << "\tFinish" << endl;
	for (i = 0; i < n; i++) {
		cout << "\t" << a[i].id << "\t\t" << a[i].start << "\t" << a[i].finish << endl;
	}

	//step 2
	//select the first activity
	cout << "-----Selected a-----\n";
	cout << "\tActivity" << "\tStart" << "\tFinish" << endl;
	cout << "\t" << a[0].id << "\t\t" << a[0].start << "\t" << a[0].finish << endl;

	//step 3
	//select next activity whose start time is greater than or equal to the finish time of the previously selected activity
	i = 0;
	for (j = 1; j < n; j++) {
		if (a[j].start >= a[i].finish) {
			cout << "\t" << a[j].id << "\t\t" << a[j].start << "\t" << a[j].finish << endl;
			i = j;
		}
	}

}
int main()
{
	Init();
	activitySelection(a, n);
	system("pause");
	return 0;
}
