def city_country(city,country):
    full_message=f"{city}, {country}"
    return full_message.title()

information=city_country('santiago','chile')
print(information)
information=city_country('lima','peru') 
print(information)



def make_album(singername,albumtitle):
    information={'singername':singername,'albumtitle':albumtitle}
    return information

album1=make_album('taylor swift','lover')
print(album1)  
album2=make_album('ed sheeran','divide')
print(album2)



def make_album(singername,albumtitle,singsnumber=False):
    information={'singername':singername,'albumtitle':albumtitle,}
    if singsnumber:
        information['singsnumber']=singsnumber
    return information

album1=make_album('taylor swift','lover',10)
print(album1)  
album2=make_album('ed sheeran','divide')    
print(album2)



def make_album(singername,albumtitle,):
    information={'singer_name':singername,'album_title':albumtitle,}
    return information

while True:
    print('enter quit to one of the blank to stop')
    
    s_name=input("please tell the singer's name :")
    if s_name=='quit':
        break
    a_title=input("please tell the album's title :") 
    if a_title=='quit':
        break
    
    album=make_album(s_name,a_title)
    print(album)


