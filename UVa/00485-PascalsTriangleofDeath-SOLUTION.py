a = [0,1,0]

cols = 3
limit = 10 ** 60
finish = False

print("1")

while finish != True:
    b = [0]
    for j in range(1, cols):
        b.append(a[j] + a[j-1])
        y = a[j] + a[j-1]
    b.append(0)
    a = b
    cols = cols + 1
    print(str(a[1]), end='')
    for j in range(2, cols - 1):
        print(" " + str(a[j]), end='')
        
        if a[j] >= limit:
            finish = True
    print("")
