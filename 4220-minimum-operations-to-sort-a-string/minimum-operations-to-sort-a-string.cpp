#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
       
        if (is_sorted(s.begin(), s.end())) return 0;
        
        if (s.length() == 2) return -1;
        
        char global_min = *min_element(s.begin(), s.end());
        char global_max = *max_element(s.begin(), s.end());
        
        if (s.front() == global_min || s.back() == global_max) {
            return 1;
        }
        
        for (int i = 1; i < s.length() - 1; ++i) {
            if (s[i] == global_min || s[i] == global_max) {
                return 2;
            }
        }
        return 3;
    }
};
