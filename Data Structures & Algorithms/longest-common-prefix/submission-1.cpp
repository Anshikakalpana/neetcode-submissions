class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> s; 

        for (int i = 0; i < strs[0].length(); i++) {
            s.push_back(strs[0][i]); 
        }

        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if ( s[j] != strs[i][j]) {
                  
                    while (s.size() > j) {
                        s.pop_back();
                    }
                    break;  
                }
            }
            if (s.empty()) return "";
        }

        return string(s.begin(), s.end());  
    }
};
