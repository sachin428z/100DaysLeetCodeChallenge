class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
       int n=patience.size();
       vector<vector<int>> graph(n);
       vector<int> time(n,-1);

       for(auto x:edges) {
        graph[x[0]].push_back(x[1]);
        graph[x[1]].push_back(x[0]);
       } 
       queue<int> q;
       q.push(0);
       time[0]=0;
       while(q.size()) {
        int node=q.front();
        q.pop();

        for(auto child: graph[node]) {
            if(time[child]==-1) {
                time[child]=time[node]+1;
                q.push(child);
            }
        }
       }
       int res=0;
       for(int i=1;i<n;i++) {
        int extraPayload=(time[i]*2-1)/patience[i];
        int lastOut=extraPayload*patience[i];
        int lastIn=lastOut+time[i]*2;

        res=max(res,lastIn);
       }
       return res+1;
    }
};