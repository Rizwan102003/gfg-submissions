class SpecialQueue:
    def __init__(self):
        # Define Data Structures
        self.queue = deque()
        self.minDeque = deque()
        self.maxDeque = deque()
    
    def enqueue(self, x):
        # Insert element into the queue
        self.queue.append(x)

        # Maintain minDeque
        while self.minDeque and self.minDeque[-1] > x:
            self.minDeque.pop()
        self.minDeque.append(x)

        # Maintain maxDeque
        while self.maxDeque and self.maxDeque[-1] < x:
            self.maxDeque.pop()
        self.maxDeque.append(x)

    def dequeue(self):
        # Remove element from the queue
        if self.queue:
            val = self.queue.popleft()
            if val == self.minDeque[0]:
                self.minDeque.popleft()
            if val == self.maxDeque[0]:
                self.maxDeque.popleft()

    def getFront(self):
        # Get front element
        return self.queue[0] if self.queue else None

    def getMin(self):
        # Get minimum element
        return self.minDeque[0] if self.minDeque else None
    
    def getMax(self):
        # Get maximum element
        return self.maxDeque[0] if self.maxDeque else None

