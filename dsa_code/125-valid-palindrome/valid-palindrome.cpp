class Solution {
public:
    bool isPalindrome(string s) {
        string input="";
        int n=s.size();
        for (int i=0;i<n;i++){
            int a=static_cast<unsigned int>(s[i]);
            if ((a>=65)&&(a<=90)){
                a+=32;
                input.push_back(static_cast<char>(a));
            }
            else if ((a>=97)&&(a<=122)){
                input.push_back(static_cast<char>(a));
            }
            else if ((a>=48)&&(a<=57)){
                input.push_back(static_cast<char>(a));
            }
        }
        int start=0, end=input.size()-1;
        while (start<end){
            if (static_cast<int>(input[start]!=static_cast<int>(input[end]))) return false;
            start++;
            end--;
        }
        return true;
    }
};