#include<bits/stdc++.h>

using namespace std;

int main(){
	int t, f, s, diff;
	cin >> t;
	for(int p = 0; p < t; p++){
		cin >> f >> s;
		if(f > s){
			diff = f - s;
			f -= diff * 2;
			s -= diff;
		}
		else{
			diff = s - f;
			s -= diff * 2;
			f -= diff;
		}
		if(s < 0 || f < 0){
			cout << "NO" << '\n';
		}
		else if(s == f && s % 3 == 0){
			cout << "YES" << '\n';
		}
		else{
			cout << "NO" << '\n';
		}
	}
}
