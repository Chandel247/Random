class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        int n=nums.size();
        prefix.resize(n+1,0);
        for (int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        int max_Sum=prefix[n];
        for (int i=0;i<n;i++){
            if (prefix[i]==(max_Sum-prefix[i+1])){
                return i;
            }
        }
        return -1;
        
    }
};