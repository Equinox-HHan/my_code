sequence=[1,2,None,4,None,5]
total=0
for value in sequence:
    if value==None:
        continue
    else:
        total+=value
print(total)

x=[1,3,5]
y=[2,4,6]
z=x+y
print(z)

tuple=(1,2,3,)
print(tuple)

tuple=('apple','orange')*2
print(tuple)

value=1,2,3,4,5
a,b,*_=value
print(_)

a=(10,21,17,6,8,10)
A=a.count(10)
print(A)

print(range(11))
print(list(range(11)))
for value in range(0,11,2):
    print(value)
    
sequence=[1,3,2,6,7]
sequence
print(sequence)

words=['apple','bear','orange','banana']
by_letter={}
for word in words:
    letter=word[0]
    if letter not in by_letter:
        by_letter[letter]=[word]
    else:
        by_letter[letter].append(word)
print(by_letter)

from collections import defaultdict
by_letter=defaultdict(list)
for word in words:
    by_letter[word[0]].append(word)
print(by_letter)

info={'name':'zengjuhan','age':'19','career':'student'}
tip=info.get('career','sorry,we have no info')
print(tip)

a={1,2,4,6,7}
b={1,3,5,7,9}
print(a.union(b))

def square(n=10):
    print(f"generating from 1 to {n**2}")
    for i in range(1,n+1):
        yield i**2
gen=square()
for x in gen:
    print(x)

def apply_the_list(some_list,f):
    return [f(x) for x in some_list]
    
ints=[1,2,3,4,5]
apply_the_list(ints,lambda x:x*2)


