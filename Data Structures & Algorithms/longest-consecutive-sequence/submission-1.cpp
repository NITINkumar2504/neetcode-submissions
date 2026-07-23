class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int maxCount = 1;
        for(auto num: s){
            if(!s.count(num - 1)){
                int start = num;
                int count = 1;

                while(s.count(start + 1)){
                    count++;
                    start++;
                }

                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
