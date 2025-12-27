#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i)
            freeRooms.push(i);

        using pii = pair<long long, int>;  
        priority_queue<pii, vector<pii>, greater<pii>> busyRooms;

        vector<int> meetingCount(n, 0);

        for (auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top();
                freeRooms.pop();
                meetingCount[room]++;
                busyRooms.push({end, room});
            } else {
                auto [availableTime, room] = busyRooms.top();
                busyRooms.pop();
                long long duration = end - start;
                long long newEnd = availableTime + duration;
                meetingCount[room]++;
                busyRooms.push({newEnd, room});
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};
