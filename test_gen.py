n = 10000
with open('test.txt', 'w') as fout:
    fout.write(str(n) + " " + str(n // 2) + '\n')
    for i in range(n // 2):
        fout.write('{} {}'.format(n, n) + '\n')

