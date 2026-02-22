class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate, count=0;
        for (int num:nums){
            if (num==candidate){
                count++;
            }
            else {
                if (count==0){
                    candidate=num;
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return candidate;
    }
};