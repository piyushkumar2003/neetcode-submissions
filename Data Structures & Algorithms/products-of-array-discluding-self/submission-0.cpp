class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product =1;
        int zeroCount = 0;
        for(auto i : nums){
            if (i == 0){
                zeroCount ++;
            }
            if(i !=0) product *= i;
        }
        int n = nums.size();
        vector<int> ans(n,0);
        if(zeroCount >= 2) return ans;
        else if(zeroCount == 1){
            for(int i = 0; i<n; i++){
                if(nums[i] == 0){
                    ans[i] = product;
                }
            }
        }
        else{
            for(int i = 0; i<n; i++){
                ans[i] = product/nums[i];
            }
        }
        return ans;
    }
};
