//https://cses.fi/problemset/task/2217
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int index[n], arr[n];
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		index[arr[i]] = i;
	}
	int start = 1, ans = 1;
	for(int i = 1; i <= n; i++){
		if(start > index[i]){
			ans++;
		}
		start = index[i];
	}
	int pos1, pos2;
	for(int i = 0; i < m; i++){
		cin >> pos1 >> pos2;
		int f = arr[pos1], s = arr[pos2];
		swap(arr[pos1], arr[pos2]);
		
		if (index[f-1] <= index[f] && index[f-1] > pos2) ans++;
		if (index[f-1] > index[f] && index[f-1] <= pos2) ans--;
		if (index[f] <= index[f+1] && pos2 > index[f+1]) ans++;
		if (index[f] > index[f+1] && pos2 <= index[f+1]) ans--;		
		index[f] = pos2;
		if (index[s-1] <= index[s] && index[s-1] > pos1) ans++;
		if (index[s-1] > index[s] && index[s-1] <= pos1) ans--;
		if (index[s] <= index[s+1] && pos1 > index[s+1]) ans++;
		if (index[s] > index[s+1] && pos1 <= index[s+1]) ans--;	
		index[s] = pos1;
		
		cout << ans << '\n';
	}
}
