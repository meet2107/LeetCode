class Twitter {
public:
    int time;
    unordered_map<int,unordered_set<int>> follows;
    unordered_map<int,vector<pair<int,int>>> tweets;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(time,tweetId);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto i : tweets[userId]){
            pq.push(i);
        }
        for(auto i : follows[userId]){
            for(auto j : tweets[i]) pq.push(j);
        }

        vector<int> feed;
        int count = 10;
        while(!pq.empty() && count){
            feed.push_back(pq.top().second);
            pq.pop();
            count--;
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
