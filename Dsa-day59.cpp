class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string,string> cap;
        unordered_map<string,string> vow;
        auto devowel = [](string s) {
            for (auto &c : s) if (string("aeiou").find(c)!=string::npos) c='*';
            return s;
        };
        for (auto &w : wordlist) {
            string lw=w;
            for (auto &c:lw) c=tolower(c);
            if (!cap.count(lw)) cap[lw]=w;
            string vw=devowel(lw);
            if (!vow.count(vw)) vow[vw]=w;
        }
        vector<string> res;
        for (auto &q : queries) {
            if (exact.count(q)) {res.push_back(q); continue;}
            string lq=q;
            for (auto &c:lq) c=tolower(c);
            if (cap.count(lq)) {res.push_back(cap[lq]); continue;}
            string vq=devowel(lq);
            if (vow.count(vq)) res.push_back(vow[vq]);
            else res.push_back("");
        }
        return res;
    }
};
