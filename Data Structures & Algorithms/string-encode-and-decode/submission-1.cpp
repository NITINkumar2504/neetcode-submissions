class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0) return "";

        string encoded = "";
        for(auto &str: strs){
            for(auto &ch: str){
                encoded.push_back(ch);
            }
            encoded.push_back(char(257));
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string temp = "";

        for(auto &ch: s){
            if(ch == char(257)){
                decoded.push_back(temp);
                temp = "";
            }
            else{
                temp.push_back(ch);
            }
        }

        return decoded;
    }
};
