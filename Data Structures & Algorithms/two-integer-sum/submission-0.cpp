class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> s;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int remainder = target-nums[i];
            if(s.find(remainder) != s.end()){
                res = {s[remainder],i};
            }
            
            s[nums[i]] = i;
        }
        return res;
    }
};
