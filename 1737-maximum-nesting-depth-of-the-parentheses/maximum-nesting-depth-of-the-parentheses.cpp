class Solution {
public:
    int maxDepth(string s) {
        int cnt=0, ans=0;
        for(char it:s){
            if(it =='(') cnt++;
            else if(it ==')') cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};