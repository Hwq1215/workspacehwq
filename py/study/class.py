from math import ceil, floor


class Person:
    def __init__(self,name,age):
        self.name = name
        self.age = age

    def get_name(self):
        return self.name

    def get_age(self):
        return self.age

person1 = Person("John",36)

print(person1.get_age())   

# round 四舍五入
a = float(3)
b = 2
print(round(a/b)) 

#ceil
print(ceil(a/b))

#floor
print(floor(a/b))