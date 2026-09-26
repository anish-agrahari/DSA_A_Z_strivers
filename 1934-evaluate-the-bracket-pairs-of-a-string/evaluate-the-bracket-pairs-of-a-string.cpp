class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> knowledgeMap;
        for(auto& pair: knowledge){
            knowledgeMap[pair[0]]=pair[1];
        }
        string result;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                int closingBracketIndex =s.find(')', i+1);
                string key=s.substr(i+1, closingBracketIndex-i-1);
            if(knowledgeMap.count(key)){
                result+=knowledgeMap[key];
            }
            else{
                result+='?';
            }
            i=closingBracketIndex;
            }
            else{
                result+=s[i];
            }
        }
        return result;
    }
};