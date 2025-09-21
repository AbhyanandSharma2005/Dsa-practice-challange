from collections import defaultdict
from sortedcontainers import SortedSet

class MovieRentingSystem:

    def __init__(self, n: int, inventory: List[List[int]]):
        self.available_movies = defaultdict(SortedSet)  
        self.movie_price = {}                           
        self.rented_set = SortedSet()                   

        for shop, movie, price in inventory:
            self.available_movies[movie].add((price, shop))
            self.movie_price[(movie, shop)] = price

    def search(self, movie: int) -> List[int]:
        top_shops = []
        for price, shop in self.available_movies[movie]:
            top_shops.append(shop)
            if len(top_shops) == 5:
                break
        return top_shops

    def rent(self, shop: int, movie: int) -> None:
        price = self.movie_price[(movie, shop)]
        self.rented_set.add((price, shop, movie))
        self.available_movies[movie].discard((price, shop))

    def drop(self, shop: int, movie: int) -> None:
        price = self.movie_price[(movie, shop)]
        self.rented_set.discard((price, shop, movie))
        self.available_movies[movie].add((price, shop))

    def report(self) -> List[List[int]]:
        top_rented = []
        for price, shop, movie in self.rented_set:
            top_rented.append([shop, movie])
            if len(top_rented) == 5:
                break
        return top_rented