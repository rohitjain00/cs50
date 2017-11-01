import cs50
import sys

if len(sys.argv) != 2:
    print ("Only one argument accepted")
    exit(1)

print("hello, {}".format(sys.argv[1]))
key = list(sys.argv[1])

all_alphabet = False

for alphabet in key:
    if (alphabet >= 'A' and alphabet <= 'Z') or (alphabet >= 'a' and alphabet <= 'z'):
        all_alphabet = True

if all_alphabet == False:
    print("Only alphabet allowed in Key")
    exit(2)

#to store the key values in int
num_lis = []

for alphabet in key:
    if (alphabet >= 'A' and alphabet <= 'Z'):
        num_lis.append(ord(alphabet)-65)

    if (alphabet >= 'a' and alphabet <= 'z'):
        num_lis.append(ord(alphabet)-97)

print (key)
print(num_lis)

simple_text = cs50.get_string()

lis_simple_text = list(simple_text)
out_lis = []

j = 0
for alphabet in lis_simple_text:
    if (alphabet >= 'A' and alphabet <= 'Z'):

        if j >= len(sys.argv[1]):
            j = 0


        if (ord(alphabet) + num_lis[j]) > ord('Z'):
            alphabet = chr(ord(alphabet) - 26)

        out_lis.append(chr(ord(alphabet) + num_lis[j] ) )

        j += 1


    if (alphabet >= 'a' and alphabet <= 'z'):

        if j >= len(sys.argv[1]):
            j = 0

        if ord(alphabet) + num_lis[j] > ord('z'):
            alphabet = chr(ord(alphabet) - 26)

        out_lis.append(chr(ord(alphabet) + num_lis[j] ) )
        j += 1

    else:
        out_lis.append(alphabet)
crypt_text =  ''.join(out_lis)
print (crypt_text)

