class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int i = 1;
        int maxSeq = 1;
        int currSeq = 1;

        while(i < nums.size()){
            if(nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            else if(nums[i] - nums[i - 1] == 1){
                currSeq++;
            }
            else{
                currSeq = 1;
            }

            maxSeq = max(maxSeq, currSeq);
            i++;
        }
        
        return maxSeq;
    }
};
