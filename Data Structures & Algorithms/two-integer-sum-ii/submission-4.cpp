class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        
        vector<int> result;

        for (int i = 0; i < numbers.size() - 1; i++) {
            int needed = target - numbers[i];
            int front = 0;
            int end = numbers.size() - 1;

            while (front <= end) {
                int middle = front + (end - front)/2;

                if (numbers[middle] == needed) {
                    result = {i + 1, middle + 1};
                    return result;
                }
                if (needed > numbers[middle]) {
                    front = middle + 1;
                } else if ((middle - 1) > 0) {
                    end = middle - 1;
                }        
            }
        }
        return {};
    }
};
