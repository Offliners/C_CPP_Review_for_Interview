import os
import random
import math
from config import cfg

random.seed(cfg['seed'])

def gen():
    piles_lower = int(cfg['piles_lower'])
    piles_upper = int(cfg['piles_upper'])
    h_upper = int(cfg['h_upper'])
    pile_lower = int(cfg['pile_lower'])
    pile_upper = int(cfg['pile_upper'])


    len_piles = random.randint(piles_lower, piles_upper)

    h = random.randint(len_piles, h_upper)
    test_case = [[h]]

    data = []
    for _ in range(len_piles):
        data.append(random.randint(pile_lower, pile_upper))

    test_case.append(data)

    return test_case


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()

        h = int(data[0].strip())
        piles = list(map(int, data[1].strip().split()))

    l, r = 1, max(piles)
    res = r

    while l <= r:
        k = (l + r) // 2

        totalTime = 0
        for p in piles:
            totalTime += math.ceil(float(p) / k)
        if totalTime <= h:
            res = k
            r = k - 1
        else:
            l = k + 1
        
    with open(out_path, 'w') as f:
        f.writelines(f'{res}\n')

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