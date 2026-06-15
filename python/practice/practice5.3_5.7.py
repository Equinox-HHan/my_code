alien_colour='green'
if alien_colour=='green':
    print('5 points')
else:
    print("sorry")

alien_colour='red'or'yellow'
if alien_colour=='green':
    print('5 points')
else:
    print("sorry")

alien_colour='red'
if alien_colour=='green':
    print('5 points')
if alien_colour=="red":
    print("sorry")

#more
users=['admin','jaden','mming','xdd',]
for user in users:
    if user =='admin':
        print('Hello admin ,\nwoule you like to see astatues report?')
else:
    print(f"hello{users[1]},\tthank you for log in again".title())

users=[]
if users:
    for user in users:
        print("we need to find new users")
    print('now we have user')
else:
    print('ok')

current_users=['A','B','C','D','E']
new_users=['a','X','Y','Z']
for new_user in new_users:
    if new_user in  current_users:
        print(f"sorry,the name {new_user} had been used")
    if new_user not in  current_users:
        print(f"u can use the name {new_user} to log in")

A=list(range(0,10))
print(A)
for number in A:
    if number ==1:
        print(f"{number}st")
    elif number  in [2]:
        print(f"{number}nd")
    elif number  in [3]:
        print(f"{number}rd")
    else:
        print(f"{number}th")