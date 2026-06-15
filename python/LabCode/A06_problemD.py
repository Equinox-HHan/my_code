import math

class Vector3d:
    def __init__(self, x, y, z):
        self.__x = x
        self.__y = y
        self.__z = z

    def length(self):
        # 请在这里补充代码，完成本关任务
    	#********** Begin *********#
        # 计算三维向量长度：sqrt(x^2 + y^2 + z^2)
        return (self.__x**2 + self.__y**2 + self.__z**2)**0.5
    	#********** End *********#

    # 请在这里增加3个特殊方法，分别用来支持加法运算符、减法运算符以实现两个三维向量间的加法和减法运算
    	#********** Begin *********#
    
    # 重载加法运算符 +
    def __add__(self, other):
        return Vector3d(self.__x + other.__x, self.__y + other.__y, self.__z + other.__z)

    # 重载减法运算符 -
    def __sub__(self, other):
        return Vector3d(self.__x - other.__x, self.__y - other.__y, self.__z - other.__z)

    # 重载打印输出 print()
    def __str__(self):
        # 按照题目要求的格式 (x y z) 返回字符串
        return "({} {} {})".format(self.__x, self.__y, self.__z)

    	#********** End *********#
        
if __name__=="__main__": 
    # 处理输入：读取一行并按空格拆分，转为 float 列表
    # 注意：输入可能是六个数在一行，也可能分两行。根据题目描述，连续读取两组坐标。
    input_data = []
    while len(input_data) < 6:
        input_data.extend([float(x) for x in input().split()])
    
    x1, y1, z1 = input_data[0:3]
    m1 = Vector3d(x1, y1, z1) 
    print('The m1 is', m1)
    print('Length of m1 is {:.2f}'.format(m1.length())) 

    x2, y2, z2 = input_data[3:6]
    m2 = Vector3d(x2, y2, z2) 
    print('The m2 is', m2)    
    print('Length of m2 is {:.2f}'.format(m2.length()))
    
    m3 = m1 + m2
    print('The m3 is', m3)
    print('Length of m1+m2 is {:.2f}'.format(m3.length()))
    m4 = m1 - m2
    print('The m4 is', m4)
    print('Length of m1-m2 is {:.2f}'.format(m4.length()))