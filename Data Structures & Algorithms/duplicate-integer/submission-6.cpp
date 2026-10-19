class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique_set;
        for (const int& num : nums) {
            auto [it, inserted] = unique_set.insert(num);
            if (!inserted) {return true;}
        }
        return false;
    }
};