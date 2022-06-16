import numpy as np

# 创建数组
array1 = np.array([[1,2,3],[4,5,6]])
array_zeros = np.zeros((3,4) , dtype=np.float32)
array_one = np.ones((3,4))
array_range = np.arange(1,4)
array_rad = np.random.rand(3,4)
# print(array1.shape)
# print(array_zeros)
# print(array_one)
# print(array_range)
# print(array_rad)
#内部操作
print(array1.min())
print(array1.max())
print(array1.sum())
#平均值
print(array1.mean())
#方差
print(array1.var())     
#标准方差
print(array1.std())
#返回最大最小的索引
print(array1.argmin())
print(array1.argmax())
#axis = 0 时 每一行的数据会相加
array2 = array1.sum(axis=0)
print(array2)
#axis = 1 时 每一列的数据会相加
array3 = array1.sum(axis=1)
print(array3)

#快速获取数据
print(array1[0,0:2])
print(array1[(array1>3)&(array1%2==0)])
#第二各冒号后跟随着一个跨度，表示要如何跳跃取数
print(array1[0,0:2:1])
print(array1[0,::-1])
#运算
theFirst = np.array([1,2,3])
theSecond = np.array([4,5,6])
print(theFirst + theSecond)
print(theFirst - theSecond)
print(theFirst * theSecond)
print(theFirst / theSecond)
#点乘
print(np.dot(theFirst,theSecond))
#不同尺寸的数组也可以做运算
array_row = np.array([[1],[2],[3]])
array_col = np.array([1,2,3])
print(array_row + array_col)
print(array_col * array_row)
print(array_col @ array_row)