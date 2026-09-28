class Solution {
public:
    int maxDepth(string s) {
        int maxState = 0;
        int currentState = 0;
        for(int i =0 ; i<s.length() ; i++){
            if(s[i]=='('){
                currentState++;
            }else if(s[i]==')'){
                currentState--;
            }
            maxState = max(maxState , currentState);
        }
        return maxState;
    }
};