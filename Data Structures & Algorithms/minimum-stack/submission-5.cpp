class MinStack {
private:
    vector<pair<int, int>> stck;
public:
    void push(int val) {
        if (stck.empty()) stck.push_back({val, val});
        else {
            int previous = stck.back().second;
            stck.push_back({val, std::min(val, previous)});
        }
    }
    
    void pop() {stck.pop_back();}
    
    int top() {return stck.back().first;}
    
    int getMin() {return stck.back().second;}
};
