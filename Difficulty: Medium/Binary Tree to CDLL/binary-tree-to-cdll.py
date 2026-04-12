'''
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None

'''
class Solution:
    def merge(self, head1, head2):
        if not head1:
            return head2
        if not head2:
            return head1

        tail1 = head1.left
        tail2 = head2.left

        tail1.right = head2
        head2.left = tail1

        tail2.right = head1
        head1.left = tail2

        return head1
        
        
    def bTreeToCList(self, root):
        if not root:
            return None

        left = self.bTreeToCList(root.left)
        right = self.bTreeToCList(root.right)

        root.left = root
        root.right = root

        return self.merge(self.merge(left, root), right)