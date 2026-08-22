class Solution {
public:
    int count(vector<int>& bloomDay, int mid, int m, int k){
        int n=bloomDay.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid)
            count++;
            else count=0;
            if(count==k){
                count=0;
                m--;
            }
            if(m<=0) return 1;
        }
        return 0;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long long)m*k>n) return -1;
        int low=INT_MAX, high=0;
        for(int i=0;i<n;i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            int possible=count(bloomDay,mid,m,k);
            if(possible==1){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};