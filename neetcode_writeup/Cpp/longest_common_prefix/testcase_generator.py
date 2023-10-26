import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    string_lower = int(cfg['string_lower'])
    string_upper = int(cfg['string_upper'])

    prefix = ''
    prob_same_char = float(cfg['prob_of_same_char'])
    string_length = random.randint(string_lower, string_upper // 2)
    for i in range(string_length):
        if random.random() < prob_same_char:
            prefix += chr(random.randint(97, 122))
            prob_same_char *= float(cfg['prob_of_continuous_same_char'])
        else:
            break


    strings_lower = int(cfg['strings_lower'])
    strings_upper = int(cfg['strings_upper'])
    strings_length = random.randint(strings_lower, strings_upper)

    strs = [''] * strings_length
    for i in range(strings_length):
        strs[i] += prefix

        append_char = random.randint(string_lower, string_upper)
        if len(prefix) < append_char:
            for j in range(append_char - len(prefix)):
                strs[i] += chr(random.randint(97, 122))

    return strs

def sol(in_path, out_path):
    strs = []
    with open(in_path, 'r') as f:
        strs = f.readlines()

    for i in range(len(strs)):
        strs[i] = strs[i].strip('\n')

    res = ""
    flag = False
    for i in range(len(strs[0])):
        for s in strs:
            if i == len(s) or s[i] != strs[0][i]:
                flag = True
                break

        if flag:
            break
    
        res += strs[0][i]
        
    with open(out_path, 'w') as f:
        f.writelines(f'{res}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            for case in cases:
                f.writelines(f'{case}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))