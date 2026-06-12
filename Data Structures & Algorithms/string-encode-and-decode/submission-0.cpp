class Solution {
public:

    string encode(vector<string>& strs) {
        
        string encodedString;
        int length;

        for (const string &str : strs) {
            length = str.length();
            encodedString.append(to_string(length));
            encodedString.push_back('#');
            encodedString.append(str);
        }
        return encodedString;
    }

    vector<string> decode(string s) {

        vector<string> decoded;
        size_t length;
        size_t delim_pos = 0;
        size_t next_delim_pos = 0;
        string subString;
        
        while(delim_pos < s.size())
        {
            next_delim_pos = s.find("#", delim_pos);
            length = stoi(s.substr(delim_pos, (next_delim_pos - delim_pos)));
            subString = s.substr(next_delim_pos + 1, length);
            decoded.push_back(subString);
            delim_pos = next_delim_pos + 1 + length;
        }   
        
        
        return decoded;
    }
};
