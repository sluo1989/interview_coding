//
//  main.cpp
//  longest_chain
//
//  Created by Shikai Luo on 11/1/15.
//  Copyright © 2015 Shikai Luo. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<string, int> hash_map;

int _longest_chain(unordered_set<string>& vstr, string start) {
    
    if (hash_map.find(start) != hash_map.end()) return hash_map[start];
    
    auto state_extend = [&](const string& str) {
        vector<string> result;
        for (size_t i = 0; i != str.size(); i++) {
            string new_str(str);
            new_str.erase(i, 1);
            if (vstr.count(new_str) > 0)
                result.push_back(new_str);
        }
        return result;
    };
    
    queue<string> current, next;
    int level = 0, max_len = 0;
    
    current.push(start);
    while (!current.empty()) {
        ++level;
        while (!current.empty()) {
            const string str = current.front();
            current.pop();
            
            const auto& new_states = state_extend(str);
            if (new_states.size() != 0) {
                for (const auto& state : new_states) {
                    if (hash_map.find(state) != hash_map.end()) max_len = level + hash_map[state];
                    else next.push(state);
                }
            }
        }
        if (next.empty()) {
            hash_map[start] = max(level, max_len);
            return max(level, max_len);
            break;
        }
        swap(next, current);
    }
    
    return max(level, max_len);
}

int longest_chain(unordered_set<string>& vstr) {
    int maximum_length = 0;
    for (const auto& str : vstr) {
        maximum_length = max(maximum_length, _longest_chain(vstr, str));
    }
    return maximum_length;
}

int main(int argc, const char * argv[]) {
    unordered_set<string> vstr{"a","abcde","bcde","abd","cde","de","e"};
    int res = longest_chain(vstr);
    cout << res << "\n";
    return 0;
}
