class Solution {
public:
    bool isPalindrome(string s) {
        string input="";
        for (char a:s){
            if ((a>='A')&&(a<='Z')){
                a+=32;
                input.push_back(a);
            }
            else if ((a>='a')&&(a<='z')){
                input.push_back(a);
            }
            else if ((a>='0')&&(a<='9')){
                input.push_back(a);
            }
        }
        int start=0, end=input.size()-1;
        while (start<end){
            if (input[start]!=input[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};