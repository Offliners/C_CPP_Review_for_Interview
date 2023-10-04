import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    prices_lower = int(cfg['prices_lower'])
    prices_upper = int(cfg['prices_upper'])
    price_lower = int(cfg['price_lower'])
    price_upper = int(cfg['price_upper'])

    prices_len = random.randint(prices_lower, prices_upper)
    print(prices_len)

    test_case = []
    for _ in range(prices_len):
        test_case.append(random.randint(price_lower, price_upper))

    return test_case

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        prices = list(map(int, f.readlines()[0].strip().split()))

    res = 0
    lowest = prices[0]
    for price in prices:
        if price < lowest:
            lowest = price
        res = max(res, price - lowest)
        
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