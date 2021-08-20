class bit:
    size = 0
    ary = None
    def __init__(self, size: int):
        self.size = size + 1
        self.ary = [0 for _ in range(size + 1)]
    
    def add(self, i: int, x: int):
        idx = i
        while idx < self.size:
            self.ary[idx] += x
    
    def sum(self, i: int) -> int:
        s = 0
        idx = i
        while idx < self.size:
            s += self.ary[idx]
        return s