#include <algorithm>
#include <stack>
#include <vector>

#define REP(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int largestArea = 0;
        REP(i, 0, heights.size()) {
            if (s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
            }
            else {
                while (!s.empty() && heights[i] < heights[s.top()]){
                    int popped = s.top();
                    s.pop();
                    int start = s.empty() ? -1 : s.top();
                    largestArea = max(largestArea, heights[popped] * (i -  start - 1));
                }
                s.push(i);
            }
        }
        int end = heights.size();
        while (!s.empty()) {
            int popped = s.top();
            s.pop();
            int start = s.empty() ? -1 : s.top();
            largestArea = max(largestArea, heights[popped] * (end - start - 1));
        }
        return largestArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    solution.largestRectangleArea(heights);
}