########## 第一题 ##############
from math import *  

i = 1 # 当前计算的值  
s = 0 # 计算出来的和   
########### begin ##########
while i<1000:	
######### end     ####
	s = s + i ** 2  
	i = i + 2  

print(s)  

########## 第二题 ##############
x = int(input())  

if x<0:  
	print('无实数解')  
else:  
	g = x/2  
#######begin##############
while abs((x-g*g))>pow(10,-6):
#######end#################
	g = (g+x/g)/2  
print('{:.10f}'.format(g))