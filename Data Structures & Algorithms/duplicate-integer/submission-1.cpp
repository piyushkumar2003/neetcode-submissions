class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // optimised approch
            // 1. sort
            // 2. create indx arr
            // 3. negate all the entries
            // 4. loop over indx arr, if entry is >0 that number is duplicate

        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     int val = abs(nums[i]);

        //     if(nums[val-1] < 0){
        //         return true;
        //     }else{
        //         nums[val-1] = -nums[val-1];
        //     }
        // }
        // return false;
        

        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]) return true;
        }
        return false;
    }
};