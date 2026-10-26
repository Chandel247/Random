class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        for (int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> min;
        for (auto& [num, count]:mp){
            min.push({count,num});
            if (min.size()>k){
                min.pop();
            }
        }

        vector<int> ans;
        while (!min.empty()){
            ans.push_back(min.top().second);
            min.pop();
        }

        return ans;
    }
};