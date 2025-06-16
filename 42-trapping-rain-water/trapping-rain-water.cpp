class Solution {
public:
    int trap(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int water = 0;

        while (left < right) {
            if (arr[left] < arr[right]) 
            {
                if (arr[left] >= leftMax)
                    leftMax = arr[left];
                else
                    water += leftMax - arr[left];
                left++;
            } 
            else 
            {
                if (arr[right] >= rightMax)
                    rightMax = arr[right];
                else
                    water += rightMax - arr[right];
                right--;
            }
        }

        return water;
    }
};
