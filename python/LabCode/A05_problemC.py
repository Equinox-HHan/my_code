import random

s = int(input())
random.seed(s)  # 调用函数，输出结果
"""创建两个二维列表"""
lsa = []
lsb = []
for i in range(1, 6):
    lsa.append([i, random.randint(0, 100), random.randint(0, 100)])
    lsb.append([i, random.randint(0, 100)]) 
"""创建两个二维列表"""
print('原数据', lsa)
print('新增成绩', lsb)

p = int(input())#指定更新学生

"""合并列表，将lsb中成绩插入到"""
score_ls = []
########## Begin ########## 
  
########## End ########## 

"""合并列表，将lsb中成绩插入到"""
print('更新后数据', score_ls)