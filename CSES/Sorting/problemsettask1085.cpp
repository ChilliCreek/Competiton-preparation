#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, k, ans = LONG_LONG_MAX;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	long long low = 0, high = static_cast<long long>(1e16), subarrays = 1, mid;
	while(low <= high){
		ll sum = 0;
		subarrays = 0;
		mid = (low + high) / 2;
		bool interrupted = false;
		for(int i = 0; i < n; i++){
			if(arr[i] > mid){
				interrupted = true;
				break;
			}
			if(sum + arr[i] > mid){
				subarrays++;
				sum = arr[i];
			}
			else{
				sum += arr[i];
			}
		}
		subarrays++;
		if(subarrays <= k && !interrupted){
			high = mid - 1;
			ans = mid;
		}
		else{
			low = mid + 1;
		}
	}
	cout << ans;
}
