import cs50
import sys
import crypt

if len(sys.argv) != 2:
    print("USAGE : python crack.py key")
    exit(1)

poss_char = []

for i in range (65,91):
    poss_char.append(chr(i))

for i in range (97,123):
    poss_char.append(chr(i))

temp_word = []

for i in poss_char:
    if crypt.crypt(i,"50") == sys.argv[1]:
        print(i)
        exit(3)

for i in poss_char:
    for j in poss_char:
        temp_word.append(i)
        temp_word.append(j)

        if crypt.crypt("".join(temp_word),"50") == sys.argv[1]:
            print("".join(temp_word))
            exit(4)


for i in poss_char:
    for j in poss_char:
        for k in poss_char:
            temp_word.append(i)
            temp_word.append(j)
            temp_word.append(k)

            if crypt.crypt("".join(temp_word),"50") == sys.argv[1]:
                print("".join(temp_word))
                exit(4)
            temp_word = []



for i in poss_char:
    for j in poss_char:
        for k in poss_char:
            for l in poss_char:

                temp_word.append(i)
                temp_word.append(j)
                temp_word.append(k)
                temp_word.append(l)

                if crypt.crypt("".join(temp_word),"50") == sys.argv[1]:
                    print("".join(temp_word))
                    exit(4)
                temp_word = []





