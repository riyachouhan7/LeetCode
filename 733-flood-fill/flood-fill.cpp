class Solution {
public:
    void helper(int i, int j, vector<vector<int>> &image, int oldColor, int newColor, int n, int m)
    {
        if(i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor)
        {
            return;
        }
        image[i][j] = newColor;
        helper(i+1, j, image, oldColor, newColor, n, m);
        helper(i, j+1, image, oldColor, newColor, n, m);
        helper(i-1, j, image, oldColor, newColor, n, m);
        helper(i, j-1, image, oldColor, newColor, n, m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int x, int y, int newColor) 
    {
        int oldColor = image[x][y];
        if(oldColor == newColor)
        {
            return image;
        }
        int n = image.size();
        int m = image[0].size();
        helper(x, y, image, oldColor, newColor, n , m);
        return image;
    }
};