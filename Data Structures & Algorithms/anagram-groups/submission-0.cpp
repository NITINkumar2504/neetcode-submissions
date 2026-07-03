class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<string> temp(strs);
        vector<vector<string>> ans;
        int n = strs.size();

        for(auto &t: temp){
            sort(t.begin(), t.end());
        }

        for(int i = 0; i < n; i++){
            mp[temp[i]].push_back(strs[i]);
        }

        for(auto m: mp){
            ans.push_back(m.second);
        }

        return ans;
    }
};
