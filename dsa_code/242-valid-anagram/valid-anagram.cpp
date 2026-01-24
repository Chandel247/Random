class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()){
            return false;
        }
        unordered_map<char, int> map,map2;
        for (int i=0;i<s.size();i++){
            map[s.at(i)]++;
            map2[t.at(i)]++;
        }

        return (map==map2);
    }
};