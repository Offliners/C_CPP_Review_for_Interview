import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])

    nums_length = random.randint(num_lower, num_upper)

    test_cases = []
    for _ in range(nums_length):
        test_cases.append(random.randint(nums_lower, nums_upper))
    
    return test_cases

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        nums = []
        for line in f.readlines():
            nums.append(int(line))
        
        rightMax = -1
        for i in range(len(nums) -1, -1, -1):
            newMax = max(rightMax, nums[i])
            nums[i] = rightMax
            rightMax = newMax
        
    with open(out_path, 'w') as f:
        for num in nums:
            f.writelines(f'{num}\n')

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