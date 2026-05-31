class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> depend(numCourses,vector<int>(numCourses,0));
        unordered_map<int,int> freq;

        for(int i=0; i<prerequisites.size(); i++){
            depend[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }
        vector<int> keyRow;
        for(int i=0; i<numCourses; i++){
            int f = 0;
            for(int j=0; j<numCourses; j++){
                if(depend[i][j] == 1)f++;
            }
            if(f == 0)keyRow.push_back(i);
            freq[i] = f;
        }

       for(int i=0; i<keyRow.size(); i++){
        int m = keyRow[i];
        for(int j=0; j<depend.size(); j++){
            if(depend[j][m] == 1){
                depend[j][m] = 0;
                if(freq[j] == 1)keyRow.push_back(j);
                freq[j]--;
            }
        }
       }

       for(int i=0; i<depend.size(); i++){
        if(freq[i] > 0)return false;
       }
     return true;
    }
};