import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    n_lower = int(cfg['n_lower'])
    n_upper = int(cfg['n_upper'])
    pick_lower = int(cfg['pick_lower'])

    n = random.randint(n_lower, n_upper)
    p = random.randint(pick_lower, n)
    test_case = [[n], [p]]

    return test_case

def guess(n, p):
    if n == p:
        return 0
    elif n < p:
        return 1
    else:
        return -1

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        n = int(data[0].strip())
        p = int(data[1].strip())

    low = 1
    high = n
    
    while True:
        mid = low + (high - low) // 2
        myGuess = guess(mid, p)
        if myGuess == 1:
            low = mid + 1
        elif myGuess == -1:
            high = mid - 1
        else:
            break

    with open(out_path, 'w') as f:
        f.writelines(f'{mid}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            for case in cases:
                data = [str(e) for e in case]
                f.writelines(f'{" ".join(data)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))