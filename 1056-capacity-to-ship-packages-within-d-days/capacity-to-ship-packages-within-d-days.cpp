class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n =  weights.size();

        int lo = weights[0], hi = 0;

        for(int i = 0; i < n; i++){
            lo = max(lo ,weights[i]);
            hi += weights[i];
        }

        int ans = hi;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;

            int cap = 0, din = 0;

            for(int i = 0; i < n; i++){
                cap += weights[i];

                if(cap >= mid) {
                    din++;

                    if(cap == mid) cap = 0;
                    else cap = weights[i];
                }
            }

            if(cap > 0) din++;

            if(din <= days) {
                ans = mid;
                hi = mid - 1;
            }

            else lo = mid + 1;
        }

        return ans;
    }
};