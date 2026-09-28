class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int leftptr = 0;
        int rightptr = 0;
        vector<bool>vis(128,false);
        int res = 0;
        while(rightptr < s.size()){
            while(vis[s[rightptr]] == true){
                vis[s[leftptr]] = false;
                leftptr++;
            }
            vis[s[rightptr]] = true;
            res = max(res, (rightptr-leftptr+1));
            rightptr++;
        }
        return res;
    }
};
