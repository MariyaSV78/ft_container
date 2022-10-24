==========================================================================
[32m                                     map[0m
==========================================================================
Default constructor: empty map


Filling map: [a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5


Range constructor: [a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5


Copy constructor: [a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5


Assignement operator: [a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5


==========================================================================

[a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5
Max_size:
max size for def_map = 230584300921369395
max size for copy_map = 230584300921369395

Begin, end: 
first element = a; last element = 101

Rbegin, rend: 
def_map.rend()-> first: first element key= a; def_map.rend()->second: first element value =97
def_map.rbegin()->first(): last element key = e; def_map.rbegin()->second: last element value=101

Iterator
[a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5
[a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5

Iterator (const)
[a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5
[a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5

Reverse Iterator
[a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5
[a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5

Reverse Iterator (const)                 [a: 97], [b: 98], [c: 99], [d: 100], [e: 101],  size = 5
[a: 101], [b: 100], [c: 99], [d: 98], [e: 97],  size = 5

Element accesse []: 
copy_map['b'] is 1000
copy_map['x'] is 350
[a: 97], [b: 1000], [c: 99], [d: 100], [e: 101], [x: 350],  size = 6


Insert (single parameter): [a: 97], [b: 98], [c: 99], [d: 100], [e: 101], [f: 102], [g: 103],  size = 7


Insert (with hint position): [a: 97], [b: 98], [c: 99], [d: 100], [e: 101], [f: 102], [g: 103], [i: 105],  size = 8


Insert (range insertion): [A: 65], [a: 97], [b: 98], [c: 99], [i: 105], [j: 106],  size = 6


Erase: position [A: 65], [b: 98], [c: 99], [i: 105], [j: 106],  size = 5


Erase: by key
erase1 element(s)1
[A: 65], [b: 98], [c: 99], [j: 106],  size = 4


Erase: by range: 
[A: 65],  size = 1


Swap:
map_1: [a: 97], [b: 98], [c: 99], [d: 100], [e: 101], [f: 102], [g: 103], [i: 105],  size = 8
map_2: [A: 65],  size = 1

===swap===
map_1: [A: 65],  size = 1
map_2: [a: 97], [b: 98], [c: 99], [d: 100], [e: 101], [f: 102], [g: 103], [i: 105],  size = 8


Clear:[B: 66],  size = 1


Key compare:
compare keys: 115 and 116: the first argument is considered to go before the second

Key value:       [32mOK[0m

Find:
[a:97]
[a: 97], [b: 1000], [c: 99], [d: 100], [e: 101], [x: 350],  size = 6
[b: 1000], [c: 99], [d: 100], [e: 101], [x: 350],  size = 5


Count:
N elements with key c = 1
N elements with key x = 0


Lower_bound and upper_bound:
[b: 1000], [c: 99], [d: 100], [e: 101], [x: 350],  size = 5
Lower_bound point: [c : 99]
Upper_bound point: [e : 101]
After erase: [b: 1000], [e: 101], [x: 350],  size = 3


Equal range:
lower bound points to: b => 20
upper bound points to: c => 30

