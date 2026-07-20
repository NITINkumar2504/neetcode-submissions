class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";

        for (auto &s : strs) {
            encoded.append(to_string(s.size()));
            encoded.push_back('#');
            encoded.append(s);
        }
        cout << encoded;
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;

            decoded.push_back(s.substr(i, length));
            i = i + length;
        }

        return decoded;
    }
};
