class Solution {
public:
    int search(vector<int>& nums, int key) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        // int ans = -1;
        while(low<=high){
            int mid = (high+low)/2;
            if(nums[mid] == key) return mid;
            if(nums[low]<=nums[mid]){
                if((nums[low]<=key)&&(key < nums[mid])){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if((nums[mid]<key)&&(key <= nums[high])){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
