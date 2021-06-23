#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, target, currSum = 0, inp, ans = 0;
	cin >> n >> target;
	ll sums[n];
	for(int i = 0; i < n; i++){
		cin >> inp;
		currSum += inp;
		sums[i] = currSum;
		if(currSum == target){
			ans++;
		}
		else if(currSum > target){
			int low = 0, high = i - 1, mid = (low + high) / 2;
			bool found = false;
			while(high >= low){
				if(sums[mid] == currSum - target){
					found = true;
					break;
				}
				else if(sums[mid] < currSum - target){
					low = mid + 1;
				}
				else{
					high = mid - 1;
				}
				mid = (low + high) / 2;
			}
			if(found){
				ans++;
			}
		}
	}
	cout << ans;
}
