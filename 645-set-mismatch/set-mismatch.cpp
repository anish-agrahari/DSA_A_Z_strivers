class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int duplicate=-1;
        int missing=-1;
        for(int i=0;i<nums.size();i++){
            int val=abs(nums[i]);
            if(nums[val-1]<0) duplicate=val;
            else nums[val-1]=-nums[val-1];
        }
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                missing=i+1;
                break;
            }
        }
        return {duplicate,missing};
    }
};