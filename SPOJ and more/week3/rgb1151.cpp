#include<iostream>
 
using namespace std;
 
int a[1002][1002]={0};
main(){
	int i,j,r;
	scanf("%d",&r);
	
	for(i=1;i<=r;i++){
		for(j=1;j<=i;j++){
			scanf("%d",&a[i][j]);
			a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
		}
	}
	j=0;
	for(i=1;i<=r;i++){
		if(j<a[r][i]){
			j=a[r][i];
		}
	}
	
	printf("%d",j);
}
