class Solution {
public:
    int Count(vector<int> weights, int mid,int n, int days){
        int count=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+weights[i]>mid){
                count++;
                sum=weights[i];
                if(count>days) return 1;
            }
            else{
                sum+=weights[i];
            }
        }
        if(count>days) return 1;
        else return 0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=0;
        int h=0;
        for(int i=0;i<n;i++){
            h+=weights[i];
            l=max(l,weights[i]);
        }
        while(l<=h){
            int mid=l+(h-l)/2;
            int count=Count(weights,mid,n,days);
            if(count==1) l=mid+1;
            else h=mid-1;
        }
        return l;
    }
};