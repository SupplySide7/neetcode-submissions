class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramArray;
        unordered_map<string, vector<string>> anagramMap;

        for (const string &str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(str);
        }
        for (pair<const string, vector<string>> &entry : anagramMap) {
            anagramArray.push_back(entry.second); 
        }
        return anagramArray;
    }
};
