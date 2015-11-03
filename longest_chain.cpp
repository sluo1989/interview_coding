int dfs(const string& s, unordered_map<string, int>& hash_map) {
    if (hash_map[s] > 0) return hash_map[s];
    hash_map[s] = 1;
    for (int i = 0; i < s.length(); ++i) {
        string tmp = s;
        tmp.erase(i, 1);
        if (hash_map.count(tmp))
            hash_map[s] = max(hash_map[s], 1 + dfs(tmp, hash_map));
    }
    return hash_map[s];
}

int longest_chain(vector<string> w) {
    unordered_map<string, int> hash_map;
    for (string s : w) hash_map[s] = 0;
    int ret = 0;
    for (string s : w)
        ret = max(ret, dfs(s, hash_map));
    return ret;
}