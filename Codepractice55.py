import heapq
from bisect import bisect_left
import bisect

class Solution:
    def busiestServers(self, k: int, arrival: list[int], load: list[int]) -> list[int]:
        busy = []  # min-heap of (end_time, server_id)
        available = list(range(k))  # sorted list of available server IDs
        count = [0] * k
        
        # We can use an ordered collection or sorted list for available servers,
        # or maintain a sorted list with bisect.
        from sortedcontainers import SortedList
        avail = SortedList(range(k))
        
        for i, (arr_time, req_load) in enumerate(zip(arrival, load)):
            # Free up servers that finished before or at arr_time
            while busy and busy[0][0] <= arr_time:
                _, freed_server = heapq.heappop(busy)
                avail.add(freed_server)
            
            if not avail:
                continue  # All servers busy, drop the request
            
            target = i % k
            idx = avail.bisect_left(target)
            if idx == len(avail):
                idx = 0  # wrap around to the smallest available server ID
            
            server = avail.pop(idx)
            count[server] += 1
            heapq.heappush(busy, (arr_time + req_load, server))
        
        max_requests = max(count) if count else 0
        return [s for s, c in enumerate(count) if c == max_requests]
