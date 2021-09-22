//https://cses.fi/problemset/task/2163
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k; 
	indexed_set points;
	for(int i = 1; i <= n; i++){
		points.insert(i);
	}
	int left = k % n;
	for(int i = n - 1; i >= 0; i--){
		auto it = points.find_by_order(left);
		cout << *(it) << " ";
		points.erase(it);
		if(i != 0){
			left = (left % i + k) % i;
		}
	}
}
