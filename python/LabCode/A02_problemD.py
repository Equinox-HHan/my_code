#********** Begin *********#
import math  # 导入math模块

m = int(input())  # 输入大披萨直径 m英寸
n = int(input())  # 输入小披萨直径 n英寸

radius_of_m = (int(m*2.54))/2 # 计算大披萨直径，厘米，取整，再计算半径
radius_of_n = (int(n*2.54))/2 # 计算小披萨直径，厘米，取整，再计算半径
num = math.ceil(pow(radius_of_m,2)/pow(radius_of_n,2))# 计算大小披萨面积比值，格式化输出向上取整
print(num)  # 

#********** End *********#