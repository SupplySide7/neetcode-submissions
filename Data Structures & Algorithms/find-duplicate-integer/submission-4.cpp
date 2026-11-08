class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (fast != slow);

        int finder = 0;
        while (finder != slow) {
            finder = nums[finder];
            slow = nums[slow];
        }
        return finder;
    }
};
