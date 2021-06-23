#include<bits/stdc++.h>

using namespace std;

void search(int platesLeft, int beautyVal, int& max, int stackNum, vector<vector<int> > &beautyMap) {
	
	if (stackNum >= beautyMap.size() && platesLeft != 0) {
		return;
	}
	
	if (platesLeft == 0) {
		if (beautyVal > max) {
			max = beautyVal;
		}
		return;
	}
	else {
		
		search(platesLeft, beautyVal, max, stackNum + 1, beautyMap);
		
		int temp = beautyMap[stackNum].size();

		for (int i = 0; i < min(platesLeft, temp); i++){
			search(platesLeft - i - 1, beautyVal + beautyMap[stackNum][i], max, stackNum + 1, beautyMap);
		}
		
	}
}

int main(){
	int numOfStacks, platesPerStack, numOfPlates, numOfTests, temp, max;
	vector<vector<int> > beautyMap;
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
		
		
		
		max = INT_MIN;
		search(numOfPlates, 0, max, 0, beautyMap);
		beautyMap.clear();
		cout << "Case #" << t+1 << ": " << max << endl;
	}
	
}
