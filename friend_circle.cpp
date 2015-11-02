//
//  main.cpp
//  friend_circle
//
//  Created by Shikai Luo on 10/27/15.
//  Copyright © 2015 Shikai Luo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<string> & friends) {
    vector<bool> visited(friends.size(), false);
    queue<int> que;
    que.push(0);
    visited[0] = true;
    int circles = 0;
    
    while (!que.empty()) {
        int node = que.front();
        que.pop();
        string cur_node_friends = friends[node];
        for (int i = 0; i < cur_node_friends.size(); i++) {
            if (cur_node_friends[i] == 'y' && node != i && visited[i] == false) {
                que.push(i);
                visited[i] = true;
            }
        }
        
        if (que.empty()) {
            circles++;
            for (int i = 1; i < friends.size(); i++) {
                if (visited[i] == false) {
                    que.push(i);
                    visited[i] = true;
                    break;
                }
            }
            
        }
    }
    
    return circles;
}

int main(int argc, const char * argv[]) {
    vector<string> friends;
    friends.push_back("yynn");
    friends.push_back("yynn");
    friends.push_back("nnyy");
    friends.push_back("nnyy");
    int cc = bfs(friends);
    cout << cc << endl;
    return 0;
}
