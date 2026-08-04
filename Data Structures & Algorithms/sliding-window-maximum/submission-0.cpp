class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;

        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            // remove invalid elements (make space for ith element)
            while(!pq.empty() && pq.top().second <= i - k) pq.pop();

            // push ith element
            pq.push({ nums[i], i });

            if(i >= k - 1) ans.push_back(pq.top().first);
        }

        return ans;
    }
};
