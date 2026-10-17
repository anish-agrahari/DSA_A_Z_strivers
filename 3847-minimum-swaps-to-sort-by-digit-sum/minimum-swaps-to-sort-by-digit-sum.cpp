class Solution {
private:   
    static int digisum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    static bool cmp(int a,int b){
        int sa=digisum(a);
        int sb=digisum(b);
        if(sa==sb) return a<b;
        return sa<sb;
    }
public:
    int minSwaps(vector<int>& nums) {
        vector<int> temp=nums;

        sort(temp.begin(),temp.end(),cmp);

        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++) m[nums[i]]=i;

        int swaps=0;
        for(int i=0;i<nums.size();i++){
            if(temp[i]!=nums[i]){
                int idx=m[temp[i]];
                swap(nums[i],nums[idx]);

                m[nums[i]]=i;
                m[nums[idx]]=idx;

                swaps++;
            }
        }

        return swaps;
    }
};