class MinStack {
private:
    vector<pair<int, int>> stck;
    int min = numeric_limits<int>::max();

public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (stck.empty()) stck.push_back({val, val});
        else {
            int previous = stck.back().second;
            int min = std::min(val, previous);
            stck.push_back({val, min});
        }
    }
    
    void pop() {
        stck.pop_back();
    }
    
    int top() {
        return stck.back().first;
    }
    
    int getMin() {
        return stck.back().second;
    }
};
