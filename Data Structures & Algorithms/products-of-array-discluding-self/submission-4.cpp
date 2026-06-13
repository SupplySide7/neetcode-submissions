class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size());
/* Option 1
        for(int i = 0; i < nums.size(); i++) {
            int product = 1;
            for (int j = 0; j < nums.size(); j++) {
                if (j == i) {continue;}
                product = product * nums[j];
            }
            result.at(i) = product;
        }
End Option 1*/      
//* Option 2
        vector<int> prefix_array(nums.size());
        vector<int> suffix_array(nums.size());
        prefix_array.at(0) = 1;
        suffix_array.at(nums.size() - 1) = 1;

        for (int i = 1; i < nums.size(); i++) {
            prefix_array.at(i) = nums.at(i - 1) * prefix_array.at(i - 1);
            suffix_array.at(nums.size() - 1 - i) = nums.at(nums.size() - i) 
                * suffix_array.at(nums.size() - i);
            
        }
        for (int i = 0; i < nums.size(); i++) {
            result.at(i) = prefix_array.at(i) * suffix_array.at(i);
        }
//End Option 2*/
        return result;
    }
};
