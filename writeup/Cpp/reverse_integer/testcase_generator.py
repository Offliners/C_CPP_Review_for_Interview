import os
import math
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])

    num = random.randint(num_lower, num_upper)
    
    return num

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        x = int(f.readlines()[0])

    MIN = -2147483648
    MAX = 2147483647

    res = 0
    while x:
        digit = int(math.fmod(x, 10))
        x = int(x / 10)

        if res > MAX // 10 or (res == MAX // 10 and digit > MAX % 10):
            res = 0
            break
        if res < MIN // 10 or (res == MIN // 10 and digit < MIN % 10):
            res = 0
            break
        res = (res * 10) + digit

    with open(out_path, 'w') as f:
        f.writelines(f'{res}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            f.writelines(f'{cases}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))