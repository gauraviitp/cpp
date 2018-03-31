#include <iostream>
#include <limits>
#include <vector>
typedef long long NumType;

using namespace std;

template <class T>
class Algorithms {
    public:
        struct Result {
            T sum;
            int start, end;
        };
        Result maxContiguousSumSubArray(vector<T>& v);
};

template <typename T>
typename Algorithms<T>::Result Algorithms<T>::maxContiguousSumSubArray(vector<T>& v){
    Result res;
    T max_so_far = numeric_limits<T>::min();
    T max_ending_here = 0;
    int start = 0;
    for(int i = 0; i < v.size(); ++i){
        max_ending_here += v[i];
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
            res.start = start;
            res.end = i;
            res.sum = max_so_far;
        }
        if(max_ending_here < 0){
            start = i + 1;
            max_ending_here = 0;
        }
    }
    return res;
}

int main() {
  vector<NumType> v = {-1, 5, 3, -4};
  Algorithms<NumType> algo;
  Algorithms<NumType>::Result res = algo.maxContiguousSumSubArray(v);
  cout << "start: " << res.start << ", end: " << res.end << ", sum: " << res.sum << endl;
  return 0;
}
