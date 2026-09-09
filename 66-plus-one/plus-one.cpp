class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l=digits.size();
        for(int i=l-1;i>=0;i--){
            if((digits[i]+1)<=9){
                digits[i]++;
                return digits;
            }
            else digits[i]=0;
        }
        vector<int> res(l+1,0);
        res[0]=1;
        return res;
    }
};