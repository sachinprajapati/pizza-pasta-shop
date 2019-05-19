while True:
    n = int(input(s))
    if n == 1:
        order["pizza"] += 1
        print("you have seleted 1 large pizza\nAmount = 12 AUD")
    elif n == 2:
        order["pizza"] += 2
        print("you have seleted 2 large pizza\nAmount = 22 AUD")
    elif n == 3:
        while True:
            countp = int(input("Enter Number of pizzas\n"))
            if countp < 3:
                print("please enter number of pizzas more than 3")
            else:
                break
        order["pizza"] += countp
        print("you have seleted {} large pizzas\nAmount = {} AUD".format(countp, 10*countp))
    elif n == 4:
        order["pasta"] += 1
        print("you have seleted 1 large pasta\nAmount = 8 AUD")
    elif n == 5:
        order["pasta"] += 2
        print("you have seleted 1 large pastas\nAmount = 15 AUD")
    elif n == 6:
        while True:
            countps = int(input("Enter Number of pastas\n"))
            if countps < 3:
                print("please enter number of pastas more than 3")
            else:
                break
        order["pasta"] += countps
        print("you have seleted {} large pastas\nAmount = {} AUD".format(countps, 7*countps))
    elif n == 7:
        print("payment information")
        print("Item Name\tQuantity\tPrice\tTotal")
        if order["pizza"] == 1:
            print("Pizza\t\t1\t*\t12\t12")
        elif order["pizza"] == 2:
            print("Pizza\t\t2\t*\t22\t22")
    elif n == 8:
        print("thanks for using")
        break
    else:
        print("Invalid Choice")

