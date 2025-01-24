def main():
    return 0

def statistik(dateiname):
    from collections import defaultdict
    data = defaultdict(lambda: defaultdict(int)) #lambda is an anonymous function that initiates the default values of plz when they don`t exist yet
     
    with open(dateiname) as file: #with closes the file when the block finishes
        for line in file:
            plz, name, summe = line.strip().split(';')
            data[plz][name] += int(summe) #int() converts the str value to int
            #data = { "65197": { "Meier": 42}}
    for plz in sorted(data): #sorted retorna una lista ordenada por PLZ en orden ascendente
        customers = [f"{name}({total})" for name, total in sorted(data[plz].items())] #list comprehension / items devuelve una tupla de pares (key, value)/sorted(data[plz]) ordena alfabeticamnete por name
        print(f"{plz}: {' '.join(customers)}") #join() une una lista (de strings o iterables) en un solo string colocando el separador entre cada elemento

print(statistik(r"C:\Users\Startllar\OneDrive\Documentos\UNI STUFF\Prog3000\prog3-c\Testaufgaben\bestellungen.txt"))



    

