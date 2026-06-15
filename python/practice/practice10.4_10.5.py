from pathlib import Path
name=input("please tell me what's your name:")
path=Path('guest.txt')
user_info=path.write_text(name)
message=path.read_text()
print(message)




    