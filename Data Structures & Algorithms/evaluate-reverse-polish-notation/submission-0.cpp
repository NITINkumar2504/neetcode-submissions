class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<string> s;

        for(auto &token: tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                int a = stoi(s.top());
                s.pop();

                int b = stoi(s.top());
                s.pop();

                if(token == "+") s.push(to_string(a + b));
                else if(token == "-") s.push(to_string(b - a));
                else if(token == "*") s.push(to_string(a * b));
                else s.push(to_string(b / a));   
            }
            else{
                s.push(token);
            }
        }

        return stoi(s.top());
    }
};