class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int>seen;
        for (const int& num : nums) {
            auto [intertor, inserted] = seen.insert(num);
            if (!inserted) {return true;}
        }
        return false;
    }
};