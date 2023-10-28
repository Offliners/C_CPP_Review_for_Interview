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

    test_cases = [[nums_length]]
    data = []
    for _ in range(nums_length):
        data.append(random.randint(nums_lower, nums_upper))
    
    test_cases.append(data)
    return test_cases

def sol(in_path, out_path):
    flag = False
    with open(in_path, 'r') as f:
        nums = list(map(int, f.readlines()[1].strip().split()))
        
        nums.sort()
        for i in range(len(nums) - 1):
            if nums[i] == nums[i+1]:
                flag = True
                break
        
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
            for case in cases:
                case = [str(e) for e in case]
                f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))