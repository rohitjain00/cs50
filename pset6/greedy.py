import cs50


money = cs50.get_float()

exchange = 0

while (money >= 0.25):
    money -= 0.25
    exchange += 1
    print ("{}".format(money))

while (money >= 0.10):
    money -= 0.10
    exchange += 1
    print ("{}".format(money))


while (money >= 0.05):
    money -= 0.05
    exchange += 1
    print ("{}".format(money))


while (money >= 0.009999999):
    money -= 0.01
    exchange += 1
    print ("{}".format(money))


print ("{}".format(exchange))