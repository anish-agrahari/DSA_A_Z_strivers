static const int _ = [](){ios_base::sync_with_stdio(false);cin.tie(NULL);return 0;}();

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;
        
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }
        
        int count[65][65] = {0};
        int maxOverlap = 0;
        
        for (const auto& p1 : ones1) {
            for (const auto& p2 : ones2) {
                int dr = p2.first - p1.first + 30;
                int dc = p2.second - p1.second + 30;
                maxOverlap = max(maxOverlap, ++count[dr][dc]);
            }
        }
        
        return maxOverlap;
    }
};