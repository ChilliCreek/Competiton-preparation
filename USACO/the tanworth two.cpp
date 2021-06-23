#include<bits/stdc++.h>
/*
ID: chiig.e1
TASK: ttwo
LANG: C++                 
*/
using namespace std;

#define NORTH 0
#define RIGHT 1
#define SOUTH 2
#define LEFT 3



struct Tile{
	bool ifObstacle = false;
};


Tile tiles[10][10];
    
struct Pos{
	int x;
	int y;
	int direction = NORTH;
	void changeDir(){
		direction++;
		if(direction == 4)direction = 0;
	}
	void goDir(){
		if(direction == NORTH){
			if(x > 0 && !tiles[x - 1][y].ifObstacle){
				x--;
			}else{
				changeDir();
			}
		}
		else if(direction == RIGHT){
			if(y < 9 && !tiles[x][y + 1].ifObstacle){
				y++;
			}else{
				changeDir();
			}
		}
		else if(direction == SOUTH){
			if(x < 9 && !tiles[x + 1][y].ifObstacle){
				x++;
			}else{
				changeDir();
			}
		}
		else if(direction == LEFT){
			if(y > 0 && !tiles[x][y - 1].ifObstacle){
				y--;
			}else{
				changeDir();
			}
		}
	}
	bool operator==(const Pos& other)const{
		if(other.x == x && y == other.y)return true;
		else return false;
	}
};

int main(){
	ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");
    
    Pos farmer, cow;
    
    char temp;
    for(int i = 0; i < 10; i++){
    	for(int j = 0; j < 10; j++){
    		fin >> temp;
    		if(temp == '*'){
    			tiles[i][j].ifObstacle = true;
			}else if(temp == 'F'){
				farmer.x = i;
				farmer.y = j;
			}else if(temp == 'C'){
				cow.x = i;
				cow.y = j;
			}
		}
	}
	
	int res = 0;
	while(!(farmer == cow)){
		farmer.goDir();
		cow.goDir();
		res++;
		if(res > 160000){
			res = 0;
			break;
		}
	}
	fout << res << endl;
}

