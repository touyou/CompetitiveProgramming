crypt = []

crypt.append(0x7a)
crypt.append(0x69)
crypt.append(0x78)
crypt.append(0x6e)
crypt.append(0x62)
crypt.append(0x6f)
crypt.append(0x7c)
crypt.append(0x6b)
crypt.append(0x77)
crypt.append(0x78)
crypt.append(0x74)
crypt.append(0x38)
crypt.append(0x38)
crypt.append(0x64)

key = 0x19

for c in crypt:
  print(chr(key^c))
