//https://cses.fi/problemset/task/1622
#include<bits/stdc++.h>

using namespace std;

stringstream res;
int k = 0;
map<char, int> mapp;
int len;
void newst(int step, string w){
	if(step == len){
		k++;
		res << '\n' << w;
	}
	else{
		w += " ";
		map<char, int>::iterator it;
		for(it = mapp.begin(); it != mapp.end(); it++){
			if(it->second > 0){
				it->second--;
				w[w.size() - 1] = it->first;
				newst(step + 1, w);
				it->second++;
			}
		}
	}
}


int main(){
	string inp;
	cin >> inp;
	len = inp.size();
	for(int i = 0; i < len; i++){
		mapp[inp[i]]++;
	}
	newst(0, "");
	cout << k;
	cout << res.str();
}
