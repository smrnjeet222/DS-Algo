import sys
from random import randint


class node:
    def __init__(self, data=None):
        self.data = data
        self.lft = None
        self.rght = None
        self.parent = None


class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root == None:
            self.root = node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, cur_node):
        if data < cur_node.data:
            if cur_node.lft == None:
                cur_node.lft = node(data)
                cur_node.lft.parent = cur_node
            else:
                self._insert(data, cur_node.lft)
        elif data > cur_node.data:
            if cur_node.rght == None:
                cur_node.rght = node(data)
                cur_node.rght.parent = cur_node
            else:
                self._insert(data, cur_node.rght)
        else:
            print("Value alredy exists")

    def display(self):
        if self.root:
            self._printTree(self.root)

    def _printTree(self, cur_node):
        if cur_node:
            self._printTree(cur_node.lft)
            print(cur_node.data, end=" ")
            self._printTree(cur_node.rght)

    def height(self):
        if self.root:
            return self._height(self.root, 0)
        else:
            return 0

    def _height(self, cur_node, cur_h):
        if cur_node == None:
            return cur_h
        lft_h = self._height(cur_node.lft, cur_h+1)
        rght_h = self._height(cur_node.rght, cur_h+1)
        return max(lft_h, rght_h)

    def search(self, val):
        if self.root:
            par_node = self._search(val, self.root)
            return bool(par_node)
        else:
            return False

    def find(self, val):
        if self.root:
            return self._search(val, self.root)
        else:
            return None

    def _search(self, val, cur_node):
        if val == cur_node.data:
            return cur_node
        elif val < cur_node.data and cur_node.lft:
            return self._search(val, cur_node.lft)
        elif val > cur_node.data and cur_node.rght:
            return self._search(val, cur_node.rght)

    def delete_val(self, val):
        n = self.find(val)
        if n:
            return self.delete_node(self.find(val))
        else:
            return

    def delete_node(self, node):
        def min_value_node(n):
            current = n
            while current.lft:
                current = current.lft
            return current

        def num_child(n):
            num = 0
            if n.lft:
                num += 1
            if n.rght:
                num += 1
            return num

        node_parent = node.parent
        node_child = num_child(node)

        if node_child == 0:
            if node_parent:
                if node_parent.lft == node:
                    node_parent.lft = None
                else:
                    node_parent.rght = None
            else:
                self.root = None

        if node_child == 1:
            if node.lft:
                child = node.lft
            else:
                child = node.rght
            if node_parent:
                if node_parent.lft == node:
                    node_parent.lft = child
                else:
                    node_parent.rght = child
            else:
                self.root = child

            child.parent = node_parent

        if node_child == 2:

            successor = min_value_node(node.rght)
            node.data = successor.data

            self.delete_node(successor)

    def isBST(self):
        if self.root:
            return self._isBST(self.root)
        else:
            return True

    def _isBST(self, root, min=-sys.maxsize, max=sys.maxsize):
        if root == None:
            return True
        return (root.data > min and root.data < max and
                self._isBST(root.lft, min, root.data) and
                self._isBST(root.rght, root.data, max))

    def levelOrderTraversal(self):
        result = []
        self._levOT([self.root], result)
        return result

    def _levOT(self, cur, res):
        if cur==[]:
            return
        nxtlevel=[]
        for node in cur:
            res.append(node.data)
            if node.lft:
                nxtlevel.append(node.lft)
            if node.rght:
                nxtlevel.append(node.rght)
        self._levOT(nxtlevel, res)

# __________________________________________________________


def fill_tree(tree, num_elems=100, max_int=1000):
    for _ in range(num_elems):
        cur_elem = randint(0, max_int)
        tree.insert(cur_elem)
    return tree


my_tree = BST()
my_tree = fill_tree(my_tree)

my_tree.display()
print("\nTree Height is :", str(my_tree.height()))

print("\nIs 100 present :", my_tree.search(100))
print("Is 200 present :", my_tree.search(200))
print("Is 300 present :", my_tree.search(900))

my_tree.delete_val(100)
my_tree.delete_val(200)
my_tree.delete_val(900)

print("\nAfter deletion : \n")
my_tree.display()

print("\nIs BST:", my_tree.isBST())

print("Level Order Trav. \n", my_tree.levelOrderTraversal())