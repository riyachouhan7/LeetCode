class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> Q;
        int n = prerequisites.size();
        vector<vector<int>> adjList(numCourses);

        for(auto it : prerequisites){
            adjList[it[1]].push_back(it[0]);
        }

        vector<int>inDegree(numCourses);

        for(int i = 0;i<numCourses;i++){
            for(auto it : adjList[i]){
                inDegree[it]++;
            }
        }

        for(int i = 0;i<numCourses;i++){
            if(inDegree[i] == 0){
                Q.push(i);
            }
        }

        vector<int>res;
        while(!Q.empty()){
            int front = Q.front();
            Q.pop();
            res.push_back(front);

            for(auto it : adjList[front]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    Q.push(it);
                }
            }
        }
        if(res.size() == numCourses){
            return res;
        }

        return {};
    }
};