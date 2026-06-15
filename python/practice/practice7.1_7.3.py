car=input("Enter your car name: ")
print(f"Let me see if I can find you a {car}")

number=input("how many people will take supper tonight? ")
number=int(number)
if number>8:
    message="sorry we have no table for you"
    print(message)
else:
    message="your table is ready"
    print(message)

value=input("Enter a number: ")
value=int(value)
if value%10==0:
    message=f"{value} is a multiple of 10"
    print(message)
else:
    message=f"{value} is not a multiple of 10"
    print(message)