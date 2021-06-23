#include <bits/stdc++.h>
/*
ID: chiig.e1
LANG: C++
TASK: skidesign
*/
using namespace std;

int n,arr[1001];

int main()
{
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	fin>>n;
	for (int i=0; i<n; i++){
		fin >> arr[i];
	}
	int mincost=INT_MAX;
	int cost=0,x;
	for (int i=0; i<=83; i++){
		cost=0;
		for (int j=0; j<n; j++){
			if (arr[j]<i)
				x=i-arr[j];
			else if (arr[j]>i+17)
				x=arr[j]-(i+17);
			else
				x=0;
			cost+=x*x;
		}
		mincost=min(mincost,cost);
	}
	fout<<mincost<<"\n";
}
