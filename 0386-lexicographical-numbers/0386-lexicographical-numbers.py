class Solution:
    def __init__(self):
        self.ans = []
        self.n = 0

    def f(self, i):
        if i > self.n:
            return
        if i > 0:
            self.ans.append(i)
        for j in range(1 if i == 0 else 0, 10):
            x = 10 * i + j
            if x > self.n:
                break
            self.f(x)

    def lexicalOrder(self, n):
        self.n = n
        self.ans = []
        self.f(0)
        return self.ans
