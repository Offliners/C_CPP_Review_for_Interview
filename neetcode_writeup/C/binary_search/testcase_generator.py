import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    target_lower = int(cfg['target_lower'])
    target_upper = int(cfg['target_upper'])

    num_len = random.randint(nums_lower, nums_upper)
    target = random.randint(target_lower, target_upper)

    test_case = [[target], [num_len]]
    data = random.sample(range(num_lower, num_upper), num_len)

    test_case.append(sorted(data))

    return test_case

def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    target = int(data[0].strip())
    data_len = int(data[1].strip())
    nums = [int(e) for e in data[2].strip().split()]

    l, r = 0, len(nums) - 1
    ans = -1
    while l <= r:
        m = l + ((r - l) // 2)
        if nums[m] > target:
            r = m - 1
        elif nums[m] < target:
            l = m + 1
        else:
            ans = m
            break
        
    with open(out_path, 'w') as f:
        f.writelines(f'{ans}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            for case in cases:
                data = [str(e) for e in case]
                f.writelines(f'{" ".join(data)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))