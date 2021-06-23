//https://codeforces.com/contest/1520/problem/D
#include<bits/stdc++.h>
using namespace std;
#define LOG(x) cout << x << endl


int main(){
	long long t, n;
	cin >> t;
	for(long long j = 0; j < t; j++){
		cin >> n;
		long long res = 0, inp;
		map<long long, long long> mapp;
		for(long long p = 0; p < n; p++){
			cin >> inp;
			res += mapp[inp - p];
			mapp[inp - p]++;
		}
		LOG(res);
	}
}
