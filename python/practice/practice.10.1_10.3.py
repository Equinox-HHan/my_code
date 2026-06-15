from pathlib import Path
path=Path('learning_py.txt')
message=path.read_text()
print(message)


from pathlib import Path
path=Path('learning_py.txt')
message=path.read_text()
lines=message.splitlines()
for line in lines:
    print(line)
    
    
from pathlib import Path
path=Path('learning_py.txt')
message=path.read_text()
message=message.replace('Python','C++')
print(message)









