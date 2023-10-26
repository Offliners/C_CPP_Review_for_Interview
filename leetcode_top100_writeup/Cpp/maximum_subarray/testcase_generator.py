import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])

    nums_len = random.randint(nums_lower, nums_upper)

    data = []
    for _ in range(nums_len):
        data.append(random.randint(num_lower, num_upper))

    return data

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        nums = list(map(int, f.readlines()[0].strip().split()))

    res = nums[0]
    total = 0
    for n in nums:
        total += n
        res = max(res, total)
        if total < 0:
            total = 0
        
    with open(out_path, 'w') as f:
        f.writelines(f'{res}\n')

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