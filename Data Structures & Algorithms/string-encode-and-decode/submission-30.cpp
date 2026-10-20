class Solution {
public:

    string encode(vector<string>& strs) {
        string out;
        for (const string& s : strs) {
            out += std::to_string(s.size());
            out += '#';
            out += s;
        }
        return out;
    }

    vector<string> decode(string s) {
        size_t last_pos = 0;
        size_t hash_pos = 0;
        vector<string> result;
        while (last_pos < s.size()) {
             hash_pos = s.find('#', last_pos);
             int length = std::stoi(s.substr(last_pos, hash_pos - last_pos));
             result.push_back(s.substr(hash_pos + 1, length));
             last_pos = hash_pos + length + 1;
        }
        return result;
    }
};
