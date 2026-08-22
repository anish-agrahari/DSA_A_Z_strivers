class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k> bloomDay.size()) return -1;

        int maxi = INT_MIN;
        for(int i = 0;i < n;i++) maxi = max(maxi,bloomDay[i]);

        int low = 0, high = maxi;
        while(low <= high){
            int mid = low + (high-low)/2;//no days passed

            int cnt = 0,bq=0;
            for(int i = 0; i < n;i++){
                if(bloomDay[i]<=mid){
                    cnt++;
                }else cnt = 0;
                if(cnt==k){
                    bq++;
                    cnt = 0;
                }
            }
            
            if(bq>=m) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};