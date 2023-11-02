import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])

    num_len = random.randint(nums_lower, nums_upper)

    test_case = list(range(1, num_len + 1))
    disappear_nums = []
    for i in range(num_len):
        if random.random() < float(cfg['prob_number_disappear']):
            disappear_nums.append(i + 1)
            temp = []
            for j in range(1, num_len + 1):
                if j + 1 not in disappear_nums:
                    temp.append(j + 1)
    
            test_case[i] = random.sample(temp, 1)[0]

    random.shuffle(test_case)
    return test_case

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        nums = list(map(int, f.readlines()[0].strip().split()))

    for n in nums:
        i = abs(n) - 1
        nums[i] = -1 * abs(nums[i])

    res = []
    for i, n in enumerate(nums):
        if n > 0:
            res.append(i + 1)

    if len(res) == 1:
        res = [res]
    elif len(res) == 0:
        res = []
        
    with open(out_path, 'w') as f:
        res = [str(e) for e in res]
        f.writelines(f'{" ".join(res)}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            case = gen()
            data = [str(e) for e in case]
            f.writelines(f'{" ".join(data)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))