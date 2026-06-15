person={'first_name':'zeng','last_name':'juhan','age':'19','city':'shenzheng'}
print(person['first_name'].title())
print(person['last_name'].title())
print(person['age'])
print(person['city'].upper())

#AMAZING
alien_0={'X_position':0,'Y_position':0,'speed':'medium'}
#alien start to move ,but speed is unclear:
if alien_0['speed']=='slow':
    X_increment=1
if alien_0['speed']=='medium':
    X_increment=2
if alien_0['speed']=='fast':
    X_increment=3
alien_0['X_position']=alien_0['X_position']+X_increment
print(f" the new position is {alien_0['X_position']}!")

dictionanry={'a':1,'b':2,'c':3}
number=dictionanry['a']
print(f"your number is {number}")

