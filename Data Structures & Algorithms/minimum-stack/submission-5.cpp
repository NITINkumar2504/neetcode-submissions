class MinStack {
public:
    stack<long> s;
    long mini;

    MinStack() {
    }
    
    void push(int val) {
        if(s.empty()){
            mini = val;
            s.push((long)val);
        }
        else{
            if(mini <= val){   // min does not change
                s.push((long)val);
            }
            else{
                s.push(2L * val - mini);   // newVal
                mini = val;
            }
        }
    }
    
    void pop() {
        long newVal = s.top();

        if(newVal < mini){   // value was modified
            mini = 2 * mini - newVal;   // rollback mini, (mini = val, line 20) so we are using mini = val, 2 * val - mini = newVal(stored value) => 2 * val - newVal = mini;
        }

        s.pop();
    }
    
    int top() {
        long val = s.top();

        if(val < mini){  // value was modified
            return (int)mini;
        }
        else{
            return (int)val;
        }
    }
    
    int getMin() {
        return (int)mini;
    }
};
