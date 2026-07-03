class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto str: strs){
            vector<int> count(26, 0);
            for(auto ch : str){
                count[ch - 'a']++;
            }

            string key = "";
            for(auto val: count){
                key = key + '-' + to_string(val);
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto p: mp){
            ans.push_back(p.second);
        }

        return ans;
    }
};
