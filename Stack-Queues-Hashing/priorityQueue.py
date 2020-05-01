class BinaryHeap():
    def __init__(self):
        self.heap = []

    def isEmpty(self):
        return len(self.heap) == 0

    def clear(self):
        for i in range(len(self.heap)):
            self.heap.pop()

    def size(self):
        return len(self.heap)

    def peek(self):
        if self.isEmpty():
            return None
        return self.heap[0]

    def poll(self):
        return self.removeAt(0)

    def contains(self, element):
        if element in self.heap:
            return True
        else:
            return False

    def add(self, elem):
        if elem != None:
            self.heap.append(elem)
            self.swim(len(self.heap)-1)
        else:
            print('Invalid Element')
            exit()

    def check(self, i, j):
        return self.heap[i] < self.heap[j]

    def swim(self, k):
        parent = int((k-1)/2)

        while k > 0 and self.check(k, parent):
            self.swap(parent, k)
            k = parent

            parent = int((k-1)/2)

    def sink(self, k):
        while True:
            lft = (2*k) + 1
            rght = (2*k) + 2

            smallest = lft

            if rght < len(self.heap) and self.check(rght,lft):
                smallest = rght
            
            if lft >= len(self.heap) or self.check(k,smallest):
                break
            
            self.swap(smallest,k)
            k = smallest
        
    def swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
    
    def remove(self,element):
        if(element == None):
            return False
        
        for i, c in enumerate(self.heap):
            if element == c:
                self.removeAt(i)
                return True
        return False

    def removeAt(self,i):
        if self.isEmpty():
            return None
        
        removedData = self.heap[i]

        self.swap(i, len(self.heap) - 1)

        self.heap.pop()

        element = self.heap[i]

        self.sink(i)

        if self.heap[i] == element:
            self.swim(i)

        return removedData

    def show(self):
        print(self.heap)

    def isMinHeap(self, k):
        if k >= len(self.heap):
            return True

        lft = (2 * k) + 1
        right = (2 * k) + 2

        if lft < len(self.heap) and not self.less(k, lft):
            return False
        if right < len(self.heap) and not self.less(k, right):
            return False

        return self.isMinHeap(lft) and self.isMinHeap(right)

# _________________________________________________

H = BinaryHeap()
H.add(4)
H.add(2)
H.add(0)
H.add(5)
H.add(7)
H.removeAt(0)
H.add(9)
H.add(3)
H.add(1)
H.show()

