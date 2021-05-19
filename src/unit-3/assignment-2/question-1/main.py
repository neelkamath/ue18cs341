"""
implement iterator in Python to traverse returning only those elements
	which satisfy a predicate.
	experiment for all odd numbers
				   perfect squares
				   prime numbers
"""


class MyCollection:
    def __init__(self, predicate, iterable):
        self.__predicate = predicate
        self.__iterable = list(iterable)

    def __iter__(self):
        return MyIterator(self.__predicate, self.__iterable)

    def append(self, *elements):
        self.__iterable += elements

    def remove_all(self, element):
        self.__iterable = [current for current in self.__iterable if current != element]


class MyIterator:
    def __init__(self, predicate, iterable):
        self.__index = 0
        self.__predicate = predicate
        self.__iterable = iterable

    def __next__(self):
        while True:
            if self.__index == len(self.__iterable):
                raise StopIteration
            element = self.__iterable[self.__index]
            self.__index += 1
            if self.__predicate(element):
                return element


def test_odd_nums():
    print('***ODD NUMBERS***')
    collection = MyCollection(lambda element: element % 2 == 0, range(10))
    iterable1 = iter(collection)
    iterable2 = iter(collection)
    print('Testing multiple instances of iterables:')
    for _ in range(2):
        print(next(iterable1))
        print(next(iterable2))
    print('Testing appending elements:')
    collection.append(1, 2, 3, 3)
    for element in collection:
        print(element)
    print('Testing removing elements:')
    collection.remove_all(3)
    for element in collection:
        print(element)


def is_perfect_square(num):
    for current in range(num + 1):
        if current * current == num:
            return True
    return False


def test_perfect_squares():
    print('***PERFECT SQUARES***')
    collection = MyCollection(is_perfect_square, range(10))
    for element in collection:
        print(element)


def is_prime(num):
    for current in range(2, num):
        if num % current == 0:
            return False
    return num not in [0, 1]


def test_prime_numbers():
    print('***PRIME NUMBERS***')
    collection = MyCollection(is_prime, range(30))
    for element in collection:
        print(element)


test_odd_nums()
test_perfect_squares()
test_prime_numbers()
