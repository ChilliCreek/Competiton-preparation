//https://codeforces.com/contest/1520/problem/A
#include<bits/stdc++.h>
using namespace std;

#define LOG(x) cout << x << endl

long long main(){
	long long len, t;
	cin >> t;
	bool done;
	char prev = 'z', curr;
	bool letters[26] = {false};
	for(long long j = 0; j < t; j++){
		done = false;
		cin >> len;
		for(long long i = 0; i < len; i++){
			cin >> curr;
			if(done)continue;
			if(curr != prev){
				if(letters[curr - 65]){
					LOG("NO");
					done = true;
				}
				else{
					letters[curr - 65] = true;
				}
			}
			prev = curr;
		}
		if(!done)LOG("YES");
		for(long long i = 0; i < 26; i++){
			letters[i] = false;
		}
		prev = 'z';
	}
}
