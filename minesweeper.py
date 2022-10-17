# line 21줄 제한

matrix = []
col, row = map(int, input().split())
for i in range(row):
    matrix.append(list(input()))
for i in range(row):
    for j in range(col):
        cnt = 0
        if matrix[i][j] != '*':
            for c in range(i - 1, i + 2):
                for r in range(j - 1, j + 2):
                    if c < 0 or r < 0 or c > row - 1 or r > col - 1:
                        r += 1
                        continue
                    if matrix[c][r] == '*':
                        cnt += 1
                    r += 1
                c += 1
            matrix[i][j] = cnt
        print(matrix[i][j], end = '')
        j += 1
    print()
    i += 1