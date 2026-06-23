class Solution {
public:
    int characterReplacement(string s, int k) {

    int left = 0;
    int right = 0;
    int max_window = 0;
    int window = 0;
    int max_freq = 0;
    unordered_map<char, int> freq_map;

    for (right = 0; right < s.size(); right++) {
        char r = s[right];
        freq_map[r]++;
        max_freq = std::max(max_freq,freq_map[r]);

        while ((right - left + 1) > k + max_freq) {
            char l = s[left];
            freq_map[l]--;
            left++;
        }
        window = right - left + 1;
        max_window = std::max(max_window, window);
    }
    return max_window;
    }
};