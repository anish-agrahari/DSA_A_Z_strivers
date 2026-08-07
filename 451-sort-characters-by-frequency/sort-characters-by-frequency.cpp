class Solution {
public:
    string frequencySort(string s) {
        vector<int> temp(123,0);
        for(auto x:s) temp[x]++;
        vector<pair<int,char>> freq;
        for(int i=48;i<=122;i++)
        if(temp[i]>0) freq.push_back({temp[i],(char)i});

        sort(freq.begin(), freq.end(), greater<pair<int,char>>());
        string ans ="";
        for(auto x: freq){
            string str(x.first,x.second);
            ans+=str;
        }
        return ans;
            }
};