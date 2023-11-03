import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    str_lower = int(cfg['str_lower'])
    str_upper = int(cfg['str_upper'])
    prob_palindrome = float(cfg['prob_palindrome'])


    str_len = random.randint(str_lower, str_upper) // 2
    data = ''
    for _ in range(str_len):
        data += chr(random.randint(32, 127))

    if random.random() < prob_palindrome:
        if str_len % 2 == 0:
            s = data + data[::-1]
        else:
            s = data[:-2] + data[::-1]
    else:
        data_temp = ''
        for _ in range(str_len):
            data_temp += chr(random.randint(32, 127))
        
        if str_len % 2 == 0:
            s = data + data_temp
        else:
            s = data[:-2] + data_temp
        
    return s


def alphanum(c):
    return (
        ord("A") <= ord(c) <= ord("Z")
        or ord("a") <= ord(c) <= ord("z")
        or ord("0") <= ord(c) <= ord("9")
    )


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        s = f.readlines()[0].strip()
    
    flag = True
    l, r = 0, len(s) - 1
    while l < r:
        while l < r and not alphanum(s[l]):
            l += 1
        while l < r and not alphanum(s[r]):
            r -= 1
        if s[l].lower() != s[r].lower():
            flag = False
            break
        l += 1
        r -= 1
        
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
            s = gen()
            f.writelines(f'{s}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))