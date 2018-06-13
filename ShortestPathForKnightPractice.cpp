//Given 8*8 chass board, 
//Current position of Knight is $
//Destination position of Knight is @
//Shortest path for a Knight to travel $ to @

//Minimum number of steps

//  1   2   3   4   5   6   7   8  
//1 *   *   *   *   *   *   *   *
//2 *   *   n   *   n   *   *   *
//3 *   n   *   *   *   n   *   *
//4 *   *   *   $   *   *   *   *
//5 *   n   *   *   *   n   *   *
//6 *   *   n   *   n   *   *   *
//7 *   *   *   *   *   *   *   *
//8 *   *   *   @   *   *   *   *

#include <cassert>
#include <queue>
#include <vector>

using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

class Cell{
public:
	int x;
	int y;
	Cell(int px, int py): x(px), y(py){}
	bool operator==(const Cell& other){
		return x == other.x && y == other.y;
	}
};

bool onChessBoard(int n, int x, int y){
	if(x > n || x < 1) return false;
	if(y > n || y < 1) return false;
	return true;
}

int countMinSteps(int n, const Cell *start, const Cell *end){
	if(!onChessBoard(n, start->x, start->y)) return -1;
	if(!onChessBoard(n, end->x, end->y)) return -1;
	queue<Cell *> q({new Cell(start->x, start->y)});
	int dx[] = {-2, -2, -1, -1,  1, 1,  2, 2};
	int dy[] = {-1,  1, -2,  2, -2, 2, -1, 1};
	VVI dist(n + 1, VI(n + 1, -1));
	dist[start->x][start->y] = 0;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		if(*cur == *end) {
			return dist[cur->x][cur->y];
		}
		for(int i = 0; i < 8; ++i){
			int nextx = cur->x + dx[i];
			int nexty = cur->y + dy[i];
			if(onChessBoard(n, nextx, nexty)){
				if(dist[nextx][nexty] == -1){
					dist[nextx][nexty] = dist[cur->x][cur->y] + 1;
					q.push(new Cell(nextx, nexty));
				}
			}
		}
		delete cur;
	}
	return -1;
}

int main(){
		// case 1, $=(4, 4), @=(8, 4)
		assert(countMinSteps(8, new Cell(4, 4), new Cell(8, 4)) == 2);
		// case 2, $=(6, 2), @=(8, 4)
		assert(countMinSteps(8, new Cell(6, 2), new Cell(8, 4)) == 4);
}
