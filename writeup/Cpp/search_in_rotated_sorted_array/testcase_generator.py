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

    test_cases = [[target]]
    arr = random.sample(list(range(nums_lower, nums_upper)), nums_length)
    arr = sorted(arr)
    k = random.randint(0, len(arr))

    k = -k % len(arr)
    arr = arr[k:] + arr[:k]

    test_cases.append(arr)
    return test_cases

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        target = int(data[0].strip())
        nums = list(map(int, data[1].strip().split()))

    ans = -1    
    l, r = 0, len(nums) - 1
    while l <= r:
        mid = (l + r) // 2
        if target == nums[mid]:
            ans = mid
            break
        
        if nums[l] <= nums[mid]:
            if target > nums[mid] or target < nums[l]:
                l = mid + 1
            else:
                r = mid - 1
        else:
            if target < nums[mid] or target > nums[r]:
                r = mid - 1
            else:
                l = mid + 1
     
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
                case = [str(e) for e in case]
                f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))