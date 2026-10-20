class Solution {
public:

    string encode(vector<string>& strs) {
        string out;
        for (const string& s : strs) {
            out += to_string(s.size());
            out += '#';
            out += s;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        int last_pos = 0;
        while (last_pos < s.size()) {
            int hash_pos = static_cast<int>(s.find('#', last_pos));
            int length = stoi(s.substr(last_pos, hash_pos - last_pos));
            string substring = s.substr(hash_pos + 1, length);
            decoded_strings.push_back(substring);
            last_pos = hash_pos + length + 1;
        }
        return decoded_strings;
    }
};
