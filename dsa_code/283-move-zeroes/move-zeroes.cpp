class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first=0,second=0;
        while (first<nums.size() && second<nums.size()){
            if (nums[first]!=0){
                first++;
            }
            else if (nums[second]!=0){
                swap(nums[first], nums[second]);
                first++;
            }
            second++;
        }
    }
};