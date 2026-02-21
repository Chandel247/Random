class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        if (n==0){
            return 0;
        }

        int start=0, end=n-1;
        while (start<end){
            if (nums[start]!=val){
                start++;
            }
            else if (nums[end]==val){
                end--;
            }
            else {
                swap(nums[start], nums[end]);
                start++;
                end--;
            }
        }
        int ans=0;
        int i=0;
        while (i<n && nums[i]!=val){
            ans++;
            i++;
        }
        return ans;
    }
};