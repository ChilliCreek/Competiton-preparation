//https://cses.fi/problemset/task/2216
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, temp;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> temp;
		arr[temp - 1] = i;
	}
	int start = 0, ans = 1;
	for(int i = 0; i < n; i++){
		if(start > arr[i]){
			ans++;
		}
		start = arr[i];
	}
	
	cout << ans;
}
