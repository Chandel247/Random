class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> table={{0,1}};
        int sum=0;
        int ans=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            sum+=nums[i];
            int comp=sum-k;
            ans+=table[comp];
            table[sum]++;
        }
        return ans;
    }
};