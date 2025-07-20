class Solution {
    
    static class TrieNode {
        Map<String, TrieNode> children = new HashMap<>();
        String name;
        boolean isDuplicate = false;

        TrieNode(String name) {
            this.name = name;
        }
    }

    Map<String, Integer> subtreeCount = new HashMap<>();
    Map<String, TrieNode> serializationMap = new HashMap<>();

    private void insert(TrieNode root, List<String> path) {
        TrieNode node = root;
        for (String folder : path) {
            node.children.putIfAbsent(folder, new TrieNode(folder));
            node = node.children.get(folder);
        }
    }

    private String serialize(TrieNode node) {
        if (node.children.isEmpty()) return "";

        List<String> serialList = new ArrayList<>();
        for (Map.Entry<String, TrieNode> entry : node.children.entrySet()) {
            String childSerial = serialize(entry.getValue());
            serialList.add("(" + entry.getKey() + childSerial + ")");
        }

        Collections.sort(serialList);  
        String serial = String.join("", serialList);

        subtreeCount.put(serial, subtreeCount.getOrDefault(serial, 0) + 1);
        if (subtreeCount.get(serial) == 2) {
            serializationMap.get(serial).isDuplicate = true;
            node.isDuplicate = true;
        } else if (subtreeCount.get(serial) > 2) {
            node.isDuplicate = true;
        } else {
            serializationMap.put(serial, node);
        }

        return serial;
    }

    private void collect(TrieNode node, List<String> path, List<List<String>> result) {
        for (Map.Entry<String, TrieNode> entry : node.children.entrySet()) {
            TrieNode child = entry.getValue();
            if (!child.isDuplicate) {
                path.add(entry.getKey());
                result.add(new ArrayList<>(path));
                collect(child, path, result);
                path.remove(path.size() - 1);
            }
        }
    }

    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        TrieNode root = new TrieNode("");
        for (List<String> path : paths) {
            insert(root, path);
        }

        serialize(root);

        List<List<String>> result = new ArrayList<>();
        collect(root, new ArrayList<>(), result);

        return result;
    }
}
