class Solution {
public:
    int minAddToMakeValid(string s) {
        int size=0;
        int open=0;
        for(char &ch:s){
            if(ch=='('){
                size++;
            }else{
                size>0 ? size-- :open++;
            }
        }
        return size+open;
    }
};