import sys


class node:
    def __init__(self, data=None):
        self.data = data
        self.lft = None
        self.rght = None
        self.parent = None
        self.height = 1


class AVL:
    def __init__(self):
        self.root = None

    def __repr__(self):
        if self.root == None:
            return ''
        content = '\n'  # to hold final string
        cur_nodes = [self.root]  # all nodes at current level
        cur_height = self.root.height  # height of nodes at current level
        # variable sized separator between elements
        sep = ' '*(2**(cur_height-1))
        while True:
            cur_height += -1  # decrement current height
            if len(cur_nodes) == 0:
                break
            cur_row = ' '
            next_row = ''
            next_nodes = []

            if all(n is None for n in cur_nodes):
                break

            for n in cur_nodes:

                if n == None:
                    cur_row += '   '+sep
                    next_row += '   '+sep
                    next_nodes.extend([None, None])
                    continue

                if n.data != None:
                    buf = ' '*int((5-len(str(n.data)))/2)
                    cur_row += '%s%s%s' % (buf, str(n.data), buf)+sep
                else:
                    cur_row += ' '*5+sep

                if n.lft != None:
                    next_nodes.append(n.lft)
                    next_row += ' /'+sep
                else:
                    next_row += '  '+sep
                    next_nodes.append(None)

                if n.rght != None:
                    next_nodes.append(n.rght)
                    next_row += '\ '+sep
                else:
                    next_row += '  '+sep
                    next_nodes.append(None)

            content += (cur_height*'   '+cur_row+'\n' +
                        cur_height*'   '+next_row+'\n')
            cur_nodes = next_nodes
            sep = ' '*int(len(sep)/2)  # cut separator size in half
        return content

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
                self._inspect_insertion(cur_node.lft)
            else:
                self._insert(data, cur_node.lft)
        elif data > cur_node.data:
            if cur_node.rght == None:
                cur_node.rght = node(data)
                cur_node.rght.parent = cur_node
                self._inspect_insertion(cur_node.rght)
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
            print(f"{cur_node.data} h={cur_node.height}", end=" ")
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

            return

        if node_parent:
            node_parent.height = 1 + \
                max(self.get_height(node_parent.lft),
                    self.get_height(node_parent.rght))

            self._inspect_deletion(node_parent)

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

    # _______AVL__________

    def _inspect_insertion(self, cur_node, path=[]):
        if cur_node.parent == None:
            return
        path = [cur_node]+path

        lft_h = self.get_height(cur_node.parent.lft)
        rght_h = self.get_height(cur_node.parent.rght)

        if abs(lft_h-rght_h) > 1:
            path = [cur_node.parent] + path
            self._rebalance_node(path[0], path[1], path[2])
            return

        new_height = 1+cur_node.height
        if new_height > cur_node.parent.height:
            cur_node.parent.height = new_height

        self._inspect_insertion(cur_node.parent, path)

    def _inspect_deletion(self, cur_node):
        if cur_node == None:
            return

        lft_h = self.get_height(cur_node.lft)
        rght_h = self.get_height(cur_node.rght)

        if abs(lft_h-rght_h) > 1:
            y = self.taller_child(cur_node)
            x = self.taller_child(y)
            self._rebalance_node(cur_node, y, x)

        self._inspect_deletion(cur_node.parent)

    def _rebalance_node(self, z, y, x):
        if y == z.lft and x == y.lft:
            self._right_rotate(z)

        elif y == z.lft and x == y.rght:
            self._left_rotate(y)
            self._right_rotate(z)

        elif y == z.rght and x == y.rght:
            self._left_rotate(z)

        elif y == z.rght and x == y.lft:
            self._right_rotate(y)
            self._left_rotate(z)
        else:
            raise Exception(
                '_rebalance_node: z,y,x node configuration not recognized!')

    def _right_rotate(self, z):
        sub_root = z.parent
        y = z.lft
        t3 = y.rght
        y.rght = z
        z.parent = y
        z.lft = t3
        if t3 != None:
            t3.parent = z
        y.parent = sub_root
        if y.parent == None:
            self.root = y
        else:
            if y.parent.lft == z:
                y.parent.lft = y
            else:
                y.parent.rght = y
        z.height = 1+max(self.get_height(z.lft),
                         self.get_height(z.rght))
        y.height = 1+max(self.get_height(y.lft),
                         self.get_height(y.rght))

    def _left_rotate(self, z):
        sub_root = z.parent
        y = z.rght
        t2 = y.lft
        y.lft = z
        z.parent = y
        z.rght = t2
        if t2 != None:
            t2.parent = z
        y.parent = sub_root
        if y.parent == None:
            self.root = y
        else:
            if y.parent.lft == z:
                y.parent.lft = y
            else:
                y.parent.rght = y
        z.height = 1+max(self.get_height(z.lft),
                         self.get_height(z.rght))
        y.height = 1+max(self.get_height(y.lft),
                         self.get_height(y.rght))

    def get_height(self, cur_node):
        if cur_node == None:
            return 0
        return cur_node.height

    def taller_child(self, cur_node):
        left = self.get_height(cur_node.lft)
        right = self.get_height(cur_node.rght)
        return cur_node.lft if left >= right else cur_node.rght
# __________________________________________________________


my_tree = AVL()

for i in range(10):
    print(f"Inserting {i}")
    my_tree.insert(i)
    print(my_tree)

for i in range(10):
    print(f"Deleting {i}")
    my_tree.delete_val(i)
    print(my_tree)
