class restaurant:
    def __init__(self,restaurant_name,cuisine_type):
        self.name=restaurant_name
        self.cuisine=cuisine_type
    def discribe_restaurant(self):
        print(f"our restaurant name is {self.name}")
        print(f"we can provide your {self.cuisine} food")
    def open_restaurant(self):
        print('we are open now')

class IceCreamStand(restaurant):
    def __init__(self,restaurant_name,cuisine_type):
        super().__init__(restaurant_name,cuisine_type)
        self.flavors=['chocolate','pineapple']
    def show_flavors(self):
        for flavor in self.flavors:
            print('\n-'+flavor)
        
                
icecreamstand=IceCreamStand('KFC','icecream')
icecreamstand.discribe_restaurant()
icecreamstand.show_flavors()
        


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
        
class Admin(User):
    def __init__(self,first_name,last_name,age,career):
        super().__init__(first_name,last_name,age,career)
        self.privileges=['can add post','can ban users','candelete post']
    def show_priviliges(self):
        for privilige in self.privileges:
            print('\n-'+privilige)
            
admin=Admin('zeng','juhan',19,'student')
admin.discribe_users()
admin.show_priviliges()

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
class Privileges:
    def __init__(self,privileges=['can add post','can ban users','can delete post']):
        self.privileges=privileges
    def show_priviliges(self):
        for privilige in self.privileges:
            print('\n-'+privilige)
class Admin(User):
    def __init__(self,first_name,last_name,age,career):
        super().__init__(first_name,last_name,age,career)
        self.privileges=Privileges()

admin=Admin('zeng','juhan',19,'student')
admin.discribe_users()
admin.privileges.show_priviliges()
admin.privileges.privileges.append('can shutdown system')
admin.privileges.show_priviliges()


class Car:
    def __init__(self,make,model,year):
        self.make=make
        self.model=model
        self.year=year
        self.odometer_reading=0
    def get_descriptive_name(self):
        long_name=f"{self.year} {self.make} {self.model}"
        return long_name.title()
    def read_odometer(self):
        print(f"this car has {self.odometer_reading} miles on it")
    def update_odometer(self,mileage):
        if mileage>=self.odometer_reading:
            self.odometer_reading=mileage
        else:
            print("you can't roll back an odometer")
    def increment_odometer(self,miles):
        self.odometer_reading+=miles
        
class Battery:
    def __init__(self,battery_size=75,battery_volumn=100):
        self.battery_size=battery_size
        self.battery_volumn=battery_volumn
    def upgrade_battery(self):
        if self.battery_volumn!=65:
            self.battery_volumn=65
    def describe_battery(self):
        print(f"this car has a {self.battery_size}-kwh battery")
    def get_range(self):
        if self.battery_size==75:
            range=260
        elif self.battery_size==100:
            range=315
        print(f"this car can go about {range} miles on a full charge")
        
class ElectricCar(Car):
    def __init__(self,make,model,year):
        super().__init__(make,model,year)
        self.battery=Battery()
        
my_tesla=ElectricCar('tesla','model s',2019)
print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery()
my_tesla.battery.get_range()
my_tesla.battery.upgrade_battery()
my_tesla.battery.get_range()
my_tesla.battery.upgrade_battery()
my_tesla.battery.get_range()   