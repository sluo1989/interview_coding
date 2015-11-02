//
//  main.cpp
//  data_center_cpy
//
//  Created by Shikai Luo on 11/1/15.
//  Copyright © 2015 Shikai Luo. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;



int main(int argc, const char * argv[]) {
    unordered_map<int, vector<int>> hash_map;
    int data_center_number;
    cin >> data_center_number;
    for (int i=0; i!=data_center_number; i++) {
        int num, k;
        cin >> num;
        for (int j=0; j!=num; j++) {
            cin >> k;
            if (hash_map.find(k) != hash_map.end()) hash_map[k].push_back(i+1);
            else hash_map.emplace(k, vector<int>(1,i+1));
        }
    }
    for (auto& x : hash_map) {
        for (int l=0; l!=data_center_number; l++){
            if (find(x.second.begin(),x.second.end(),l+1)==x.second.end())
                cout << x.first << " " << x.second[0] << " " << l+1 << endl;
        }
    }
    return 0;
}
