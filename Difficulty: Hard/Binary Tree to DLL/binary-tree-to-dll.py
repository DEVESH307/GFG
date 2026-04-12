'''
class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None
'''
class Solution:
    def bToDLL(self,root):
        # Code here
        if not root:
            return None
        
        self.head = None
        self.prev = None
        
        def inorder(node):
            if not node:
                return
            
            inorder(node.left)

            if not self.prev:
                self.head = node
            else:
                self.prev.right = node
                node.left = self.prev
            
            self.prev = node
            
            inorder(node.right)

        inorder(root)
        
        return self.head