import os
import random
import queue
from config import cfg

random.seed(cfg['seed'])


def gen():
    nums_lower = int(cfg['nums_lower'])
    nums_upper = int(cfg['nums_upper'])
    num_lower = int(cfg['num_lower'])
    num_upper = int(cfg['num_upper'])

    num_len = random.randint(nums_lower, nums_upper)

    majority = random.randint(num_lower, num_upper)
    test_case = [majority] * (num_len // 2 + 1)

    remain = num_len - len(test_case)
    for _ in range(remain):
        test_case.append(random.randint(num_lower, num_upper))

    random.shuffle(test_case)
    return test_case


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        nums = list(map(int, f.readlines()[0].strip().split()))

    res, count = 0, 0
    for n in nums:
        if count == 0:
            res = n
        count += (1 if n == res else -1)

    with open(out_path, 'w') as f:
        f.writelines(f'{res}\n')

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