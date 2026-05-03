class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        if(s.size() != goal.size()){
            // if the length is not equal, then the string is not rotated
            return false;
        }
        for(int i{0};i<(int)goal.size();i++){
            if(s[0] == goal[i]){
                bool isEqual{true};
                for(int j{0}, k = i;j<(int)s.size();j++){
                    if(k >= (int)goal.size()){
                        k = 0;
                    }
                    if(s[j] != goal[k]){
                        isEqual = false;
                        break;
                    }
                    k++;
                }
                if(isEqual){
                    return true;
                }
            }
        }
        return false;
    }
};