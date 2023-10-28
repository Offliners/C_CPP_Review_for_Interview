import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    n_lower = int(cfg['n_lower'])
    n_upper = int(cfg['n_upper'])

    return random.randint(n_lower, n_upper)

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        n = int(f.readlines()[0].strip())

    stack = []
    res = []

    def backtrack(openN, closedN):
        if openN == closedN == n:
            res.append("".join(stack))
            return

        if openN < n:
            stack.append("(")
            backtrack(openN + 1, closedN)
            stack.pop()
        if closedN < openN:
            stack.append(")")
            backtrack(openN, closedN + 1)
            stack.pop()

    backtrack(0, 0)

    with open(out_path, 'w') as f:
        for r in res:
            f.writelines(f'{"".join(r)}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            case = gen()
            f.writelines(f'{case}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))