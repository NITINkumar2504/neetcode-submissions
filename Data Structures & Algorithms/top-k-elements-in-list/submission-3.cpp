class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(auto &num: nums){
            mp[num]++;
        }

        vector<vector<int>> bucket(n + 1);
        // index = freq
        // value = elements
        // bulcet[i] = elements having i freq

        for(auto &it: mp){
            int ele = it.first;
            int freq = it.second;

            bucket[freq].push_back(ele);
        }

        vector<int> ans;
        for(int i = n; i >= 0; i--){
            for(auto &ele : bucket[i]){
                ans.push_back(ele);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
