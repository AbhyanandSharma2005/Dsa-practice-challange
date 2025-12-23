class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        mx, mxlast, curhappening = 0, 0, []
        events.sort()

        for curstart, curend, val in events:
            while curhappening and curhappening[0][0] < curstart:
                lastend, lastval = heapq.heappop(curhappening)
                mxlast = max(mxlast, lastval)
            mx = max(mx, val + mxlast)
            heapq.heappush(curhappening, (curend, val))
        return mx

        