class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramArray;
        unordered_map<string, vector<string>> anagramMap;

        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(str);
        }
        for (const auto& [key, vectorString] : anagramMap) {
            anagramArray.push_back(vectorString); 
        }
        return anagramArray;
    }
};
