import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])

    num = random.randint(num_lower, num_upper)
    
    return num

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        x = int(f.readlines()[0])

        flag = True
        if x < 0:
            flag = False
        else:   
            div = 1
            while x >= 10 * div:
                div *= 10
                
            while x:
                right = x % 10
                left = x // div
                
                if left != right:
                    flag = False
                    break
                
                x = (x % div) // 10
                div = div / 100

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