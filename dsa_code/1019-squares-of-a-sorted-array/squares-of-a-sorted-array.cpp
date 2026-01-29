class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int end=n-1;

        vector<int> ans(n);

        for (int i=(ans.size()-1);i>=0;i--){
            if (abs(nums[start])>abs(nums[end])){
                ans.at(i)=nums[start]*nums[start];
                start++;
            }
            else{
                ans.at(i)=nums[end]*nums[end];
                end--;
            }
        }
        return ans;
    }
};