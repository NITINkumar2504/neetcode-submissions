class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0;
        int j = n - 1;
        int maxArea = 0;

        while(i < j){
            int minH = min(heights[i], heights[j]);
            int width = j - i;

            maxArea = max(maxArea, minH * width);
            
            if(heights[i] <= heights[j]) i++;
            else j--;
        }

        return maxArea;
    }
};
