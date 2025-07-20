from collections import defaultdict
from typing import List

class TrieNode:
    def __init__(self, name=""):
        self.name = name
        self.children = {}
        self.is_duplicate = False

class Solution:
    def deleteDuplicateFolder(self, paths: List[List[str]]) -> List[List[str]]:
        root = TrieNode()
        
        def insert(path):
            node = root
            for folder in path:
                if folder not in node.children:
                    node.children[folder] = TrieNode(folder)
                node = node.children[folder]
        
        for path in paths:
            insert(path)

        subtree_count = defaultdict(int)
        serialization_map = {}

        def serialize(node):
            if not node.children:
                return ""

            serials = []
            for child_name in sorted(node.children):
                child_node = node.children[child_name]
                child_serial = serialize(child_node)
                serials.append(f"({child_name}{child_serial})")

            serial = "".join(serials)
            subtree_count[serial] += 1

            if subtree_count[serial] == 2:
                serialization_map[serial].is_duplicate = True
                node.is_duplicate = True
            elif subtree_count[serial] > 2:
                node.is_duplicate = True
            else:
                serialization_map[serial] = node

            return serial

        serialize(root)

        result = []

        def collect(node, path):
            for child_name, child in node.children.items():
                if not child.is_duplicate:
                    path.append(child_name)
                    result.append(path[:])
                    collect(child, path)
                    path.pop()

        collect(root, [])

        return result
