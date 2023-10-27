import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    x_lower = int(cfg['x_lower'])
    x_upper = int(cfg['x_upper'])

    return random.randint(x_lower, x_upper)

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        x = int(f.readlines()[0].strip())
        
    with open(out_path, 'w') as f:
        f.writelines(f'{int(x ** 0.5)}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            case = gen()
            f.writelines(f'{case}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))