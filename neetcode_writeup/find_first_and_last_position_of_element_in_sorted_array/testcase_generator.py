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

    test_case = [[target]]
    data = []
    for _ in range(num_len):
        if random.random() < float(cfg['prob_target_appear']):
            data.append(target)
        else:
            data.append(random.randint(num_lower, num_upper))

    test_case.append(sorted(data))

    return test_case

def binSearch(nums, target, leftBias):
    l, r = 0, len(nums) - 1
    i = -1
    while l <= r:
        m = (l + r) // 2
        if target > nums[m]:
            l = m + 1
        elif target < nums[m]:
            r = m - 1
        else:
            i = m
            if leftBias:
                r = m - 1
            else:
                l = m + 1
    return i


def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    target = int(data[0].strip())
    nums = [int(e) for e in data[1].strip().split()]

    left = binSearch(nums, target, True)
    right = binSearch(nums, target, False)
        
    with open(out_path, 'w') as f:
        f.writelines(f'{left} {right}\n')

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