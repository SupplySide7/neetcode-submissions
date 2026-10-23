class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int SIZE = static_cast<int>(nums.size());
        int left = 1;
        vector<int> answer(nums.size(), 1);

        for (int i = 0; i < SIZE; i++) {
            answer[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = SIZE - 1; i >= 0; i--) {
            answer[i] *= right;
            right *= nums[i];
        }
        return answer;
    }
};
