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
    
    test_cases = sorted(test_cases)
    return test_cases

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        nums = list(map(int, f.readlines()[0].strip().split()))

    L = 1
    for R in range(1, len(nums)):
        if nums[R] != nums[R - 1]:
            nums[L] = nums[R]
            L += 1
        
    with open(out_path, 'w') as f:
        f.writelines(f'{L}\n')
        nums = [str(e) for e in nums[:L]]
        f.writelines(f'{" ".join(nums)}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            case = [str(e) for e in cases]
            f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))