import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])

    nums_length = random.randint(num_lower, num_upper) // 2
    single_num = random.randint(nums_lower, nums_upper)

    testcase = [single_num]
    count = 0
    while True:
        data = random.randint(nums_lower, nums_upper)

        if data == single_num:
            continue

        testcase.append(data)
        testcase.append(data)

        count += 1

        if count == nums_length:
            break
    
    return testcase

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        nums = list(map(int, f.readlines()[0].strip().split()))

        res = 0
        for n in nums:
            res = n ^ res
        
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