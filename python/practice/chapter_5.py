cars=['audi','bmw','fararri','benz']
for car in cars:
    if car=="bmw":
        print(car.upper())
    else:
        print(car.title())

    car ='bmw'
    car =='audi'
True

requested_topping="mushroom"
if requested_topping!="anchovies":
    print('hold the anchovies')

ageA=17
ageB=21
if (ageA >= 20)or(ageB >= 20):
    print('uncorrect')
if(ageA >= 10)and(ageB >= 10):
    print('correct')
   
bannedusers=['a','b','c','d']
user='e'
message='welcome to comment'
if user not in bannedusers:
    print(f"{message.title()},{user}!")

#price for visiting
age=20

if age <=6:
    price=5
elif age <=18:
    price=10
elif age <=65:
    price=20
else:
    price=0

    print(f"you need to pay ${price}for ticket.".title())


#price for visiting
age=20

if age <=6:
    print("you need to pay5 yuan")
elif age <=18:
    print("you need to pay10 yuan")
elif age <=65:
    print("you need to pay20 yuan")
else:
    print("you need to pay0 yuan")
    



