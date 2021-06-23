#include<bits/stdc++.h>
  
using namespace std;

unsigned long long minDistance(unsigned long long distances[], bool visited[], unsigned long long n)
{
    unsigned long long min = INT_MAX, minIndex = -1;
  
    for (unsigned long long i = 0; i < n; i++){
    	if (!visited[i] && distances[i] <= min){
    		min = distances[i];
			minIndex = i;
		}
	}
  
    return minIndex;
}
  
int main()
{
	unsigned long long n, src, end; 
	cin >> n >> src >> end;
    unsigned long long distances[n], node;
	long long graph[n][n]; 
    bool visited[n]; 
    src--;
    end--;
    
    for (unsigned long long i = 0; i < n; i++){
        distances[i] = INT_MAX;
		visited[i] = false;
    }
    for(unsigned long long i = 0; i < n; i++){
    	for(unsigned long long j = 0; j < n; j++){
    		cin >> graph[i][j];
		}
	}
    
    distances[src] = 0;
    for (unsigned long long i = 0; i < n - 1; i++) {
        node = minDistance(distances, visited, n);
        visited[node] = true;
        
        for (unsigned long long j = 0; j < n; j++){
        	if (!visited[j] && graph[node][j] > -1 && node != j){
        		if(distances[node] != INT_MAX && (distances[node] + graph[node][j]) < distances[j]){
        			distances[j] = distances[node] + graph[node][j];
				}
			}
		}
    }
    if(distances[end] == INT_MAX)cout << "-1";
    else cout << distances[end];
  
    return 0;
}
