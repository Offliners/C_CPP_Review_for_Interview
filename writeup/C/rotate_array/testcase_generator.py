import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    k_lower = int(cfg['k_lower'])
    k_upper = int(cfg['k_upper'])

    nums_len = random.randint(nums_lower, nums_upper)

    k = random.randint(k_lower, k_upper)
    testcase = [[k], [nums_len]]
    data = []
    for _ in range(nums_len):
        data.append(random.randint(num_lower, num_upper))
    
    testcase.append(data)
    return testcase

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        k = int(data[0].strip())
        nums = list(map(int, data[2].strip().split()))

    k = k % len(nums)
    l, r = 0, len(nums) - 1
    while l < r:
        nums[l], nums[r] = nums[r], nums[l]
        l, r = l + 1, r - 1
        
    l, r = 0, k - 1
    while l < r:
        nums[l], nums[r] = nums[r], nums[l]
        l, r = l + 1, r - 1
        
    l, r = k, len(nums) - 1
    while l < r:
        nums[l], nums[r] = nums[r], nums[l]
        l, r = l + 1, r - 1
        
    with open(out_path, 'w') as f:
        data = [str(e) for e in nums]
        f.writelines(f'{" ".join(data)}\n')

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