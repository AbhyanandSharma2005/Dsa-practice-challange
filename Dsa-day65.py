from collections import deque, defaultdict
import bisect

class Router:
    def __init__(self, memoryLimit: int):
        self.limit = memoryLimit
        self.q = deque()
        self.seen = set()
        self.dest_map = defaultdict(list)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        key = (source, destination, timestamp)
        if key in self.seen:
            return False
        if len(self.q) == self.limit:
            s, d, t = self.q.popleft()
            self.seen.remove((s, d, t))
            arr = self.dest_map[d]
            idx = bisect.bisect_left(arr, t)
            arr.pop(idx)
        self.q.append((source, destination, timestamp))
        self.seen.add(key)
        bisect.insort(self.dest_map[destination], timestamp)
        return True

    def forwardPacket(self) -> list:
        if not self.q:
            return []
        s, d, t = self.q.popleft()
        self.seen.remove((s, d, t))
        arr = self.dest_map[d]
        idx = bisect.bisect_left(arr, t)
        arr.pop(idx)
        return [s, d, t]

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        arr = self.dest_map[destination]
        l = bisect.bisect_left(arr, startTime)
        r = bisect.bisect_right(arr, endTime)
        return r - l
