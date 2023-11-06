import os
import random
import collections
from config import cfg

random.seed(cfg['seed'])

def gen():
    base  = 3
    side  = base * base

    def pattern(r, c): 
        return (base * (r % base) + r // base + c) % side

    def shuffle(s): 
        return random.sample(s, len(s)) 
    
    rBase = range(base) 
    rows  = [g * base + r for g in shuffle(rBase) for r in shuffle(rBase)] 
    cols  = [g * base + c for g in shuffle(rBase) for c in shuffle(rBase)]
    nums  = shuffle(range(1, base * base + 1))

    board = [[nums[pattern(r, c)] for c in cols] for r in rows]

    squares = side * side
    empties = squares * 3 // 4
    for p in random.sample(range(squares), empties):
        board[p // side][p % side] = '.'
    
    return board

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()

        board = []
        for row in data:
            board.append(row.strip().split())

    cols = collections.defaultdict(set)
    rows = collections.defaultdict(set)
    squares = collections.defaultdict(set)

    flag = True
    for r in range(9):
        for c in range(9):
            if board[r][c] == ".":
                continue
            if (
                board[r][c] in rows[r]
                or board[r][c] in cols[c]
                or board[r][c] in squares[(r // 3, c // 3)]
            ):
                flag = False
                break
            cols[c].add(board[r][c])
            rows[r].add(board[r][c])
            squares[(r // 3, c // 3)].add(board[r][c])
        
        if not flag:
            break
        
    with open(out_path, 'w') as f:
        if flag:
            f.writelines('true\n')
        else:
            f.writelines('false\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            for case in cases:
                case = [str(e) for e in case]
                f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))