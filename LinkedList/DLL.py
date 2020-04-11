class node:
    def __init__(self, data=None):
        self.data = data
        self.nxt = None
        self.prev = None


class DLL:
    def __init__(self):
        self.head = node()
        self.tail = node()

    def append(self, data):
        new_node = node(data)
        cur = self.head
        while cur.nxt:
            cur = cur.nxt
        cur.nxt = new_node
        new_node.prev = cur
        self.tail = new_node

    def length(self):
        cur = self.head
        size = 0
        while cur.nxt:
            size += 1
            cur = cur.nxt
        return size

    def erase(self, index):
        if abs(index) >= self.length():
            print('Error')
            return
        if index < 0:
            index = self.length()+index

        cur_idx = 0
        if index <= self.length()//2:
            cur_node = self.head
            while True:
                last_node = cur_node
                cur_node = cur_node.nxt
                if cur_idx == abs(index):
                    last_node.nxt = cur_node.nxt
                    if cur_node.nxt:
                        cur_node.nxt.prev = last_node
                    else:
                        self.tail = last_node
                    del cur_node
                    return
                cur_idx += 1
        else:
            index = self.length()-index-1
            cur_node = self.tail
            while True:
                last_node = cur_node
                if cur_idx == abs(index):
                    if last_node.nxt:
                        last_node.nxt.prev = cur_node.prev
                        cur_node.prev.nxt = last_node.nxt
                    if cur_node.nxt==None:
                        self.tail = last_node.prev
                        last_node.prev.nxt = None
                    # del cur_node
                    return
                cur_node = cur_node.prev
                cur_idx += 1
    
    # def ptop(self):
    #     print(self.head.data , self.head.nxt.data)
    #     print(self.tail.data , self.tail.prev.data)

    def find(self, data):
        idx = -1
        temp = self.head
        while temp:
            if temp.data == data:
                return idx
            temp = temp.nxt
            idx += 1
        else:
            return -1

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

    def display(self):
        elems = []
        cur_node = self.head
        while cur_node.nxt:
            cur_node = cur_node.nxt
            elems.append(cur_node.data)
        print(elems)

    def displayReverse(self):
        elems = []
        cur_node = self.tail
        while cur_node.prev:
            elems.append(cur_node.data)
            cur_node = cur_node.prev
        print(elems)

# ______________________________________________________


dll = DLL()

dll.append(0)
dll.append(1)
dll.append(2)
dll.append(3)
dll.append(4)
dll.append(5)
dll.append(6)
dll.append(7)
dll.append(8)
dll.display()

print("Elem at index :",dll.find(26))

dll.erase(-1)

dll.display()
dll.displayReverse()
