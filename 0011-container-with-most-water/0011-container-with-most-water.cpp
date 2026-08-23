class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int w = 0, area;
        while (i < j) {
            area = (j - i) * (min(height[j], height[i]));
            w = max(area, w);
            if (height[i] >= height[j])
                j--;
            else
                i++;
        } return w;
    }
};