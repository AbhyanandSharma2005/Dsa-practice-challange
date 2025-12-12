class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        sorted_events = sorted(events, key=lambda x: (int(x[1]), x[0] != "OFFLINE"))
        offline_queue = deque()
        offline_set = set()
        rv = []
        for i in range(numberOfUsers):
            rv.append(0)
        for i, event in enumerate(sorted_events):
            event_type, timestamp, ids = event
            while len(offline_queue) > 0:
                if int(timestamp) < offline_queue[0][0] + 60:
                    break
                removed_element = offline_queue.popleft()
                offline_set.remove(removed_element[1])
            if event_type == "MESSAGE":
                for id_string in ids.split(' '):
                    if id_string == "HERE":
                        for i in range(numberOfUsers):
                            if i in offline_set:
                                continue
                            rv[i] += 1
                        continue
                    elif id_string == "ALL":
                        for i in range(numberOfUsers):
                            rv[i] += 1
                        continue
                    number = int(id_string[2:len(id_string)])
                    #if number in offline_set:
                    #    continue
                    rv[number] += 1
            elif event_type == "OFFLINE":
                offline_queue.append((int(timestamp), int(ids)))
                offline_set.add(int(ids))
            

            

        return rv

