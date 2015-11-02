/*
从stdin读入一行String，String中同时包括单词和数字，以空格分开。需要将输入进行排序，要求：（1）字母和数字分别顺序排序（2）输入中原本是字母/数字的地方依然是字母/数字。

比如输入：d 3 c 2 1 a 输出为 a 1 c 2 3 d 

        输入：add 6 abb at 输出为 abb 6 add at


思路：

由于单词元素和数字元素是以空格分开的，可以将输入的String解析成单个输入元素的list。然后一一判断这些元素是不是数字，如果是的话，标记所在位置，并将该元素加到一个新的叫integers的list中，再将单词加到另一个叫words的list中。分别对这两个list排序后根据之前标记的位置把排序好的值重新填回去。
*/



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
