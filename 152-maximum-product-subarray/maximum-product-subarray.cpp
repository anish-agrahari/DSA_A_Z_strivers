class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1,suf=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre*=nums[i];
            suf*=nums[nums.size()-i-1];
            maxi=max({pre,suf,maxi});
        }
        return maxi;
    }
};