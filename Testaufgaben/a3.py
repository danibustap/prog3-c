def isHawaiian(w):
    vokale = "AEIOUaeiou"
    konsonanten = "HKLMNPWhklmnpw'"     
    if not all(c in vokale + konsonanten for c in w):
        return False

    if w[-1] not in vokale:
        return False
    
    for i in range(len(w)-1):
        if w[i] in konsonanten and w[i+1] not in vokale:
            return False

    return True

def extractHi(iterable):
    for str in iterable:
        str_alnum = ''.join(c if c.isalnum() or c =="'" else ' ' for c in str)
        words = str_alnum.split() #divide the string in words (separated by space) instead of chars
        for wort in words:
            if isHawaiian(wort):
                yield wort #yield devuelve un generator 

print(isHawaiian("Humuhumunukunukuapua'a"))

for w in extractHi(["Eine Wahine sagt", "Maika'i no au!"]):
    print(w)


     