import heapq

class Solution:
    def mostBooked(self, n: int, meetings: list[list[int]]) -> int:
        meetings.sort()
        
        free_rooms = list(range(n))
        heapq.heapify(free_rooms)

        busy_rooms = []

        count = [0] * n

        for start, end in meetings:
            while busy_rooms and busy_rooms[0][0] <= start:
                _, room = heapq.heappop(busy_rooms)
                heapq.heappush(free_rooms, room)

            if free_rooms:
                room = heapq.heappop(free_rooms)
                count[room] += 1
                heapq.heappush(busy_rooms, (end, room))
            else:
                end_time, room = heapq.heappop(busy_rooms)
                duration = end - start
                new_end = end_time + duration
                count[room] += 1
                heapq.heappush(busy_rooms, (new_end, room))

        max_meetings = max(count)
        for i in range(n):
            if count[i] == max_meetings:
                return i