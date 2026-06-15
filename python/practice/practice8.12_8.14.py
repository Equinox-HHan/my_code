def sandwich_toppings(*toppings):
    """Print the list of sandwich toppings that have been requested."""
    print(f"\nthe toppings are in your sandwich: {toppings} ")
sandwich_toppings('lettuce', 'tomato', 'mayo')
sandwich_toppings('turkey', 'bacon', 'avocado', 'cheese')


def sandwich_order(size, *toppings):
    """Summarize the sandwich order."""
    print(f"\nYou ordered a {size}-inch sandwich with the following toppings:")
    for topping in toppings:
        print(f"- {topping}")
sandwich_order(12, 'lettuce', 'tomato', 'mayo')
sandwich_order(6, 'turkey', 'bacon', 'avocado', 'cheese')

def build_profile(first, last, **user_info):
    user_info['first_name'] = first
    user_info['last_name'] = last
    return user_info
user_profile = build_profile('zeng', 'juhan',age=22, city='shanghai')
print(user_profile)


def car_information(maker,typ,**car_info):
    car_info['company']=maker
    car_info['type']=typ
    return car_info
car=car_information('subaru','outback',color='blue',tow_package=True)
print(car)


message='please tell the maker company and the tyoe of the car'
message+='\n you can tell me more information of the car if you want'
information=input(message)   