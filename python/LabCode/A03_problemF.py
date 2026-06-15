import math
row = int( input() )
if row == 1:
    print("*", end = "" )
    exit()
if row % 2 == 0 :
    raise ValueError
row = math.ceil( row / 2.0  )#n是行数
for n in range( 1, row + 1 ):
    i = 2 * n - 1   #每一行*的个数
    j = ( row  - n ) * 2    #每一行空格的个数
    for jj in range(j): #控制输出每一行的空格
        print( " ", end="" )
    if i > 1:   #如果一行字母*的个数大于1，则要控制*和*之间的空格格式然后输出
        for ii in range(i):
            if ii != i - 1:
                print("* ", end="" )
            else:
                print("*")
    else:   #如果一行的字母*的个数等于1，则直接输出*
        print("*")

# 输出完菱形的上半部分，下半部分直接通过反向控制输出
#********* Begin *********#
for countRow in range(row-1):
    SymNumber=(row*2-1)-((countRow+1)*2)#符号的数量
    tableNumber=(countRow+1)*2
    for cal in range(tableNumber):
        print(" ",end="")
    if SymNumber>1:
        for ss in range(SymNumber):
            if ss!=SymNumber-1:
                print("* ",end="")
            else:
                print("*")
    else:
        print("*",end="")
# 注意最后一层一个*的时候，不需要换行，去掉换行
#********* End *********#