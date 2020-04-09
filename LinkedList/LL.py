class node:
    def __init__(self, data=None):
        self.data = data
        self.nxt = None


class linkedList:
    def __init__(self):
        self.head = node()

    def append(self, data):
        new_node = node(data)
        cur = self.head
        while cur.nxt != None:
            cur = cur.nxt
        cur.nxt = new_node

    def length(self):
        cur = self.head
        total = 0
        while cur.nxt != None:
            total += 1
            cur = cur.nxt
        return total

    def display(self):
        elems = []
        cur_node = self.head
        while cur_node.nxt != None:
            cur_node = cur_node.nxt
            elems.append(cur_node.data)
        print(elems)

    def get(self, index):
        if index >= self.length():
            print("Error")
            return None
        cur_idx = 0
        cur_node = self.head
        while True:
            cur_node = cur_node.nxt
            if cur_idx == index:
                return cur_node.data
            cur_idx += 1

    def erase(self, index):
        if index >= self.length():
            print("Error")
            return
        cur_idx = 0
        cur_node = self.head
        while True:
            last_node = cur_node
            cur_node = cur_node.nxt
            if cur_idx == index:
                last_node.nxt = cur_node.nxt
                return
            cur_idx += 1

# _________________________________________________

my_list = linkedList()

my_list.append(0)
my_list.append(1)
my_list.append(2)
my_list.append(5)
my_list.append(8)
my_list.append(13)
my_list.display()
print(my_list.length())
print("Elem at 2 index:", my_list.get(2))

my_list.erase(1)

my_list.display()
