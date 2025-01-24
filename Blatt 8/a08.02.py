def ggT(x, y):
    x,y = abs(x), abs(y) #abs() return the absolute value of a function (distance from 0)
    while y!=0:        #when y reaches null you have the ggtr
        x,y = y, x % y #x siempre tendrá el valor más alto
    return x           #si x<y, entonces x%y == x


with open(r"C:\Users\Startllar\OneDrive\Documentos\UNI STUFF\Prog3000\prog3-c\Blatt 8\ggtbeispiele.txt") as file: #r = raw string(ignores \n, \t, etc)
    for line in file:
        numbers = line.split() #numbers = ["10", "20", "30"]
        a,b, expected_ggtr = map(int, numbers) #map applies a function to each element of a list
        ggt_value = ggT(a, b)

        if ggt_value != expected_ggtr:
            print(f"Expected ggtr between {a} and {b}: {expected_ggtr}") #f = formated string
            print(f"Obtained ggtr: {ggt_value}\n")

def ggT1(*args):
    result = args[0]
    for num in args[1:]:
        result = ggT(result, num)
    return result

print(f"Result: {ggT1(10, 20, 40 ,32, 54, 63)}")

