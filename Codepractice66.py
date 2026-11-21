from typing import List


class Solution:

  def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
    n = len(parent)
    children = [[] for _ in range(n)]
    for i in range(1, n):
      children[parent[i]].append(i)

    new_parent = parent[:]
    last_char = [-1] * 26

    def find_new_parents(u: int) -> None:
      c = ord(s[u]) - ord('a')
      prev = last_char[c]
      if u != 0 and prev != -1:
        new_parent[u] = prev

      last_char[c] = u
      for v in children[u]:
        find_new_parents(v)
      last_char[c] = prev

    find_new_parents(0)

    new_children = [[] for _ in range(n)]
    for i in range(1, n):
      new_children[new_parent[i]].append(i)

    ans = [0] * n

    def calc_sizes(u: int) -> int:
      size = 1
      for v in new_children[u]:
        size += calc_sizes(v)
      ans[u] = size
      return size

    calc_sizes(0)
    return ans
add