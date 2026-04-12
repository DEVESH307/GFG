#User function Template for python3
class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False
        self.freq = 0

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        curr = self.root
        for ch in word:
            if ch not in curr.children:
                curr.children[ch] = TrieNode()
            curr = curr.children[ch]
            curr.freq += 1 
        curr.end = True

    def search_unique_prefix(self, word: str) -> str:
        curr = self.root
        prefix = ""

        for ch in word:
            curr = curr.children[ch]
            prefix += ch
            if curr.freq == 1:
                break
        
        return prefix
        
        
class Solution:
    def findPrefixes(self, arr, N):
        # code here 
        trie = Trie()

        # insert all words
        for word in arr:
            trie.insert(word)

        # find shortest unique prefixes
        res = []
        for word in arr:
            prefix = trie.search_unique_prefix(word)
            res.append(prefix)

        return res