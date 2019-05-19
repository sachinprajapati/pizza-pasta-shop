s = """Pizzas :-
1. 1 large Pizza = 12 AUD
2. 2 large Pizzas = 22 AUD
3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)

Pastas :-
4. 1 large pasta = 8 AUD
5. 2 large pastas = 15 AUD
6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)

For every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.

7. Payment Information
8. Quit\n"""

operation = """
1. Add Item and package
2. Show Menu
"""

items = ["pizza", "pasta"]

package = {items[0]: [
                    {"qty": 1, "tprice": 12, "type": "large Pizza"},
                    {"qty": 2, "tprice": 22, "type": "large Pizza"},
                    {"uprice": 10, "minitem": 3, "type": "large Pizza", "offer": {"item": "garlic bread"}}
                    ],
           items[1]: [
                   ]
           }

order = {"pizza": 0, "pasta": 0, "garlic": 0, "drink": 0, "baklava": 0}

menu = []

for i,j in package.items():
    print(i+" :-")
    for l in j:
        menu.append(l)
        if not l.get("offer"):
            print("\t{} {} = {} AUD".format(l["qty"], l["type"], l["tprice"]))
        else:
            print("\toffer")

while True:
    choice = input(operation)
    try:
        choice = int(choice)
    except:
        print("please enter valid choice")
    if choice == 1:
        print("1")
    elif choice == 2:
        n = input(s)
        
