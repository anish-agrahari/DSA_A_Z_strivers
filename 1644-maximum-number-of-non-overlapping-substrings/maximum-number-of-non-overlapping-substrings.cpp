class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> first(26, -1);
        vector<int> last(26, -1);
        int n = s.length();
        
        // Step 1: Find the first and last occurrence of each character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) {
                first[c] = i;
            }
            last[c] = i;
        }
        
        vector<pair<int, int>> validIntervals;
        
        // Step 2: Expand boundaries for each character to find valid substrings
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;
            
            int left = first[i];
            int right = last[i];
            bool isValid = true;
            
            // Expand the window to include all instances of any character inside it
            for (int j = left; j <= right; ++j) {
                int c = s[j] - 'a';
                left = min(left, first[c]);
                right = max(right, last[c]);
                
                // If a character inside starts before our initial character, 
                // this interval is redundant/invalid for our greedy starting point.
                if (left < first[i]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                validIntervals.push_back({left, right});
            }
        }
        
        // Step 3: Sort intervals by their end times (Greedy Activity Selection)
        sort(validIntervals.begin(), validIntervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        
        vector<string> res;
        int lastEnd = -1;
        
        // Step 4: Select non-overlapping intervals
        for (const auto& interval : validIntervals) {
            if (interval.first > lastEnd) {
                res.push_back(s.substr(interval.first, interval.second - interval.first + 1));
                lastEnd = interval.second;
            }
        }
        
        return res;
    }
};