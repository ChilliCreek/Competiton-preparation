#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, k, ans = 0;
	cin >> n >> k;
	map<int, int> mapp;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int st = 0;
	for(int en = 0; en < n; en++){
		mapp[arr[en]]++;
		while(mapp.size() > k){
			mapp[arr[st]]--;
			if(mapp[arr[st]] == 0){
				mapp.erase(arr[st]);
			}
			st++;
		}
		ans += en - st + 1;
	}
	cout << ans;
}
