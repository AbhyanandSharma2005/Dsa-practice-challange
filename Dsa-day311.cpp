class Solution {
public:

    struct Trie{
        Trie* next[26];
        int index;
        int len;

        Trie(){
            fill(next,next+26,nullptr);
            index = 0;
            len = INT_MAX;
        }
    };

    vector<Trie> pool;
    int poolIdx = 0;

    Trie* newNode(){
        return &pool[poolIdx++];
    }

    void insert(Trie* root,string &s,int idx){

        int n = s.length();

        if(root->len > n){
            root->len = n;
            root->index = idx;
        }

        for(int i=n-1;i>=0;i--){

            int c = s[i]-'a';

            if(!root->next[c]){
                root->next[c] = newNode();
            }

            root = root->next[c];

            if(root->len > n){
                root->len = n;
                root->index = idx;
            }
        }
    }

    int find(Trie* root,string &s){

        int ans = root->index;

        for(int i=s.length()-1;i>=0;i--){

            int c = s[i]-'a';

            if(!root->next[c]) break;

            root = root->next[c];
            ans = root->index;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        int maxNodes = 1;

        for(auto &i : wordsContainer){
            maxNodes += i.length();
        }

        pool.resize(maxNodes);

        Trie* root = newNode();

        for(int i=0;i<wordsContainer.size();i++){
            insert(root,wordsContainer[i],i);
        }

        vector<int> ans;

        for(auto &i : wordsQuery){
            ans.push_back(find(root,i));
        }

        return ans;
    }
};