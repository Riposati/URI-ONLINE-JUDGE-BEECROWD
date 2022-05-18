t = int(input())

while t > 0:

    v = input()
    v2 = v.split()

    a = int(v2[0])
    b = int(v2[1])

    l2 = [[] for _ in range(a)]

    v3 = input()
    v4 = v3.split()

    for i in range(0,b):
        x = int(v4[i])
        funcao = x % a
        l2[funcao].append(x)

    for i in range(0,a):
        if len(l2[i]) > 0:
            aux = l2[i]
            print("{} -> ".format(i), end='')
            for j in range(0, len(aux)):
                print("{} -> ".format(aux[j]), end='')
            print("\\", end='')
        else:
            print("{} -> \\".format(i), end='')
        print()
    if t > 1:
        print()
    t -= 1