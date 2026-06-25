class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = static_cast<int>(piles.size());
        int max_pile = 0;
        int hours = 0;
        
        max_pile = *max_element(piles.begin(), piles.end());
    
        int right = max_pile;
        int left = 1;
        int k_min = max_pile;

        while (left <= right) {
            int k_midpoint = left + (right - left)/2;
            hours = 0;
            for (int pile : piles) {
                hours = hours + (pile + k_midpoint - 1)/k_midpoint;
            }
            
            if(hours > h) { // total hours sum is monotonically decreasing as k increases
                left = k_midpoint + 1;
            } else {
                k_min = std::min(k_min, k_midpoint);
                right = k_midpoint - 1;
            }
        }
        return k_min;
    }
};
