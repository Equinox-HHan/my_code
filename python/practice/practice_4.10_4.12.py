players=['A','B','C','D','E']
message="these are the best players"
for player in players[0:2]:
    print(f"{message.title()}:{player}")

my_favourite_pizzas=['BACON','CHEESE','BEEF','PINEAPPLE']
friend_pizza_list=my_favourite_pizzas[:]
my_favourite_pizzas.append('hotchido')
friend_pizza_list.append('wasaka')
sentence1="my favourite pizza is"
sentence2="my friend's favourite pizza is"
for pizza in my_favourite_pizzas:
    print(f"{sentence1},{pizza}")
print(f"{sentence2}:{friend_pizza_list}")