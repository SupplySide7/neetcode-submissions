class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set;
        
        for (const int &num: nums) {
            auto [it, inserted] = nums_set.insert(num);
            if (!inserted) {return true;}
        }
        return false;
    }
};