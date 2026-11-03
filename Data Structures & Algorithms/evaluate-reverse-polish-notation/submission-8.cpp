class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& s : tokens) {
            bool mathop = (s.size() == 1) && 
                            string_view("+-/*").find(s[0]) != string_view::npos;
            if (!mathop) {
                int operand = 0;
                from_chars(s.data(), s.data() + s.size(), operand);
                stk.push(operand);
            }
            else {
                const int rt_operand = stk.top(); stk.pop();
                const int lt_operand = stk.top(); stk.pop();
                switch(s[0]) {
                    case '+': stk.push(lt_operand + rt_operand); break;
                    case '-': stk.push(lt_operand - rt_operand); break; 
                    case '*': stk.push(lt_operand * rt_operand); break;
                    case '/': stk.push(lt_operand / rt_operand); break;
                    default: break;
                }
            }
        } return stk.top();
    }
};
