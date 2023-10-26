import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    s_lower = int(cfg['s_lower'])
    s_upper = int(cfg['s_upper'])

    s_len = random.randint(s_lower, s_upper)

    roman_text = ["I", "V", "X", "L", "C", "D", "M"]
    s = ""
    for _ in range(s_len):
        s += random.choice(roman_text)
    
    return s

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        s = f.readlines()[0].strip()   

    roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
    res = 0
    for i in range(len(s)):
        if i + 1 < len(s) and roman[s[i]] < roman[s[i + 1]]:
            res -= roman[s[i]]
        else:
            res += roman[s[i]]
        
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