import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])

    num_row = random.randint(num_lower, num_upper)
    
    return num_row

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        numRows = int(f.readlines()[0])

    ans = []
    if numRows == 1:
        ans.append([1])
    else:
        ans.append([1])
        ans.append([1, 1])
        for i in range(2, numRows):
            deck = [1]
            for j in range(1, i):
                deck.append(ans[i-1][j-1] + ans[i-1][j])
            deck.append(1)
            ans.append(deck)

    with open(out_path, 'w') as f:
        for i in ans:
            i = [str(e) for e in i]
            data = " ".join(i)
            f.writelines(f'{data}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            f.writelines(f'{cases}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))