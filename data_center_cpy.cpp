/*输入：第一行是一个0-999999之间的整数，代表数据中心（data center）的数量。接着的每一行分别是一个数据中心，每一行最先是一个0-299的整数代表该数据中心的数据组（data sets）. 然后就是以空格分开的数据。数据都是1-999999之间的整数。每一行最多999个字符长。

输出：

要求输出分布式备份的步骤，将数据在数据中心间互相拷贝，最后使得所有数据中心都有所有的数据。
打印出的步骤的格式是： <data-set-id> <from> <to>

 <data-set-id> 就是所要拷贝的数据， <from> 是该数据所在数据中心的索引， <to>是即将拷贝过去的数据中心的索引

当步骤结束后，打印“done”。

能实现分布式备份的步骤往往不是唯一的，打印出任何正确地步骤均可。
*/ 

#include <iostream>
#include <unordered_map>
#include <vector>

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
                cout << x.first << " " << x.second[0] << " " << l+1 << "\n";
        }
    }
    cout << "done" << "\n";

    return 0;
}
