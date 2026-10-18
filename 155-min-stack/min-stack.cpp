class MinStack {
public:
    vector<pair<int,int>>vec;
    MinStack() {
        
    }
    
    void push(int value) {
        if(vec.empty())
        vec.push_back({value,value});
        else{
            auto [y,mini]=vec.back();
            vec.push_back({value,min(mini,value)});
        }
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        auto [y,mini]=vec.back();
        return y;
    }
    
    int getMin() {
        auto [y,mini]=vec.back();
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */