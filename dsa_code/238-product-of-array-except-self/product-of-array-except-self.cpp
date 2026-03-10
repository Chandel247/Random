class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(),1);
        vector<int> suffix(nums.size(),1);
        int i=1,j=nums.size()-2;
        while (i<nums.size()){
            prefix[i]=prefix[i-1]*nums[i-1];
            suffix[j]=suffix[j+1]*nums[j+1];
            i++;
            j--;
        }
        i=0;
        vector<int> ans(nums.size());
        while (i<nums.size()){
            ans[i]=prefix[i]*suffix[i];
            i++;
        }
        return ans;
    }
};