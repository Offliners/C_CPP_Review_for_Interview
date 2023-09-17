import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])
    target_lower = int(cfg['target_lower'])
    target_upper = int(cfg['target_upper'])

    nums_length = random.randint(num_lower, num_upper)
    target = random.randint(target_lower, target_upper)

    ans_1 = random.randint(nums_lower, target)
    ans_2 = target - ans_1

    
    while True:
        test_cases = []
        for _ in range(nums_length - 2):
            while True:
                num = random.randint(nums_lower, nums_upper)
                if num != ans_1 or num != ans_2 or num != target:
                    break
            test_cases.append(num)
        
        prevMap = {}
        flag = True
        for i, n in enumerate(test_cases):
            diff = target - n
            if diff in prevMap:
                flag = False
            prevMap[n] = i
        
        if flag:
            break
    
    test_cases.append(ans_1)
    test_cases.append(ans_2)
    random.shuffle(test_cases)
    test_cases.append(target)
    return test_cases

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        nums = []
        for line in f.readlines():
            nums.append(int(line))

        prevMap = {}
        target = nums[-1]

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevMap:
                ans = [prevMap[diff], i]
            prevMap[n] = i
        
    with open(out_path, 'w') as f:
        f.writelines(f'{ans[0]}\n')
        f.writelines(f'{ans[1]}\n')

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