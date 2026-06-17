class Twitter {
private:
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<
            pair<int, pair<int,int>>
        > maxHeap;

        // Ensure user follows themselves
        following[userId].insert(userId);

        // Push most recent tweet of each followee
        for(int user : following[userId]) {
            if(!tweets[user].empty()) {
                int index = tweets[user].size() - 1;
                maxHeap.push({tweets[user][index].first, {user, index}});
            }
        }

        vector<int> res;

        while(!maxHeap.empty() && res.size() < 10) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int user = top.second.first;
            int index = top.second.second;

            res.push_back(tweets[user][index].second);

            if(index > 0) {
                maxHeap.push({tweets[user][index-1].first, {user, index-1}});
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
