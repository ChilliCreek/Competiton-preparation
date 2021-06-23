#include<bits/stdc++.h>

using namespace std;

int main(){
	int numOfStacks, platesPerStack, numOfPlates, numOfTests, temp;
	vector<vector<int> > beautyMap, dp;
	vector<int> vec;
	
	
	
	cin>>numOfTests;
	
	for(int t = 0; t < numOfTests; t++){
		
		cin >> numOfStacks >> platesPerStack >> numOfPlates;
		
		for (int i = 0; i < numOfStacks; i++) {
			for (int j = 0; j < platesPerStack; j++) {
				
				cin >> temp;
				
				if (j == 0) {
					vec.push_back(temp);
				}
				else {
					vec.push_back(temp + vec[j - 1]);
				}
			}
			beautyMap.push_back(vec);
			vec.clear();
		}
		
		vec = beautyMap[0];
		vec.insert(vec.begin(), 0);
		if (vec.size() < numOfPlates + 1){
			for(int st = vec.size(); st <= numOfPlates + 1; st++){
				vec.push_back(-1);
			}
		}
		dp.push_back(vec);
		
		vec.clear();
		vec.push_back(0);
		for(int i = 1; i < numOfStacks; i++){
			dp.push_back(vec);
		}
		
		
		
		//stacks = x, y = plates taken to get the maximium sum 
		for (int x = 1; x < numOfStacks; x++) {
			
			for (int y = 1; y <= min((x + 1) * platesPerStack, numOfPlates); y++) {
				
				temp = 0;
				
				for (int z = max(0, y - platesPerStack); z < y; z++){
					
					if (dp[x - 1][z] == -1) {
						break;
					}
					
					temp = max(temp, dp[x - 1][z] + beautyMap[x][y - z - 1]);
				}

				if(dp[x - 1][y] != -1)temp = max(temp, dp[x - 1][y]);
				dp[x].push_back(temp);
				
			}
			
			if (dp[x].size() < numOfPlates + 1){
				for(int st = dp[x].size(); st <= numOfPlates + 1; st++){
					dp[x].push_back(-1);
				}
			}
		}

		cout << "Case #" << t+1 << ": " << dp[numOfStacks - 1][numOfPlates] << endl;
		
		beautyMap.clear();
		dp.clear();
		vec.clear();
	}
	
}
