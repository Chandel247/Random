class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size()==0){
            return true;
        }
        int i = 0, j = 0;
        int n = t.size();
        while (j < n) {
            if (s[i] == t[j] && i<s.size()) {
                i++;
                j++;
                if (i==s.size()){
                    return true;
                }
            }
            else {
                j++;
            }
        }
        return false;
    }
};