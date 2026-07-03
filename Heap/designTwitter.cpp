/* Design Twitter
Create a simplified version of a social media platform similar to Twitter. Users should be able to post tweets, follow or unfollow other users, and view the 10 most recent tweets in their news feed.

Implement the Twitter class as follows:
Twitter(): Initializes the Twitter object.
void postTweet(int userId, int tweetId): Composes a new tweet with ID tweetId by the user userId. All tweetIds will be unique.
List<Integer> getNewsFeed(int userId): Retrieves the 10 most recent tweet IDs in the user's news feed. The news feed should only show posts from users the user follows or from the user themself, with tweets arranged from most recent to least recent.
void follow(int followerId, int followeeId): The user with ID followerId started following the user with ID followeeId. Input will be given such that followerId is not already following followeeId at the time of function call.
void unfollow(int followerId, int followeeId): The user with ID followerId unfollowed the user with ID followeeId. Input will be given such that followerId is following followeeId at the time of function call.

Examples
Input: [postTweet(1, 2), postTweet(2, 6), getNewsFeed(1), follow(1, 2), getNewsFeed(1), unfollow(1, 2), postTweet(1,7), getNewsFeed(1)]
Output: [null, null, [2], null, [6, 2], null, [7, 2]]
Explanation:postTweet(1, 2): User with userId 1 posts tweet with tweetId 2.
postTweet(2, 6): User with userId 2 posts tweet with tweetId 6.
getNewsFeed(1): Outputs feed of userId 1 = [2].
follow(1, 2): User with userId 1 follows user with userId 2.
getNewsFeed(1): Outputs feed of userId 1 = [6, 2], it contains the news of userId 2 as well.
unfollow(1, 2): User with userId 1 unfollows user with userId 2.
postTweet(1,7): User with userId 1 posts tweet with tweetId 7.
getNewsFeed(1): Outputs feed of userId 1 = [7, 2].

Input: [follow(2, 1), follow(1, 2), postTweet(1, 6), getNewsFeed(1), getNewsFeed(2), unfollow(2, 1), getNewsFeed(2)]
Output:  [null, null, null, [6], [6], null, []]
Explanation:follow(2, 1): User with userId 2 follows user with userId 1.
follow(1, 2): User with userId 1 follows user with userId 2.
postTweet(1, 6): User with userId 1 posts tweet with tweetId 6.
getNewsFeed(1): Outputs feed of userId 1 = [6].
getNewsFeed(2): Outputs feed of userId 2 = [6]. This includes tweets of userId 1 as well.
unfollow(2, 1): User with userId 2 unfollows user with userId 1.
getNewsFeed(2): Outputs feed of userId 2 = [], its empty as userId 2 no longer follows userId 1
*/

#include <bits/stdc++.h>

using namespace std;

class Twitter {
private:
  unordered_map<int, vector<pair<int, int>>> tweets;
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (auto& t : tweets[userId]) {
      pq.push(t);
      if (pq.size() > 10)
        pq.pop();
    }
    for (int followee : following[userId]) {
      for (auto& t : tweets[followee]) {
        pq.push(t);
        if (pq.size() > 10)
          pq.pop();
      }
    }
    vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
  void follow(int followerId, int followeeId) {
    following[followerId].insert(followeeId);
  }
  void unfollow(int followerId, int followeeId) {
    following[followerId].erase(followeeId);
  }
};

int main() {
  Twitter twitter;
  twitter.postTweet(1, 2);
  twitter.postTweet(2, 6);
  vector<int> res1 = twitter.getNewsFeed(1);
  for (int i : res1) cout << i << " ";
  cout << endl;
  twitter.follow(1, 2);
  vector<int> res2 = twitter.getNewsFeed(1);
  for (int i : res2) cout << i << " ";
  cout << endl;
  twitter.unfollow(1, 2);
  twitter.postTweet(1, 7);
  vector<int> res3 = twitter.getNewsFeed(1);
  for (int i : res3) cout << i << " ";
  cout << endl;
  return 0;
}