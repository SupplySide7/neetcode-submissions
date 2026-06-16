class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> nums_set;
        nums_set.insert(nums.begin(), nums.end());

        int seq = 0;
        int max_seq = 0;
        
        for (auto num : nums_set) {
            if (!nums_set.contains(num - 1)) {
                seq++;
                while (nums_set.contains(num + seq)) {
                    seq++;
                }
                max_seq = max(max_seq, seq);
                seq = 0;
            }
        }
        return max_seq;
  }
};