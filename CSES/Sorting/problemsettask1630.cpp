#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, elapsed = 0, tleft, skipped = -1, sum = 0;
	cin >> n;
	pair<ll, ll> coor(0, n - 1);
	vector<int> vec(n);
	for(int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i];
	}
	sort(vec.begin(), vec.begin() + n);
	tleft = vec[n - 1];
	while(coor.first < coor.second){
		if(tleft - vec[coor.first] > 0){
			elapsed += vec[coor.first];
			tleft -= vec[coor.first];
			coor.first++;
		}
		else{
			elapsed += vec[coor.first];
			tleft = tleft - vec[coor.first] + vec[coor.second - 1];
			coor.first++;
			coor.second--;
		}
	}

	if(coor.second == n - 1){
		cout << elapsed + tleft + vec[coor.first]; //<< " elapsed: " << elapsed << " tleft : " << tleft << " vec[coor.fisrt] " << vec[coor.first] ;
	}
	else{
		if(coor.first > coor.second){
			cout << max(elapsed * 2 - vec[coor.second] + tleft, sum);
		}else{
			cout << max(elapsed * 2 + tleft, sum);
		}
	}
}
