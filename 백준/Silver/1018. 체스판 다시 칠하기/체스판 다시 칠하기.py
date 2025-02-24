n, m = map(int, input().split())
board = []
for i in range(n):
    board.append(input())
board_string = ["WBWBWBWB", "BWBWBWBW"]

min_cnt = n*m
for i in range(n-8+1):
    for j in range(m-8+1):
        w_sum = 0
        b_sum = 0
        for n_i in range(8):
            for n_j in range(8):
                if board[i + n_i][j + n_j] != board_string[0][n_j]:
                    w_sum += 1
                if board[i + n_i][j + n_j] != board_string[1][n_j]:
                    b_sum += 1
            tmp = board_string[0]
            board_string[0] = board_string[1]
            board_string[1] = tmp
        if min_cnt > w_sum:
            min_cnt = w_sum
        if min_cnt > b_sum:
            min_cnt = b_sum
print(min_cnt)