import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    coins_lower = int(cfg['coins_lower'])
    coins_upper = int(cfg['coins_upper'])
    coin_lower = int(cfg['coin_lower'])
    coin_upper = int(cfg['coin_upper'])
    amount_lower = int(cfg['amount_lower'])
    amount_upper = int(cfg['amount_upper'])

    coins_length = random.randint(coins_lower, coins_upper)
    amount = random.randint(amount_lower, amount_upper)

    test_cases = [[amount], [coins_length]]
    data = []
    coin_value = [1, 2, 5, 10, 100, 200, 500, 1000, 2000, 5000]
    if coins_length <= len(coin_value):
        data = random.sample(coin_value, coins_length)
    else:
        for _ in range(coins_length - len(coin_value)):
            data.append(random.randint(coin_lower, coin_upper))

    data = sorted(data)
    test_cases.append(data)

    return test_cases

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        amount = int(data[0].strip())
        coins = list(map(int, data[2].strip().split()))
        
    dp = [amount + 1] * (amount + 1)
    dp[0] = 0

    for a in range(1, amount + 1):
        for c in coins:
            if a - c >= 0:
                dp[a] = min(dp[a], 1 + dp[a - c])

    ans = dp[amount] if dp[amount] != amount + 1 else -1
        
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