class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stck;
        for (const string& s : tokens) {
            const bool mathoperator = s.size() == 1 && 
                                    string_view("+-*/").find(s[0]) != string_view::npos;
            if (!mathoperator) {
                int operand = 0;
                from_chars(s.data(), s.data() + s.size(), operand);
                stck.push_back(operand);
            } else {
                const int rightoperand = stck.back(); stck.pop_back();
                const int leftoperand = stck.back(); stck.pop_back();

                if (s[0] == '+') stck.push_back(leftoperand + rightoperand);
                else if (s[0] == '-') stck.push_back(leftoperand - rightoperand);
                else if (s[0] == '/') stck.push_back(leftoperand / rightoperand);
                else if (s[0] == '*') stck.push_back(leftoperand * rightoperand);
            }
        } return stck.back();
    }
};
