class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError('Wrong Capacity')
        # Underscore must be use so that we can use properties, otherwise we get error.
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return self.size * "🍪"

    def deposit(self, n):
        if n > self.capacity:
            raise ValueError('Exceed Capacity')
        if self.size + n > self.capacity:
            raise ValueError('Exceed Capacity')
        self._size += n

    def withdraw(self, n):
        if self.size < n :
            raise ValueError('There are less cookies than you want')
        else:
            self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

jar = Jar()
print(Jar)
