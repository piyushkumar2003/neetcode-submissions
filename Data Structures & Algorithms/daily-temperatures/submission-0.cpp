class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        /*intution: 
            element ko stack mein daalo. counter ko increase karo;
            phir next element ko stack mein dalo only if
            next element is less than the last value pushed in
            otherwise pop the element till stack is empty
        */
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> st; // stores indices

        for(int i = 0; i < n; i++) {

            // Current temperature is warmer than
            // temperatures waiting in the stack
            while(!st.empty() && temp[i] > temp[st.top()]) {

                int prevIndex = st.top();
                st.pop();

                ans[prevIndex] = i - prevIndex;
            }

            st.push(i);
        }

        return ans;
    }
};
