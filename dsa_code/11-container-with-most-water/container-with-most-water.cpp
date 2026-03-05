class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int area=0;
        while (i<j){
            int temp_area=min(height[i],height[j])*abs(j-i);
            if (temp_area>area){
                area=temp_area;
            }
            if (height[i]<height[j]){
                i++;
            }
            else {
                j--;
            }
        }
        return area;
    }
};