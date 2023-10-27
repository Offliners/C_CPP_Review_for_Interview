import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    s_lower = int(cfg['s_lower'])
    s_upper = int(cfg['s_upper'])

    s_len = random.randint(s_lower, s_upper)
    if(s_len % 2 == 1):
        s_len += 1

    paraentheses = ['(', ')', '[', ']', '{', '}']
    s = ''
    for i in range(s_len):
        if random.random() < float(cfg['prob_pair']):
            n = random.choice([0, 2, 4])
            s += paraentheses[n]
            s += paraentheses[n + 1]
            i += 1
        else:
            s += random.choice(paraentheses)
    
    return s

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        s = f.readlines()[0].strip()

        Map = {")": "(", "]": "[", "}": "{"}
        stack = []
        flag = True
        flag_1 = False

        for c in s:
            if c not in Map:
                stack.append(c)
                continue
            if not stack or stack[-1] != Map[c]:
                flag = False
                flag_1 = True
                break
            stack.pop()

        if not flag_1:
            if stack:
                flag = False
            else:
                flag = True
        
    with open(out_path, 'w') as f:
        if flag:
            f.writelines('true\n')
        else:
            f.writelines('false\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            f.writelines(f'{cases}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))