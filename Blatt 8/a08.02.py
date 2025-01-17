def ggTr(x, y):
    x,y = abs(x), abs(y) #abs() return the absolute value of a function (distance from 0)
    while y!=0:        #when y reaches nully you have the ggtr
        x,y = y, x % y #x siempre tendrá el valor más alto
    return x           #si x<y, entonces x%y == x

with open("ggtbeispiele.txt", "r") as file:
    content = file.read()
    print(content)


