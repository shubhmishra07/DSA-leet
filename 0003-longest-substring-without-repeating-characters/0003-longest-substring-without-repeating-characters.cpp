class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l =0 , r=0;
        int maxlen = 0;
        vector<int>mp(256, -1);
        int len =0;
        while(r<n){
            if(mp[s[r]]!=-1){
                if(mp[s[r]]>=l){
                    l = mp[s[r]] + 1;
                }
            }
            len = r-l+1;
            maxlen = max(len , maxlen);
            mp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};