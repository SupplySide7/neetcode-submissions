class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {return (int)0;}

        unordered_set<int> nums_set;
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++) {
            nums_set.insert(nums.at(i));
        }

        auto it = nums_set.begin();
        int seq = 1;
        int max_seq = 1;
        int i = 1;
        bool up = true;
        bool down = true;
        while (it != nums_set.end()) {
            if(!up && !down && (nums_set.find(*it + i)) != nums_set.end() 
                && (nums_set.find(*it - i)) != nums_set.end()) {
                seq = seq + 2;
                i++;
                seen.insert(*it + i);
                seen.insert(*it - i);
            }
            else if (up && (nums_set.find(*it + i)) != nums_set.end()) {
                seq++;
                down = false;
                i++;
                seen.insert(*it + i);
            }
            else if (down && (nums_set.find(*it - i)) != nums_set.end()) {
                seq++;
                up = false;
                i++;
                seen.insert(*it - i);
            }
            else {
                it++;
                i = 1;
                if (max_seq < seq) {max_seq = seq;} 
                seq = 1;
                up = true;
                down = true;
            }
        }
        return max_seq;
    }
};