class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto& pre: prerequisites) {
            int a=pre[0],b=pre[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            count++;

            for(int nei:adj[node]) {
                indegree[nei]--;
               if(indegree[nei]==0) {
                q.push(nei);
               }
            }
        }
        return count == numCourses;
    }
};