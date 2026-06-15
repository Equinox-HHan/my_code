pets=[
    {'dding':'dog','owner':'xiao ming'},
    {'mming':'cat','owner':'xiao xin'},
    {'tting':'fish','owner':'xiao v'}
]
print(pets)
for pet in pets:
    print(pet)

person_number={
    'a':[1,2],
    'b':[3,4],
    'c':[99,100]
}
message="your favourite number are"
for key,values in person_number.items():
    print(f"\n{key},{message}")
    for value in values:
        print(f"\t,{value}")

cities={
    'Sedney':{'country':'Australia',
            'economy':'good even more',
            'environment':'nice'
            },
    'Berlin':{'country':'Germany',
            'economy':'good',
            'environment':'very nice'
            }
}
for city,info in cities.items():
    print('city'.upper(),city)
    print("it's information are below:")
    country=info['country']
    economy=info['economy']
    Environment=info['environment']
    print('country:',country)
    print('economy:',economy)
    print('environment:',Environment)
