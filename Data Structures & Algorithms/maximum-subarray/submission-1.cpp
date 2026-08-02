class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int sum = 0;
        for(auto &num: nums){
            if(sum < 0) sum = 0;
            sum += num;
            maxi = max(sum, maxi);
        }

        return maxi;
    }
};
