class StockSpanner:

    def __init__(self):
        self.stack = []
        self.index = 0

    def next(self, price: int) -> int:

        # find the nearest greater to left element
        # stack[-1] gives the top element
        while (len(self.stack) != 0 and self.stack[-1][0] <= price):
            self.stack.pop()

        # default value of the idx i.e if nearest greater to left element is not found.
        self.ngl_idx = -1
        if len(self.stack) != 0 and self.stack[-1][0] > price:
            # nearest greater to left element is found. store its index
            self.ngl_idx = self.stack[-1][1]

        # store the price with its index. e.g. (100, 0)
        self.stack.append((price, self.index))

        span = self.index - self.ngl_idx
        self.index += 1

        return span

# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
