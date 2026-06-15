showmessage=["Hello Python world!","Hello Python Crash Course world!"]
def show_message(sentence):
    print(sentence)
for message in showmessage:
    snetence=message
    show_message(snetence)


def show_message(message):
    for message in showmessage:
        print(message)
showmessage=["Hello Python world!","Hello Python Crash Course world!"]
show_message(message)

showmessage=["Hello Python world!","Hello Python Crash Course world!"]
showmessage.reverse()
sent_messages=[]
def send_message(sentence):
    while showmessage:
        sentence=showmessage.pop()
        print(sentence)
        sent_messages.append(sentence)
for message in showmessage:
    sentence=message
    send_message(sentence)
print(showmessage)
print(sent_messages) 

showmessage=["Hello Python world!","Hello Python Crash Course world!"]
show_message=showmessage[:]
sent_messages=[]
def send_message(sentence):
    while show_message:
        sentence=show_message.pop()
        print(sentence)
        sent_messages.append(sentence)
for message in showmessage:
    sentence=message
    send_message(sentence)
print(showmessage)
print(show_message)
print(sent_messages) 

      
