//https://cses.fi/problemset/task/1084
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m, diff, res = 0;
	cin >> n >> m >> diff;
	int applicants[n], apartments[m];
	for(int i = 0; i < n; i++){
		cin >> applicants[i];
	}
	for(int i = 0; i < m; i++){
		cin >> apartments[i];
	}
	sort(applicants, applicants + n);
	sort(apartments, apartments + m);
	int track1 = 0, track2 = 0;
	while(track1 < n && track2 < m){
		if(abs(applicants[track1] - apartments[track2]) <= diff){
			res++;
			track1++;
			track2++;
		}
		else if(applicants[track1] > apartments[track2]){
			track2++;
		}
		else{
			track1++;
		}
	}
	cout << res;
}
