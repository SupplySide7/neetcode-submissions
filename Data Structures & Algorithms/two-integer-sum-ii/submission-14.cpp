class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ptrdiff_t l = 0;
        ptrdiff_t r = ssize(numbers) - 1;

        while (l < r) {
            const int sum = numbers[l] + numbers[r];
            if (sum > target) {--r;}
            else if (sum < target) {++l;}
            else {return {static_cast<int>(l) + 1, static_cast<int>(r) + 1};}
        }
        return {};
    }
};
