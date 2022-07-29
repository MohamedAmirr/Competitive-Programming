T = 1
T = int(input())
mirror = {'A': 1, 'H': 2, 'I': 3, 'M': 4, 'O': 5, 'T': 6, 'U': 7, 'V': 8, 'W': 9, 'X': 10, 'Y': 11}
l = ['A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y']
while T:
    ans = ""
    k = int(1)
    s = "hoba"
    k, s = input().split()
    cnt = 0
    kam = 1
    for i in s[::-1]:
        cnt = cnt + (kam * mirror[i])
        kam = kam * 11
    kk = int(int(cnt) + int(k))
    while kk>0:
        kk = kk - 1
        ans = ans + l[int(kk % 11)]
        kk = kk // 11
    for i in ans[::-1]:
        print (i,end="")
    print()
    T = T - 1
