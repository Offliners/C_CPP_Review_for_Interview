import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    string_lower = int(cfg['string_lower'])
    string_upper = int(cfg['string_upper'])

    string_length = random.randint(string_lower, string_upper)

    s = ''
    for i in range(string_length):
        if random.random() < float(cfg['prob_of_space']):
            s += ' '
        else:
            s += chr(random.randint(97, 122))

    return s

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        ans = len(f.readlines()[0].split()[-1])
        
    with open(out_path, 'w') as f:
        f.writelines(f'{ans}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            f.writelines(f'{cases}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))