class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0;
        int product = 1;
        int zeroIndex = -1;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) {
                zero++;
                zeroIndex = i;
            }
            else product *= nums[i];
        }

        vector<int> ans(n, 0);
        if(zero > 1) return ans;

        if(zero == 1){
            ans[zeroIndex] = product;
            return ans;
        }

        for(int i = 0; i < n; i++){
            ans[i] = product / nums[i];
        } 

        return ans;
    }
};
