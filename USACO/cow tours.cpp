#include<bits/stdc++.h>

using namespace std;



int main(){
	int n;/
	int chosen1, chosen2;
	cin >> n;
	char inp;
	pair<int, int> coords[n];
	
	float dist[n][n];	
	for(int i = 0; i < n; i++){
		cin >> coords[i].first >> coords[i].second;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> inp;
			if(inp - '0' == 1){
				dist[i][j] = sqrt(pow(coords[i].first - coords[j].first, 2) + pow(coords[i].second - coords[j].second, 2));
			}else{
				dist[i][j] = -1;
			} 
		}
	}
	
	
}
