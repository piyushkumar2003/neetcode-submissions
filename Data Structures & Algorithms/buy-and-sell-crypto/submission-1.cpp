class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //     int mini = INT_MAX;
    //     int res = 0;
    //     int n = prices.size();
    //     for(int i=0; i<n; i++){
    //         mini = min(mini,prices[i]);
    //         for(int j = i+1; j<n; j++){
    //             res = max(res, prices[j]-mini);
    //         }
    //     }
    // return res;

    int l = 0;
    int r = 1;
    int maxPro = 0;

    while(r<prices.size()){
        if(prices[r]>prices[l]){
            maxPro = max(maxPro,prices[r]-prices[l]);
        }
        else l = r;
        r++;
    }
    return maxPro;
    }
};
