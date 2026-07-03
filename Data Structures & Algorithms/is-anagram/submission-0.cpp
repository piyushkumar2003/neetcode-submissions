class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int n = s.size();
        vector<int>vis(26,0);
        for(int i = 0; i<n; i++){
            vis[s[i]-'a'] += 1 ;
            vis[t[i]-'a'] -= 1;
        }

        for(int it:vis){
            if(it != 0 )return false;
        }

        return true;
    }
};
