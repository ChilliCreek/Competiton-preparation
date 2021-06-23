#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	stack<pair<int, int> > st;
	int n, inp;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> inp;
		while(!st.empty() && st.top().first >= inp){
			st.pop();
		}
		if(st.empty()){
			cout << "0 ";
		}
		else{
			cout << st.top().second << " ";
		}
		st.push(make_pair(inp, i + 1));
	}
}
