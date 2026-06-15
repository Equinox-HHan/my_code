from pathlib import Path
import json
number=input('please tell me your favourite number')
numbers=[]
numbers.append(number)
path=Path('json_file\ fav_number.json')
contents=json.dumps(numbers)
path.write_text(contents)


from pathlib import Path
import json
path=Path('json.file\ fav_number.json')
content=path.read_text()
number=json.loads(content)
for number_single in number:
    print("i know your favourite number are:")
    print(number_single)
    
    
    
from pathlib import Path
import json
username=input("please tell me your name :")
userage=input("please tell me your age :")
userplace=input("please tell me where your live :")
user_info={}
user_info["name"]=username
user_info["age"]=userage
user_info["place"]=userplace
path=Path('txt\infomation.txt')
contents=json.dumps(user_info)
path.write_text(contents)
path=Path('txt\infomation.txt')
comtemts=path.read_text()
information=json.loads(contents)
print("we've acqired your info :")
print(information)






    

