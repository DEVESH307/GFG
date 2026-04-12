'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def boundaryTraversal(self, root):
        if not root:
            return []

        self.res = [root.data]

        # left boundary
        self.left_boundary(root.left)

        # leaves
        self.leaves(root.left)
        self.leaves(root.right)

        # right boundary
        self.right_boundary(root.right)

        return self.res


    def is_leaf(self, node):
        return node and not node.left and not node.right


    # LEFT BOUNDARY
    def left_boundary(self, node):
        while node:
            if not self.is_leaf(node):
                self.res.append(node.data)

            if node.left:
                node = node.left
            else:
                node = node.right


    # LEAVES
    def leaves(self, node):
        if not node:
            return

        if self.is_leaf(node):
            self.res.append(node.data)
            return

        self.leaves(node.left)
        self.leaves(node.right)


    # RIGHT BOUNDARY (REVERSED)
    def right_boundary(self, node):
        stack = []

        while node:
            if not self.is_leaf(node):
                stack.append(node.data)

            if node.right:
                node = node.right
            else:
                node = node.left

        while stack:
            self.res.append(stack.pop())