import os
import random
from config import cfg

NUM_ENGLISH_LETTER = 26
random.seed(cfg['seed'])

def gen():
    s_lower = int(cfg['s_lower'])
    s_upper = int(cfg['s_upper'])

    t_lower = int(cfg['t_lower'])
    t_upper = int(cfg['t_upper'])

    s_len = random.randint(s_lower, s_upper)
    t_len = random.randint(s_len, t_upper)

    s = ""
    for i in range(s_len):
        s += chr(97 + random.randint(0, NUM_ENGLISH_LETTER - 1))

    t = ""
    for i in range(t_len):
        t += chr(97 + random.randint(0, NUM_ENGLISH_LETTER - 1))
    
    return s, t

def sol(in_path, out_path):
    flag = False
    with open(in_path, 'r') as f:
        s, t = f.read().splitlines()
        
        i, j = 0, 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1
            j += 1
        
        if i == len(s):
            flag = True
        
    with open(out_path, 'w') as f:
        if flag:
            f.writelines('true')
        else:
            f.writelines('false')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            s, t = gen()
            
            f.writelines(f'{s}\n')
            f.writelines(f'{t}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))