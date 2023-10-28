import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])
    val_lower = int(cfg['val_lower'])
    val_upper = int(cfg['val_upper'])

    nums_length = random.randint(nums_lower, nums_upper)
    val = random.randint(val_lower, val_upper)

    test_cases = [[val], [nums_length]]

    data = []
    for i in range(nums_length):
        data.append(random.randint(num_lower, num_upper))

    test_cases.append(data)
    
    return test_cases

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        val = int(data[0].strip())
        nums = data[2].strip().split(' ')

    if nums:
        nums = [int(e) for e in nums]
    else:
        nums = []

    k = 0
    for i in range(len(nums)):
        if nums[i] != val:
            nums[k] = nums[i]
            k += 1
        
    with open(out_path, 'w') as f:
        f.writelines(f'{k}\n')
        nums = [str(e) for e in nums[:k]]
        f.writelines(f'{" ".join(nums)}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            for case in cases:
                case = [str(e) for e in case]
                f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))