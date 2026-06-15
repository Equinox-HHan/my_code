print("please enter two number")
number1=input("the first number")
number2=input("the second number")
try:
    numberA=float(number1)
    numberB=float(number2)
    value=numberA+numberB
    print(value)
except ValueError:
    print("please enter number instead of txt")
    



while True:
    print("please enter two number")
    number1=input("rhe first number")
    number2=input("the second number")
    try:
        numberA=float(number1)
        numberB=float(number2)
        value=numberA+numberB
        print(value)
        break
    except ValueError:
        print("please enter number instead of txt")
        continue
    
    
from pathlib import Path
try:
    path=Path('txt\cats_name.txt')
    message=path.read_text()
    print(message)
except FileNotFoundError:
    print("sorry,we can't find your file")
    

from pathlib import Path
try:
    path=Path('cats_name.txt')
    message=path.read_text()
    print(message)
except FileNotFoundError:
    pass
    


            
    

    
