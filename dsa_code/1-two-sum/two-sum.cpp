class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> table;
        int n=nums.size();
        for (int i=0;i<n;i++){
            int comp=target-nums[i];
            if (table.count(comp)) return {i,table[comp]};
            table[nums[i]]=i;
        }
        return {-1,-1};
    }
};