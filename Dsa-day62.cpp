#define pis pair<int,string>

class compare{
    public:
    bool operator()(pis a, pis b){
        if(a.first < b.first) return true;
        if(a.first == b.first){
            if(a.second.compare(b.second) > 0) return true;
        }
        return false;
    }
};

class FoodRatings {
public:

    unordered_map<string, priority_queue<pis, vector<pis>, compare>> cuis;
    unordered_map<string,pis> rating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();

        for(int i=0; i<n; i++){
            cuis[cuisines[i]].push({ratings[i],foods[i]});
            rating[foods[i]] = {ratings[i], cuisines[i]};
        }

    }
    
    void changeRating(string food, int newRating) {
        pis temp = rating[food];
        cuis[temp.second].push({newRating,food});
        rating[food] = {newRating, temp.second};
    }
    
    string highestRated(string cuisine) {
        pis top = cuis[cuisine].top();
        
        while(top.first != rating[top.second].first){
            cuis[cuisine].pop();
            top = cuis[cuisine].top();
        }

        return top.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */