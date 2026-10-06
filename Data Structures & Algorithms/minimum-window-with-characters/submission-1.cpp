class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window;
        unordered_map<char,int> countT;
        int have = 0;
        for(auto c:t){
            countT[c]++;
        }
        int need = countT.size();
        int resLen = INT_MAX;
        pair<int,int> res = {-1,-1};

        int l= 0;int r = 0;
        
        while(r<s.size()){
            window[s[r]]++;
            if(countT.find(s[r]) != countT.end() && window[s[r]] == countT[s[r]]){
                have++;
            }

            while(have == need){
                if((r-l+1)<resLen){
                    resLen = r-l+1;
                    res = {l,r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]]<countT[s[l]]){
                    have--;
                }
                l++;
            }
            r++;
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);

    }
};
