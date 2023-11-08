import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])
    target_lower = int(cfg['num_lower'])
    target_upper = int(cfg['num_upper'])

    data_len = random.randint(nums_lower, nums_upper)
    test_case = [[random.randint(target_lower, target_upper)], [data_len]]

    data = []
    for i in range(data_len):
        data.append(random.randint(num_lower, num_upper))

    if random.random() < float(cfg['prob_target']):
        test_case[0][0] = random.choice(data)

    test_case.append(sorted(data))
    return test_case

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        target = int(data[0])
        nums = list(map(int, data[2].strip().split()))

        low, high = 0, len(nums)
        while low < high:
            mid = low + (high - low) // 2
            if target > nums[mid]:
                low = mid + 1
            else:
                high = mid
        
    with open(out_path, 'w') as f:
        f.writelines(f'{low}\n')

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