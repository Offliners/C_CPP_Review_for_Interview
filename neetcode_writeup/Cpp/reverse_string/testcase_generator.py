import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    s_lower = int(cfg['s_lower'])
    s_upper = int(cfg['s_upper'])

    s_len = random.randint(s_lower, s_upper)

    s = []
    for _ in range(s_len):
        s.append(chr(random.randint(32, 126)))

    return s

def sol(in_path, out_path):
    matrix = []
    with open(in_path, 'r') as f:
        s = f.readlines()[0].strip().split()  

    l = 0
    r = len(s) - 1
    while l < r:
        s[l],s[r] = s[r],s[l]
        l += 1
        r -= 1
        
    with open(out_path, 'w') as f:
        f.writelines(f'{" ".join(s)}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            case = gen()
            case = [str(e) for e in case]
            f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))