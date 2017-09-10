ac=[]
na=[]
add=[]
ba=[]
n=int(input("Enter the no. of candidates list u want:"))
for i in range(n):
    Ac = raw_input("Enter account no.")
    name=raw_input("Enter name-")
    address=raw_input("Enter address")
    balance=float(input("Enter the balance"))
    ac=ac+[Ac]
    na=na+[name]
    add=add+[address]
    ba=ba+[balance]
if balance < 10000:
    print"Account no.", (Account_number)
    print"Name:",(name)
    print"Address:",(address)
print min(ba)
