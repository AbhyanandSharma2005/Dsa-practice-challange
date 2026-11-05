class Solution:

  def removeDuplicateLetters(self, s: str) -> str:
    # Step 1: Record the last occurrence index of each character
    last_occurrence = {char: i for i, char in enumerate(s)}

    stack = []
    visited = set()

    for i, char in enumerate(s):
      # If the character is already in the stack/result, skip it
      if char in visited:
        continue

      # While stack is not empty, the top is lexicographically larger than char,
      # and the top character appears later in the string (we can add it back later)
      while (
          stack
          and stack[-1] > char
          and last_occurrence[stack[-1]] > i
      ):
        removed_char = stack.pop()
        visited.remove(removed_char)

      stack.append(char)
      visited.add(char)

    return "".join(stack)
