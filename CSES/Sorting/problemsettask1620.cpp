#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, t;
	cin >> n >> t;
	ll arr[n];
	for(ll i = 0; i < n; i++){
		cin >> arr[i];
	}
	ll low = 0, high = 1e18, ans = 0, mid, res;
	while(low <= high){
		ans = 0;
		mid = (low + high) / 2;
		for(ll i = 0; i < n; i++){
			ans += (mid / arr[i]);
			if(ans >= t){
				break;
			}
		}
		if(ans >= t){
			res = mid;
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	cout << res;
}


