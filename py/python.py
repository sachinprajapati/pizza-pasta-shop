from datetime import datetime
import sys

s = """Pizzas :-
1. 1 large Pizza = 12 AUD
2. 2 large Pizzas = 22 AUD
3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)

Pastas :-
4. 1 large pasta = 8 AUD
5. 2 large pastas = 15 AUD
6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)

For every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.

7. Cart
8. Payment Information
9. Quit\n"""

def PaymentInfo(pizza, pasta):
    total = gtotal = 0
    print("-"*20+"Payment Information"+"-"*20)
    print("Item\t\tQuantity\t\tprice\t\tTotal")

cart = {"pizza": 0, "pasta": 0, "garlic": 0, "drink": 0, "baklava": 0}

order = {}
total = 0
gb = 0
dr = 0

while True:
    n = input(s)
    try:
        n = int(n)
    except:
        print("Invalid choice")
        continue
        
    if n == 1:
        cart["pizza"] += 1
        print("you have seleted 1 large pizza\nAmount = 12 AUD")
    elif n == 2:
        cart["pizza"] += 2
        print("you have seleted 2 large pizza\nAmount = 22 AUD")
    elif n == 3:
        while True:
            countp = int(input("Enter Number of pizzas\n"))
            if countp < 3:
                print("please enter number of pizzas more than 3")
            else:
                break
        cart["pizza"] += countp
        print("you have seleted {} large pizzas\nAmount = {} AUD".format(countp, 10*countp))
    elif n == 4:
        cart["pasta"] += 1
        print("you have seleted 1 large pasta\nAmount = 8 AUD")
    elif n == 5:
        cart["pasta"] += 2
        print("you have seleted 1 large pastas\nAmount = 15 AUD")
    elif n == 6:
        while True:
            countps = int(input("Enter Number of pastas\n"))
            if countps < 3:
                print("please enter number of pastas more than 3")
            else:
                break
        cart["pasta"] += countps
        print("you have seleted {} large pastas\nAmount = {} AUD".format(countps, 7*countps))
    elif n == 7:
        print("-----------------Cart--------------------\n")
        print("Item Name\t\tQuantity\tPrice\tTotal")
        if cart["pizza"] == 1:
            print("Pizza\t\t\t1\t*\t12\t12")
            total += 12
        elif cart["pizza"] == 2:
            print("Pizza\t\t\t2\t*\t22\t22")
            total += 2
        elif cart["pizza"] >= 3:
            print("Pizza\t\t\t{}\t*\t10\t{}".format(cart['pizza'], cart['pizza']*10))
            total += (3*10)
        if cart["pasta"] == 1:
            print("Pasta\t\t1\t\t*\t8\t8")
            total += 8
        elif cart["pasta"] == 2:
            print("Pasta\t\t\t2\t*\t15\t15")
            total += 15
        elif cart["pasta"] >= 3:
            print("Pasta\t\t\t{}\t*\t7\t{}".format(cart['pasta'], cart['pasta']*7))
            total += (3*7)
        if cart["pizza"] >= 3:
            gb = int(cart['pizza']/3)
            cart['garlic'] = gb
            print("Garlic Bread\t\t{}\t*".format(gb)+"\t"+"0\t0")
        if cart["pasta"] >= 3:
            dr = int(cart['pasta']/3)
            cart['drink'] = dr
            print("Soft Drink 1.25\t\t{}\t*".format(dr)+"\t"+"0\t0")
        if cart["pasta"] >= 3 and cart["pizza"] >= 3:
            print("Baklava\t\t\t{}\t*".format(min(gb, dr))+"\t"+"0\t0")
        print("-"*60+"\nGrand Total is"+"\t"*5+str(total)+" AUD\n")
        if total > 0:
            print("\nEnter :-\n\t1 for Checkout \n\tTo Add More Enter Anything")
            while True:
                po = input()
                try:
                    po = int(po)
                except ValueError:
                    print("please enter valid choice")
                else:
                    if po == 1:
                        name = input("please enter your name\n")
                        mobile = input("please enter your mobile\n")
                        address = input("please eneter your address\n")
                        dt = datetime.now()
                        print("\nCongratulations {} your order has been Confirmed at {} ".format(name, dt.strftime("%d-%m-%Y %I:%M %p")))
                        b = input("\nEnter 1 to Menu else Anything\n")
                        order[dt] = cart
                        for i,j in cart.items():
                            cart[i] = 0
                        total = 0
                        if b != "1":
                            sys.exit()
                        else:
                            break
                    else:
                        print("please enter valid choice")
    elif n == 8:
        print("-"*20+"Payment Option"+"-"*20)
        print("1. Payment For Pizza\n2. Payment For Pasta\n3. Total Payments")
        pay = int(input())
        pizza = pasta = False
        if(pay == 1):
            pizza = True
        elif(pay == 2):
            pasta = True
        else:
            pizza = pasta = True
        PaymentInfo(pizza, pasta)
        break
    elif n == 9:
        sys.exit()
        break
    else:
        print("Invalid Choice")
