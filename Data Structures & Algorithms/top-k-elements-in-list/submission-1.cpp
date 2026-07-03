class Solution {
public:
    struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int count = 0;
        for(auto num: nums){
            freq[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for(auto f: freq){
            pq.push({f.first, f.second});
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};
