def dreh(lst):
    """
    Dreht die gegebene Liste rekursiv um.
    Parameter:
    lst (list): Die Liste, die umgedreht werden soll.
    Rückgabewert:
    list: Eine neue Liste mit umgedrehten Elementen.
    """
    # Abbruchkriterium: Leere Liste
    if not lst:
        return []
    # Rekursiver Schritt: Rest umdrehen und das erste Element anhängen
    return dreh(lst[1:]) + [lst[0]]

# Testen
print(dreh([1, 2, 3]))  # Ausgabe: [3, 2, 1]
print(dreh([]))         # Ausgabe: []
print(dreh([42]))       # Ausgabe: [42]


