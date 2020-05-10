class UnionFind:
    def __init__(self, size):
        if size <= 0:
            raise ValueError

        self.size = self.numComponents = size
        self.id = [i for i in range(self.size)]
        self.sz = [1 for i in range(self.size)]
    
    def find(self , p):
        root=p
        while root != self.id[root]:
            root = self.id[root]
        
        while p!=root:
            next = self.id[p]
            self.id[p] = root
            p = next

        return root

    
    def connected(self, p, q):
        return self.find(p) == self.find(q)
    
    def componentSize(self,p):
        return self.sz[self.find(p)]

    def __len__(self):
        return self.size
    
    def components(self):
        return self.numComponents

    def unify(self, p, q):
        root1 = self.find(p)
        root2 = self.find(q)

        if root1==root2:
            return

        if self.sz[root1] < self.sz[root2]:
            self.sz[root2] += self.sz[root1]
            self.id[root1] = root2
        else:
            self.sz[root1] += self.sz[root2]
            self.id[root2] = root1
        
        self.numComponents -=1
    
    def show(self):
        print("Size: ", self.sz)
        print("ID: ", self.id)

x = UnionFind(8)
x.unify(6,7)
x.unify(5,6)
x.unify(4,5)
x.unify(3,4)
x.unify(0,1)
x.unify(1,2)
x.unify(1,5)
x.show()