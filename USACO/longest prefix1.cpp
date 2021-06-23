#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: prefix
*/
#define MAX 200001

int main(){
	std::ifstream fin("prefix.in");
    std::ofstream fout("prefix.out");
	int res = 0;
	std::vector<std::string> prim;
	bool prefix[MAX] = {false};
	std::string all;
	while(fin >> all){
		if(all != "."){
			prim.push_back(all);
		}else{
			all = "";
			std::string temp;
			while(fin >> temp){
				all = all + temp;
			}
			break;
		}
	}
	int len = all.length();
	prefix[0] = 1;
	for(int i = 0; i <= all.length(); i++){
		if(prefix[i]){
			res = i;
			for(int j = 0; j < prim.size(); j++){
				//std::cout << j << std::endl;
				if(i + prim[j].length() <= all.length()){
					int p;
					for(p = 0; p < prim[j].length(); p++){
						if(all[i + p] != prim[j][p])break;
					}
					if(prim[j].length() == p){
						prefix[i + prim[j].length()] = 1;
					}else{
						continue;
					}
				}
			}
		}else{
			continue;
		}
	}
	if(prefix[all.length()]){
		fout << all.length() << std::endl;
	}else{
		fout << res << std::endl;
	}
}
