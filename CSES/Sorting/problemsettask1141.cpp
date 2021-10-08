//https://cses.fi/problemset/task/1141
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	int arr[n];
	map<int, int> last;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int start = 0;
	for (int i = 0; i < n; i++) {
		if(last.find(arr[i]) != last.end()){
			start = max(start, last[arr[i]] + 1);
			//cout << "A " << arr[i] << " :";
		}
		last[arr[i]] = i;
		ans = max(ans, i - start + 1);
		//cout << start << " - " << i << endl;
	}
	cout << ans;
}

