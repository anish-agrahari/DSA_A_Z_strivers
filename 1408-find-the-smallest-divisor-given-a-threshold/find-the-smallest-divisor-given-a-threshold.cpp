class Solution {
public:
    int possible(vector<int>& nums, int t,int d, int n){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]+d-1)/d;
            if(sum>t) return sum;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        int mini=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int sum=possible(nums,threshold,mid,n);
            if(sum<=threshold){
                mini=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mini;
    }
};