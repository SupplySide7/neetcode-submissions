void decrementOrErase(char c, unordered_map<char, int> &freq_map);

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        std::unordered_map<char, int> s1Freq;
        std::unordered_map<char, int> s2Freq;

        for (int i = 0; i < static_cast<int>(s1.size()); i++) {
            s1Freq[s1[i]]++;
            s2Freq[s2[i]]++;
        }
        
        if (s2Freq == s1Freq) {return true;}

        for (int right = static_cast<int>(s1.size()), left = 0;
             right < static_cast<int>(s2.size()); right++, left++) {
                
            char l = s2[left]; char r = s2[right];
            decrementOrErase(l, s2Freq); s2Freq[r]++;

            if (s2Freq == s1Freq) {return true;}
        }
        return false;
    }
};

void decrementOrErase(char c, unordered_map<char, int> &freq_map) {
    
    auto it = freq_map.find(c);
    if (it != freq_map.end()) {
        if (it->second > 1) {
            it->second--;
        } else {
            freq_map.erase(it);
        }
    }
}
