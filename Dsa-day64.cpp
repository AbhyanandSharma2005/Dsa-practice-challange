class Spreadsheet {
public:
    unordered_map<string,int> cells;
    Spreadsheet(int rows) {}
    void setCell(string cell, int value) {
        cells[cell]=value;
    }
    void resetCell(string cell) {
        cells.erase(cell);
    }
    int getValue(string formula) {
        auto get_val=[&](string s){
            if(isalpha(s[0])) return cells.count(s)?cells[s]:0;
            return stoi(s);
        };
        string s=formula.substr(1);
        int plus=s.find('+');
        string a=s.substr(0,plus),b=s.substr(plus+1);
        return get_val(a)+get_val(b);
    }
};
