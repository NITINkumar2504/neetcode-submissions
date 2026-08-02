class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int sum = 0;
        for(auto &num: nums){
            sum = max(num, sum + num);
            maxi = max(sum, maxi);
        }

        return maxi;
    }
};
