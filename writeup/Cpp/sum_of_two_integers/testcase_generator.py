import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    
    a = random.randint(num_lower, num_upper)
    b = random.randint(num_lower, num_upper)
    test_case = [a, b]
    return test_case

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        a, b = map(int, f.readlines()[0].strip().split())  
        
    with open(out_path, 'w') as f:
        f.writelines(f'{a + b}\n')

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