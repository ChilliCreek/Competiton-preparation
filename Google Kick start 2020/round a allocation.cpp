#include<bits/stdc++.h>

using namespace std;

int main(){
	int testNumber, numOfHouses, money;
	int housesNum[1001], temp;
	cin >> testNumber;
	for (int t = 0; t < testNumber; t++) {
		cin >> numOfHouses >> money;
		memset(housesNum, 0, sizeof(housesNum));
		for (int i = 0; i < numOfHouses; i++) {
			cin>>temp;
			housesNum[temp]++;
		}
		temp = housesNum[0];
		for (int i = 1; i < 1001; i++) {
			if (housesNum[i] != 0 && housesNum[i] * i <= money) {
				money -= housesNum[i] * i;
				temp += housesNum[i];
			}
			else {
				int whatWeCanBuy = min(money / i, housesNum[i]);
				money -= whatWeCanBuy * i;
				temp += whatWeCanBuy;
			}
			if(money < i)break;
		}
		cout << "Case #" << t+1 << ": " << temp << endl;
	}
}
