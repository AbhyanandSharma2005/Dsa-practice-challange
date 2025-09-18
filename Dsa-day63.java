import java.util.*;
class TaskManager {
    private Map<Integer,int[]> map;
    private PriorityQueue<int[]> pq;
    public TaskManager(List<List<Integer>> tasks){
        map=new HashMap<>();
        pq=new PriorityQueue<>((a,b)->a[0]==b[0]?b[1]-a[1]:b[0]-a[0]);
        for(List<Integer> x:tasks){
            map.put(x.get(1),new int[]{x.get(0),x.get(2)});
            pq.offer(new int[]{x.get(2),x.get(1)});
        }
    }
    public void add(int userId,int taskId,int priority){
        map.put(taskId,new int[]{userId,priority});
        pq.offer(new int[]{priority,taskId});
    }
    public void edit(int taskId,int newPriority){
        int u=map.get(taskId)[0];
        map.put(taskId,new int[]{u,newPriority});
        pq.offer(new int[]{newPriority,taskId});
    }
    public void rmv(int taskId){
        map.remove(taskId);
    }
    public int execTop(){
        while(!pq.isEmpty()){
            int[] cur=pq.poll();
            if(map.containsKey(cur[1])&&map.get(cur[1])[1]==cur[0]){
                int u=map.get(cur[1])[0];
                map.remove(cur[1]);
                return u;
            }
        }
        return -1;
    }
}
