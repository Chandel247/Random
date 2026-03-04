class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=1, i=0, j=1;
        while (j<nums.size()){
            if (nums[i]!=nums[j]){
                swap(nums[++i], nums[j]);
                res++;
            }
            j++;
        }
        return res;
    }
};