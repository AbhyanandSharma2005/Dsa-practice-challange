import java.util.*;
class Solution {
    public int[] countMentions(int numberOfUsers, List<List<String>> events) {
        List<int[]> eventList = new ArrayList<>();
        for (int i = 0; i < events.size(); i++) {
            List<String> event = events.get(i);
            int timestamp = Integer.parseInt(event.get(1));
            int type = event.get(0).equals("OFFLINE") ? 0 : 1;
            eventList.add(new int[]{timestamp, type, i});
        }
                Collections.sort(eventList, (a, b) -> {
            if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
            if (a[1] != b[1]) return Integer.compare(a[1], b[1]);
            return Integer.compare(a[2], b[2]);
        });
                int[] mentions = new int[numberOfUsers];
        int[] offlineUntil = new int[numberOfUsers];
        
        for (int[] e : eventList) {
            int originalIndex = e[2];
            List<String> originalEvent = events.get(originalIndex);
            String eventType = originalEvent.get(0);
            int timestamp = e[0];
            
            if (eventType.equals("OFFLINE")) {
                int userId = Integer.parseInt(originalEvent.get(2));
                offlineUntil[userId] = timestamp + 60;
            } else {
                String mentionsStr = originalEvent.get(2);
                String[] tokens = mentionsStr.split("\\s+");
                for (String token : tokens) {
                    if (token.startsWith("id")) {
                        int userId = Integer.parseInt(token.substring(2));
                        mentions[userId]++;
                    } else if (token.equals("ALL")) {
                        for (int u = 0; u < numberOfUsers; u++) {
                            mentions[u]++;
                        }
                    } else if (token.equals("HERE")) {
                        for (int u = 0; u < numberOfUsers; u++) {
                            if (timestamp >= offlineUntil[u]) {
                                mentions[u]++;
                            }
                        }
                    }
                }
            }
        }
        
        return mentions;
    }
}