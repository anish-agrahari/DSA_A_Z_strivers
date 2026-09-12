class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        vector<int> result(st.begin(), st.end());
        int n=result.size();
        if(n<3) return result[n-1];
        else return result[n-3];
    }
};