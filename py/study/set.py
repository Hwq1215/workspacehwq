set1 = {0,1,2,3,4,5}

set1.add(6)
set1.discard(3)

set2 = {0,2,9}

print(set1.intersection(set2))
print(set2.difference(set1))

set2.discard(9)
print(set2.issubset(set1))