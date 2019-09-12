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

class Point{
public:
    int x;
    int y;
    Point(int px, int py) : x(px), y(py){}
    bool operator==(const Point& other) const{
	return x == other.x && y == other.y;
    }
};

bool onChessBoard(int n, int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < n);
}

// $ = (x, y)
//(x - 1, y + 2), (x + 1, y + 2)
//(x - 1, y - 2), (x + 1, y - 2)
// x +- 2 and y +- 1 // four more points  

int countMinSteps(int n, const Point *start, const Point *end){
    if (!onChessBoard(n, start->x, start->y)) return -1;
    if (!onChessBoard(n, end->x, end->y)) return -1;
    VVI dist(n, VI(n, -1));
    dist[start->x][start->y] = 0;
    queue<Point *> q({new Point(start->x, start->y)});
    int dx[] = {-1, 1, -1,  1, 2,  2, -2, -2};
    int dy[] = { 2, 2, -2, -2, 1, -1,  1, -1};
    while(!q.empty()){
        Point *curPos = q.front(); q.pop();
	//check if reached the destination
	if(*curPos == *end) return dist[curPos->x][curPos->y];
		
        int curx = curPos->x;
        int cury = curPos->y;
	delete curPos;
        
	//push the next 8 coordinates if not visited
        for(int i = 0; i < 8; ++i){
            int nextx = curx + dx[i];
            int nexty = cury + dy[i];
            if(onChessBoard(n, nextx, nexty)){
                if(dist[nextx][nexty] == -1){
                    dist[nextx][nexty] = dist[curx][cury] + 1;
                    q.push(new Point(nextx, nexty));
                }
            }
        } 
    }
	return -1;
}

int main(){
		// case 1, $=(4, 4), @=(8, 4)
		assert(countMinSteps(8, new Point(3, 3), new Point(7, 3)) == 2);
		// case 2, $=(6, 2), @=(8, 4)
		assert(countMinSteps(8, new Point(5, 1), new Point(7, 3)) == 4);
}





