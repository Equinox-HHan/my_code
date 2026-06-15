class restaurant:
    def __init__(self,restaurant_name,*cuisine_type):
        self.name=restaurant_name
        self.cuisine=cuisine_type
    def discribe_restaurant(self):
        print(f"our restaurant name is{self.name}")
        print(f"we can provide your{self.cuisine} food")
    def open_restaurant(self):
        print('we are open now')
        
my_restaurant=restaurant('mcdonald','chips','hamburger','cola')
print(my_restaurant.name)
print(my_restaurant.cuisine)
my_restaurant.discribe_restaurant()
my_restaurant.open_restaurant()

class User:
    def __init__(self,first_name,last_name,age,career):
        self.first_name=first_name
        self.last_name=last_name
        self.age=age
        self.career=career
    def discribe_users(self):
        print(f"your first name is {self.first_name}")
        print(f"your last name is {self.last_name}")
        print(f"your age and your career are\n{self.age} {self.career}")
    def greet_user(self):
        full_name=f"{self.first_name}{self.last_name}"
        print('hello,'+full_name)
        
my_user=User('zeng','juhan',19,'student')
my_user.discribe_users()
my_user.greet_user()    
    