
def test(a,b):
    sum = a + b
    dif = a - b
    return sum,dif

result = test(1,2)
print(result.__getitem__(0))
print(result)