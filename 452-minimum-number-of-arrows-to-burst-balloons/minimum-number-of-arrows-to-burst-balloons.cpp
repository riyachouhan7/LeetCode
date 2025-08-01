class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        int count = 1;

        vector<int> prev = points[0];
        for(int i=1;i<n;i++){
            int currStartPoint = points[i][0];
            int currEndPoint = points[i][1];

            int prevStartPoint = prev[0];
            int prevEndPoint = prev[1];

            if(currStartPoint > prevEndPoint){ //no overlap
                count++;
                prev = points[i];
            }
            else {
                prev[0] = max(currStartPoint, prevStartPoint);
                prev[1] = min(currEndPoint, prevEndPoint);
            }
        }
        return count;
    }
};
