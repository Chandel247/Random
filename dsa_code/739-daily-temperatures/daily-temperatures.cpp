class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<int> stk;
        for (int i=0;i<n;i++){
            while (!stk.empty() && temperatures[i]>temperatures[stk.top()]){
                int temp_ind=stk.top();
                stk.pop();
                ans[temp_ind]=i-temp_ind;
            }
            stk.push(i);
        }
        return ans;
    }
};