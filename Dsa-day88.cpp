class Solution {
private:
    std::string getSorted(const std::string& s) {
        std::string sorted_s = s;
        std::sort(sorted_s.begin(), sorted_s.end());
        return sorted_s;
    }
    
public:
    std::vector<std::string> removeAnagrams(std::vector<std::string>& words) {
        std::vector<std::string> result;
        std::string prev_sorted_word = "";
        
        for (const std::string& word : words) {
            std::string current_sorted_word = getSorted(word);
            
            if (current_sorted_word != prev_sorted_word) {
                result.push_back(word);
                prev_sorted_word = current_sorted_word;
            }
        }
        
        return result;
    }
};