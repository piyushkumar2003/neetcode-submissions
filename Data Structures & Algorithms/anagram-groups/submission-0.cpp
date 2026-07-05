class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. sort strs
        // 2. if size of (strs[i]) == size of (strs[i-1])
                // call for anagram fn if true push to final vector
        // 3. return final vector
        
        unordered_map<string, vector<string>>mp;
        vector<vector<string>> ans;
        for(string s : strs){
            vector<int> hash(26,0);
            for(char c : s){
                hash[c-'a']++;
            }
            string key = "";
            for(int i : hash){
                key += to_string(i) + '#';
            }
            mp[key].push_back(s);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;


    }
};
