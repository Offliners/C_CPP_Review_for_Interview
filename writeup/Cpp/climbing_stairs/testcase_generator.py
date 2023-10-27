import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    n_lower = int(cfg['n_lower'])
    n_upper = int(cfg['n_upper'])

    return random.randint(n_lower, n_upper)

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        n = int(f.readlines()[0].strip())

    if n <= 3:
        n2 = n
    else:
        n1, n2 = 2, 3

        for _ in range(4, n + 1):
            temp = n1 + n2
            n1 = n2
            n2 = temp
        
    with open(out_path, 'w') as f:
        f.writelines(f'{n2}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            case = gen()
            f.writelines(f'{case}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))