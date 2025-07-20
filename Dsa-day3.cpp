class TrieNode {
public:
    unordered_map<string, TrieNode*> children;
    string name; 
    bool isDuplicate = false;  

    TrieNode(string name = "") : name(name) {}
};

class Solution {
public:
    unordered_map<string, int> subtreeCount;
    unordered_map<string, TrieNode*> subtreeMap;

    void insert(TrieNode* root, vector<string>& path) {
        TrieNode* node = root;
        for (const string& folder : path) {
            if (!node->children.count(folder)) {
                node->children[folder] = new TrieNode(folder);
            }
            node = node->children[folder];
        }
    }

    string serialize(TrieNode* node) {
        if (node->children.empty()) return "";

        vector<string> subs;
        for (auto& [name, child] : node->children) {
            string subSerial = serialize(child);
            subs.push_back("(" + name + subSerial + ")");
        }

        sort(subs.begin(), subs.end());  
        string serial = accumulate(subs.begin(), subs.end(), string(""));

        subtreeCount[serial]++;
        if (subtreeCount[serial] == 2) {
            subtreeMap[serial]->isDuplicate = true;
            node->isDuplicate = true;
        } else if (subtreeCount[serial] > 2) {
            node->isDuplicate = true;
        } else {
            subtreeMap[serial] = node;
        }

        return serial;
    }

    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& result) {
        for (auto& [name, child] : node->children) {
            if (!child->isDuplicate) {
                path.push_back(name);
                result.push_back(path);
                collect(child, path, result);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for (auto& path : paths)
            insert(root, path);

        serialize(root);

        vector<vector<string>> result;
        vector<string> path;
        collect(root, path, result);

        return result;
    }
};
