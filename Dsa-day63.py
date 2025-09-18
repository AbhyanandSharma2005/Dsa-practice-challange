import heapq

class TaskManager:
    def __init__(self, tasks):
        self.taskMap = {}
        self.heap = []
        for u,t,p in tasks:
            self.taskMap[t] = (u,p)
            heapq.heappush(self.heap, (-p,-t,t))
    def add(self, userId, taskId, priority):
        self.taskMap[taskId] = (userId,priority)
        heapq.heappush(self.heap, (-priority,-taskId,taskId))
    def edit(self, taskId, newPriority):
        u,_ = self.taskMap[taskId]
        self.taskMap[taskId] = (u,newPriority)
        heapq.heappush(self.heap, (-newPriority,-taskId,taskId))
    def rmv(self, taskId):
        if taskId in self.taskMap:
            del self.taskMap[taskId]
    def execTop(self):
        while self.heap:
            p,negT,t = heapq.heappop(self.heap)
            if t in self.taskMap and self.taskMap[t][1]==-p:
                u,_=self.taskMap.pop(t)
                return u
        return -1
