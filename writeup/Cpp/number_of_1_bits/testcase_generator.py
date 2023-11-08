import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    string_len = int(cfg['string_len'])

    test_case = ''
    for _ in range(string_len):
        if random.random() < 0.5:
            test_case += '1'
        else:
            test_case += '0'

    return test_case


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        n = int(f.readlines()[0].strip(), 32)

    res = 0
    while n:
        n &= n - 1
        res += 1
        
    with open(out_path, 'w') as f:
        f.writelines(f'{res}\n')


if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            case = gen()
            f.writelines(f'{case}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))