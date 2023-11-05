import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    digits_lower = int(cfg['digits_lower'])
    digits_upper = int(cfg['digits_upper'])
    digit_lower = int(cfg['digit_lower'])
    digit_upper = int(cfg['digit_upper'])

    len_digits = random.randint(digits_lower, digits_upper)

    test_case = [[len_digits]]
    data = []
    for i in range(len_digits):
        if i == 0:
            data.append(random.randint(1, digit_upper))
        else:
            data.append(random.randint(digit_lower, digit_upper))

    test_case.append(data)
    return test_case

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        digits = list(map(int, f.readlines()[1].strip().split()))

    one = 1
    i = 0
    digits = digits[::-1]

    while one:
        if i < len(digits):
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                one = 0
        else:
            digits.append(one)
            one = 0
        i += 1

    with open(out_path, 'w') as f:
        ans = [str(e) for e in digits[::-1]]
        f.writelines(f'{" ".join(ans)}\n')

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