#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <sstream>
using namespace std;
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<tuple<int, int, int>> eventInfos;
        for (int i = 0; i < events.size(); ++i) {
            int timestamp = stoi(events[i][1]);
            int type = (events[i][0] == "OFFLINE") ? 0 : 1;
            eventInfos.emplace_back(timestamp, type, i);
        }
        sort(eventInfos.begin(), eventInfos.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
            return get<2>(a) < get<2>(b);
        });

        vector<int> mentions(numberOfUsers, 0);
        vector<int> offline_until(numberOfUsers, 0);

        for (auto& eventInfo : eventInfos) {
            int originalIndex = get<2>(eventInfo);
            vector<string>& event = events[originalIndex];
            string type = event[0];
            int timestamp = stoi(event[1]);

            if (type == "OFFLINE") {
                int user = stoi(event[2]);
                offline_until[user] = timestamp + 60;
            } else {
                string mentions_str = event[2];
                istringstream iss(mentions_str);
                string token;
                while (iss >> token) {
                    if (token.substr(0, 2) == "id") {
                        int user = stoi(token.substr(2));
                        mentions[user]++;
                    } else if (token == "ALL") {
                        for (int u = 0; u < numberOfUsers; ++u) {
                            mentions[u]++;
                        }
                    } else if (token == "HERE") {
                        for (int u = 0; u < numberOfUsers; ++u) {
                            if (timestamp >= offline_until[u]) {
                                mentions[u]++;
                            }
                        }
                    }
                }
            }
        }

        return mentions;
    }
};