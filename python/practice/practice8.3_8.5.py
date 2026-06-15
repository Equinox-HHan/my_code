def make_shirt(size,text):
    print(f"The size of the shirt is {size} and the text printed on it is '{text}'")
#weizhishican    
make_shirt('L','I love Python')
#guanjianzishican
make_shirt(text='love u',size='xl')


def make_shirt1(size='l',text='i love u;'):
    print(f"the size of the shirt is {size} and the text is {text}")
    
make_shirt1()
make_shirt1('middle')
make_shirt1(text='hello')

def describe_city(city,country='china'):
    print(f"{city} is in {country}")
    
describe_city('beijing')
describe_city('shanghai') 
describe_city('tokyo','japan')


cities=['beijing','shanghai','tokyo']
for city in cities:
    describe_city(city) 