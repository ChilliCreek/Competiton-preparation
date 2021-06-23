#include<bits/stdc++.h>

using namespace std;

int main(){
	string inp;
	cin >> inp;
	map<char, int> st;
	map<char, int>::iterator it;
	char odd;
	for(int i = 0; i < inp.size(); i++){
		st[inp[i]]++;
	}
	int count = 0;
	for(it = st.begin(); it != st.end(); it++){
		if(it->second % 2 == 1){
			odd = it->first;
			count++;
		}
	}
	if(count < 2){
		stringstream ss;
		string res;
		for(it = st.begin(); it != st.end(); it++){
			for(int i = 0; i < it->second / 2; i++){
				ss << it->first;
			}
		}
		res = ss.str();
		cout << res;
		if(count == 1){
			cout << odd;
		}
		reverse(res.rbegin(), res.rend());
		cout << res;
	}
	else{
		cout << "NO SOLUTION";
	}
}
