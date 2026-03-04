class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1){
            return 1;
        }
        int curr=0;
        for (int uniq=0;uniq<nums.size();uniq++){
            if (nums[curr]!=nums[uniq]){
                curr++;
                nums[curr]=nums[uniq];
            }
        }
        return curr+1;
    }
};