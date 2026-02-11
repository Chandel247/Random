class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0){
            return "";
        }

        string ans=strs[0];
        int n=strs.size();

        for (int i=0;i<n;i++){
            int j=0;
            while (j<strs[i].size() && ans[j]==strs[i][j] && j<ans.size()){
                j++;
            }
            ans=ans.substr(0,j);
            
            if (strs[i]==""){
                return "";
            }
        }
        return ans;
    }
};