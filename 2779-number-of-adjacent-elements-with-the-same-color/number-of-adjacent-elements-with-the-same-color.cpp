class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int count = 0;
        vector<int> color(n,0);
        vector<int> result;

        for(int i=0;i<queries.size();i++)
        {
            int index = queries[i][0], indColor = queries[i][1];

            int left = index - 1 < 0 ? 0 : color[index - 1];
            int right = index + 1 == n ? 0 : color[index + 1];

            if(color[index] != 0 && left == color[index]) count--;
            if(color[index] != 0 && right == color[index]) count--;

            color[index] = indColor;

            if(left == color[index]) count++;
            if(right == color[index]) count++;

            result.push_back(count);
        }
        return result;
    }
};