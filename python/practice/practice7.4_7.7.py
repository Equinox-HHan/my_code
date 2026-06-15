message="please tell me what toppings you want on your pizza"
message+="\n(enter 'quit' when you are finished): "
while True:
    topping=input(message)
    if topping!='quit':
        print(f"we will add {topping} to your pizza")
    else:
        break

message="please tell me what toppings you want on your pizza"
message+="\n(enter 'quit' when you are finished): "
topping=input(message)
while True:
    if topping=='quit':
        break
    else:   
        print(f"we will add {topping} to your pizza")

toppings=input("Enter toppings for your pizza: ")
toppings+=" (enter 'quit' to end) "
active=True
while active:
    if toppings=='quit':
        active=False
    else:
        print(f"we will add {toppings} to your pizza")


prompt="Enter your age: "
age=input(prompt)
age=int (age)
while True:
    if age<3:
        print("your ticket is free")
        break
    if age <12:
        print("your ticket is $10")
        break
    else:  
        print("your ticket is $15")
        break