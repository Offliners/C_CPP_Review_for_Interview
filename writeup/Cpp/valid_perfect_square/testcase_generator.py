import os
import random
import collections
from config import cfg

random.seed(cfg['seed'])

def gen():
    n_lower = int(cfg['n_lower'])
    n_upper = int(cfg['n_upper'])
    
    return random.randint(n_lower, n_upper)

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        num = int(f.readlines()[0].strip())

    flag = False
    for i in range(1, num + 1):
        if i * i == num:
            flag = True
            break
        if i * i > num:
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
            case = gen()
            f.writelines(f'{case}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))