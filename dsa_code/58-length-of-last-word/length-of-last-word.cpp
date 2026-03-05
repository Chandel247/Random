class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0, spaces=0;
        int n=s.size();
        for (int i=0;i<n;i++){
            if (spaces>0 && s[i]!=' '){
                spaces=0;
                count=1;
            }
            else if (s[i]!=' '){
                count++;
            }
            else if (s[i]==' '){
                spaces++;
            }
        }
        return count;
    }
};