class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> uniqueSet;
        for (const int num1 : nums) {
            auto [it, inserted] = uniqueSet.insert(num1);
            if (!inserted) {
                return true;
            }
        }
        return false;
    }
};