//https://cses.fi/problemset/task/1629
#include<bits/stdc++.h>

using namespace std;

main(){
	int n;
	cin >> n;
	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; i++){
		cin >> vp[i].second >> vp[i].first;
	} 
	sort(vp.begin(), vp.end());
	int prev = vp[0].first, ans = 1;
	for(int i = 1; i < n; i++){
		if(vp[i].second >= prev){
			prev = vp[i].first;
			ans++;
		}
	}
	cout << ans;
}
