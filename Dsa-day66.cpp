#include <bits/stdc++.h>
using namespace std;
class MovieRentingSystem {
    unordered_map<int, set<pair<int,int>>> movieMap;
    set<tuple<int,int,int>> rented;
    unordered_map<long long,int> priceMap;
    long long key(int shop,int movie){ return ((long long)shop<<32) | (unsigned long long)movie; }
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &e: entries){
            int shop=e[0], movie=e[1], price=e[2];
            movieMap[movie].insert({price,shop});
            priceMap[key(shop,movie)] = price;
        }
    }
    vector<int> search(int movie) {
        vector<int> res;
        auto it = movieMap.find(movie);
        if(it==movieMap.end()) return res;
        int cnt=0;
        for(auto &p: it->second){
            res.push_back(p.second);
            if(++cnt==5) break;
        }
        return res;
    }
    void rent(int shop, int movie) {
        int price = priceMap[key(shop,movie)];
        movieMap[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }
    void drop(int shop, int movie) {
        int price = priceMap[key(shop,movie)];
        movieMap[movie].insert({price,shop});
        rented.erase({price,shop,movie});
    }
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt=0;
        for(auto &t: rented){
            if(cnt==5) break;
            int price,getshop,getmovie;
            tie(price,getshop,getmovie) = t;
            res.push_back({getshop,getmovie});
            ++cnt;
        }
        return res;
    }
};
