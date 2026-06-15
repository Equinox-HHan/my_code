dictionanry={'a':1,'b':2}
for key,value in dictionanry.items():
    print(f"{key},your number is {value}")

rivers = {'nile':'egypt','misisibi':'america',}
river=rivers.keys()
country=rivers.values()
print(river)
print(country)

for river in rivers.keys():
    print(river)
for country in rivers.values():
    print(country)

for key , value in rivers.items():
    print(f"The {key.upper()} go through {value.upper()}")


person_language={'mac':'python','torant':'c++','jim':'java'}
list_=['mac','cornas']
for name,language in person_language.items():
    print(name.title(), "your best language is",language)

for name in person_language.keys():
    if name in list_:
        print(name,"you need to grasp a language")

