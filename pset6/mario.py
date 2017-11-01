import cs50

a = cs50.get_int()

a += 1
j = a-2
k = 2


for i in range(1,a):
    print (" " * j + "#" * k + "  " + "#" * k)
    k += 1
    j -= 1
