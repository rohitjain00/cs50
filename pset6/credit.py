import cs50

number = cs50.get_int()

lista = [int(d) for d in str(number)]

leng = len(lista)

j = 1
suma = 0
while (j < leng):
    temp = lista[j]
    if temp * 2 > 9:
        temp1 = temp * 2
        suma += int( int(temp1%10) + int(temp1/10)  )
    else :
        suma += temp * 2
    j += 2


k = 0
while (k < leng):
    suma += lista[k]
    k += 2

validFlag = 0

if suma % 10 == 0:
    validFlag = 1

if validFlag == 1:
    if (lista[0] == 3 and (lista[1] == 4 or lista[1] == 7)):
        print("AMEX")


    # MasterCard
    if (lista[0] == 5 and (lista[1] >= 1 and lista[1] <= 5)):
    	print("MASTERCARD")


    # Visa
    if lista[0] == 4 :
    	printf("VISA")

else:
    print("INVALID")
