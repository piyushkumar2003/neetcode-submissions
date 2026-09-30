class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
if(n > m) return false;
        vector<int>maps1(26,0);
        vector<int>maps2(26,0);

        for(int i = 0; i<n; i++){
            maps1[s1[i]-'a']++;
        }

        for(int i = 0; i<n; i++){
            maps2[s2[i]-'a']++;
        }

        if(maps1 == maps2) return true;

        for(int i = n; i<m; i++){
            maps2[s2[i]-'a']++;
            maps2[s2[i-n]-'a']--;
            if(maps1 == maps2) return true;
        }
        return false;
    }
};
