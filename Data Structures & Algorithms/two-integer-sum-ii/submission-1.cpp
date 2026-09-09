class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0;
        int r = n-1;
        while(l<r){
            int newTarget = numbers[l]+numbers[r];
            if(newTarget > target) r--;
            else if(newTarget < target) l++;
            else{
                return { l + 1, r + 1 };
            }
        }
        return {};
    }
};
