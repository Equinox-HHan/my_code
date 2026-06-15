guest_list=['a','b','c','d']
message="the person who i want to invite to my supper"
print(f"{message}is:{guest_list}")

guest_list[0]="A"
guest_list[1]="B"
print(guest_list)

message="here i am sincerely invite you to come to our dinner"
print(f"{message}{guest_list[0]}")

# i found a bigger table for our party
guest_list=['a','b','c','d']
guest_list.insert(0,"zz")
guest_list.append("pro")
print(guest_list)

message="here i am sincerely invite you to come to our dinner"
print(f"{message}{guest_list}")

#i could only invite 2 people to my supper
guest_list=['a','b','c','d']
del guest_list[3]
print(guest_list)

guest_list.pop(1)
print(guest_list)
message="i only invite 2 person and they are"
print(f"{message}\t{guest_list}")

guest_list=['a','b','c','d']
sentence="i m so sorry that i cant invite you to the party "
print(f"{sentence}\n{guest_list.pop(1).title()}")

guest_list=['a','b','c','d']
guest_list.remove('c')
print(guest_list)


