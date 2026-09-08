class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff=INT_MAX, res;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(diff<minDiff){
                    minDiff=diff;
                    res=sum;
                }
                if(sum<target) j++;
                else if(sum>target) k--;
                else{
                    j++; k--;
                }
            }
        }
        return res;
    }
};