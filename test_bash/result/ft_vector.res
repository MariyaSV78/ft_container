==========================================================================
[32m                                  vector[0m
==========================================================================
Default constructor 
capacity = 0, size = 0

Default constructor pointer 
capacity = 0, size = 0

Fill constructor 
capacity = 0, size = 0

Fill constructor sized
0, 0, 0, 0, 0, 0, 0, 0, 0, capacity = 9, size = 9

Fill constructor sized & valued
42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 9, size = 9

Copy constructor 
42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 9, size = 9

Assign operator
42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 9, size = 9

Iterator constructor 
42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 9, size = 9

==========================================================================

Max_size:
max size for def_vector = 2305843009213693951
max size for copy_vector = 2305843009213693951

resize(15,42)
42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 18, size = 15

reserve(10)
42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 18, size = 15

push_back(10)
42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 10, 15, 20, 10, capacity = 36, size = 19

pop_back()
42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 10, 15, capacity = 36, size = 17

assign(4, 10)
10, 10, 10, capacity = 36, size = 3

insert(position, value)
10, 10, 42, 10, capacity = 36, size = 4

insert(position, n, value)
10, 10, 42, 42, 42, 42, 42, 10, capacity = 36, size = 8

insert(position, first, last)
10, 10, 1, 1, 1, 42, 42, 42, 42, 42, 10, capacity = 36, size = 11

erase(position)
10, 1, 1, 1, 42, 42, 42, 42, 42, 10, capacity = 36, size = 10

erase(range)
10, 42, 42, 42, 42, 10, capacity = 36, size = 6

swap
vector_1: 10, 42, 42, 42, 42, 10, capacity = 36, size = 6
vector_2: 42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 9, size = 9

===swap===
map_1: 42, 42, 42, 42, 42, 42, 42, 42, 42, capacity = 9, size = 9
map_2: 10, 42, 42, 42, 42, 10, capacity = 36, size = 6

clear
capacity = 9, size = 0

