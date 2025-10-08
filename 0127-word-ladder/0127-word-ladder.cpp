#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool singleDiff(string word1, string word2) {
        int count = 0;
        for (int i = 0; i < word1.length(); i++) {
            if (word1[i] != word2[i]) {
                count++;
            }
            if (count > 1) return false;
        }
        return count == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        wordList.push_back(beginWord);
        int n = wordList.size();

       
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (singleDiff(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (wordList[i] == beginWord) start = i;
            if (wordList[i] == endWord) end = i;
        }

      
        queue<pair<int, int>> q; // {index, level}
        vector<int> visited(n, 0);
        q.push({start, 1});
        visited[start] = 1;

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            if (node == end) return level;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, level + 1});
                }
            }
        }

        return 0; 
    }
};
