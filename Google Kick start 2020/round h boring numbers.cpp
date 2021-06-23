#include<bits/stdc++.h>
using namespace std;
// counts number of boring numbers from num to the highest number with the number of digits of num
long long countUp(vector<long long> num, long long curr){
	if (curr < num.size() - 1) {
		if (curr % 2 == 0) {
			if (num[curr] % 2 == 1){
				long long countsBefore = countUp(num, curr + 1);
		        return (9 - num[curr]) / 2 * pow(5, num.size() - 1 - curr) + countsBefore;
			} 
			else {
				return (11 - num[curr]) / 2 * pow(5, num.size() - 1 - curr);
			}
		}
		else {
			if (num[curr] % 2 == 0){
				long long countsBefore = countUp(num, curr + 1);
		        return (9 - num[curr]) / 2 * pow(5, num.size() - 1 - curr) + countsBefore;
			} 
			else {
				return (10 - num[curr]) / 2 * pow(5, num.size() - 1 - curr);
			}
		}
    }
    else if (curr == num.size() - 1) {
    	if(curr % 2 == 0){
    		return (11 - num[curr]) / 2;
		}
		else {
			return (10 - num[curr]) / 2;
		}
	}
}
// self-explanatory
long long ifBoring(vector<long long> num){
	for(int i = 0; i < num.size(); i++){
		if (i % 2 == 0){
			if (num[i] % 2 == 0) {
				return 0;
			}
		}
		else {
			if (num[i] % 2 == 1){
				return 0;
			}
		}
	}
	return 1;
}
vector<long long> numToArr(long long num){
	vector<long long> res;
	while(num > 0){
		res.insert(res.begin(), num % 10);
		num /= 10;
	}
	return res;
}
main(){
    long long test, leftNum, rightNum, temp, factor, res;
    cin>>test;
    vector<long long> leftArr;
    vector<long long> rightArr;
    for(long long t = 1; t <= test; t++){
        cin>>leftNum>>rightNum;
        leftArr = numToArr(leftNum);
        rightArr = numToArr(rightNum);
        factor = ifBoring(rightArr);
        //cout<< countUp(leftArr, 0) <<" " << (pow(5, rightArr.size()) - countUp(rightArr, 0)) << " " << factor<<endl;
        //cout << "size: "<< rightArr.size()<<endl;
        //1000000000000000000
        if (leftArr.size() == rightArr.size()){
        	cout << "Case #" << t << ": " << countUp(leftArr, 0) - countUp(rightArr, 0) + factor << endl;
		}
		else {
			res = countUp(leftArr, 0) + (pow(5, rightArr.size()) - countUp(rightArr, 0)) + factor;
			for (int i = leftArr.size() + 1; i < rightArr.size(); i++) {
				res += pow(5, i);
			}
			cout << "Case #" << t << ": " << res << endl;
		}
		leftArr.clear();
		rightArr.clear();
    }
}
