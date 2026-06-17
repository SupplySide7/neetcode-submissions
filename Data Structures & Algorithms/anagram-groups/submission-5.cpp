class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramArray;
        unordered_map<string, vector<string>> anagramMap;

        for (const string &str : strs) {            
            vector<int> count(26, 0);
            for (char c : str) {count[c - 'a']++;}

            string key = std::to_string(count[0]);
            for (int i = 1; i < 26; i++) {
                key += ",";
                key += std::to_string(count[i]);
            }
            
            anagramMap[key].push_back(str);
        }        
        for (pair<const string, vector<string>> &entry : anagramMap) {
            anagramArray.push_back(entry.second); 
        }
        return anagramArray;
    }
};
