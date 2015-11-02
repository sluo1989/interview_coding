//
//  main.cpp
//  mix_sort
//
//  Created by Shikai Luo on 11/1/15.
//  Copyright © 2015 Shikai Luo. All rights reserved.
//

#include <iostream>
#include <vector> 
#include <string>
#include <regex>
#include <sstream>

using namespace std;

bool is_integer(string x){
    regex e ("^-?\\d+");
    if (regex_match(x,e)) return true;
    else return false;
}

vector<string> mix_sort(string& str){
    istringstream iss(str);
    istream_iterator<string> beg(iss), end;
    vector<string> tokens(beg, end);
    vector<bool> indicators;
    vector<int> integers;
    vector<string> words;
    for (int i=0; i!=tokens.size(); i++) {
        if (is_integer(tokens[i])) {
            integers.push_back(stoi(tokens[i]));
            indicators.push_back(true);
        }
        else {
            words.push_back(tokens[i]);
            indicators.push_back(false);
        }
    }
    sort(integers.begin(), integers.end());
    sort(words.begin(), words.end());
    int indx_int=0, indx_str=0;
    for (int i=0; i!=tokens.size(); i++) {
        if (indicators[i]) tokens[i] = to_string(integers[indx_int++]);
        else tokens[i] = words[indx_str++];
    }
    return tokens;
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<string> tokens = mix_sort(str);
    for (int i=0; i!=tokens.size(); i++)
        cout << tokens[i] << " ";
    return 0;
}
