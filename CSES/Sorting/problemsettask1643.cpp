//https://cses.fi/problemset/task/1643
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll sums[n];
	cin >> sums[0];
	ll maxSum = sums[0], currMax = sums[0];
	for(int i = 1; i < n; i++){
		cin >> sums[i];
		if(sums[i] > currMax + sums[i]){
			currMax = sums[i];
		}
		else{
			currMax += sums[i];
		}
		maxSum = max(maxSum, currMax);
	}
	cout << maxSum;
}
