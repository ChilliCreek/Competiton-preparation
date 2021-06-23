#include<bits/stdc++.h>
/*
ID: chiig.e1
LANG: C++
TASK: skidesign
*/
using namespace std;
int lowest=INT_MAX,arr[1001],n,arr1[1001];
void func(vector <pair<int,int> >great){
	int temp,i,j;
	if(great.size()==0){
		temp=0;
		for(i=0;i<n;i++){
			temp+=(arr[i]-arr1[i])*(arr[i]-arr1[i]);
		}
		if(temp<lowest){
			lowest=temp;
		}
	}else{
		vector <pair<int,int> > package;
		for(int i=0;i<great.size();i++){
			if((arr[great[i].second]-arr[great[i].first]-17)%2==0){
				temp=(arr[great[i].second]-arr[great[i].first]-17)/2;
				arr[great[i].second]-=temp;
				arr[great[i].first]+=temp;
				for(j=0;j<great.size();j++){
					if(arr[great[j].second]-arr[great[j].first]>17){
						package.push_back(great[j]);
					}
				}
				func(package);
				package.clear();
				arr[great[i].second]+=temp;
				arr[great[i].first]-=temp;
			}else{
				temp=(arr[great[i].second]-arr[great[i].first]-17)/2;
				arr[great[i].second]-=(temp+1);
				arr[great[i].first]+=temp;
				for(j=0;j<great.size();j++){
					if(arr[great[j].second]-arr[great[j].first]>17){
						package.push_back(great[j]);
					}
				}
				func(package);
				package.clear();
				arr[great[i].second]+=(temp+1);
				arr[great[i].first]-=temp;
				arr[great[i].second]-=temp;
				arr[great[i].first]+=(temp+1);
				for(j=0;j<great.size();j++){
					if(arr[great[j].second]-arr[great[j].first]>17){
						package.push_back(great[j]);
					}
				}
				func(package);
				package.clear();
				arr[great[i].second]+=temp;
				arr[great[i].first]-=(temp+1);
			}
		}
	}
}
main(){
	ifstream fin("skidesign.in");
	ofstream fout("skidesign.out");
	int i,j;
	std::vector<pair <int,int> > greaterthan17;
	fin>>n;
	for(i=0;i<n;i++){
		fin>>arr[i];
		arr1[i]=arr[i];
		for(j=0;j<i;j++){
			if(abs(arr[i]-arr[j])>17){
				if(arr[i]<arr[j])greaterthan17.push_back(make_pair(i,j));
				else greaterthan17.push_back(make_pair(j,i));
			}
		}
	}
	func(greaterthan17);
	fout<<lowest<<endl;
}
