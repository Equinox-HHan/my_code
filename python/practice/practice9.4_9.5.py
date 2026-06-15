class Restaurant:
    def __init__(self,restaurant_name,*cuisine_type):
        self.name=restaurant_name
        self.cuisine=cuisine_type
        self.number_served=0
    def discribe_restaurant(self):
        print(f"our restaurant name is{self.name}")
        print(f"we can provide your{self.cuisine} food")
    def served_number(self):
        print(f"we have served {self.number_served} people")

restaurant=Restaurant('zhenggongfu','chinese food')
print(f"{restaurant.name}is a{restaurant.cuisine}restaurant")
restaurant.number_served=100
restaurant.served_number()


class Restaurant:
    def __init__(self,restaurant_name,*cuisine_type):
        self.name=restaurant_name
        self.cuisine=cuisine_type
        self.number_served=0
    def discribe_restaurant(self):
        print(f"our restaurant name is{self.name}")
        print(f"we can provide your{self.cuisine} food")
    def served_number(self):
        print(f"we have served {self.number_served} people")
    def set_number_served(self,number):
        self.number_served=number
        
restaurant=Restaurant('zhenggongfu','chinese food')
print(f"{restaurant.name}is a{restaurant.cuisine}restaurant")
restaurant.set_number_served(100)
restaurant.served_number()



class User:
    def __init__(self,first_name,last_name,age,career):
        self.first_name=first_name
        self.last_name=last_name
        self.age=age
        self.career=career
        self.login_attempts=0
    def discribe_users(self):
        print(f"your first name is {self.first_name}")
        print(f"your last name is {self.last_name}")
        print(f"your age and your career are\n{self.age} {self.career}")
    def greet_user(self):
        full_name=f"{self.first_name}{self.last_name}"
        print('hello,'+full_name)
    def increasement_login_attempts(self,attempts):
        self.login_attempts+=attempts
    def reset_login_attempts(self):
        self.login_attempts=0

my_user=User('zeng','juhan',19,'student')
my_user.increasement_login_attempts(17)
my_user.increasement_login_attempts(21
                                    )
print(my_user.login_attempts)
my_user.reset_login_attempts()
print(my_user.login_attempts)