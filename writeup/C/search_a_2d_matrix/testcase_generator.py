import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    m_lower = int(cfg['m_lower'])
    m_upper = int(cfg['m_upper'])
    n_lower = int(cfg['n_lower'])
    n_upper = int(cfg['n_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])
    target_lower = int(cfg['target_lower'])
    target_upper = int(cfg['target_upper'])

    m = random.randint(m_lower, m_upper)
    n = random.randint(n_lower, n_upper)
    target = random.randint(target_lower, target_upper)
    
    data = random.sample(list(range(value_lower, target)) + list(range(target + 1, value_upper)), n * m)
    if random.random() < float(cfg['prob_target']):
        data[-1] = target
    
    random.shuffle(data)

    mat = [[target]]
    mat.append([m, n])
    data = sorted(data)
    mat.append([data[i : i + n] for i in range(0, len(data), n)])
    
    return mat

def sol(in_path, out_path):
    matrix = []
    with open(in_path, 'r') as f:
        data = f.readlines()

        target = int(data[0].strip())
        matrix = []
        for row in data[2:]:
            matrix.append([int(e) for e in row.split()])

    ROWS, COLS = len(matrix), len(matrix[0])

    top, bot = 0, ROWS - 1
    while top <= bot:
        row = (top + bot) // 2
        if target > matrix[row][-1]:
            top = row + 1
        elif target < matrix[row][0]:
            bot = row - 1
        else:
            break

    flag = False
    if top <= bot:
        row = (top + bot) // 2
        l, r = 0, COLS - 1
        while l <= r:
            m = (l + r) // 2
            if target > matrix[row][m]:
                l = m + 1
            elif target < matrix[row][m]:
                r = m - 1
            else:
                flag = True
                break
        
    with open(out_path, 'w') as f:
        if flag:
            f.writelines("true\n")
        else:
            f.writelines("false\n")

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            f.writelines(f'{cases[0][0]}\n')
            mn = [str(e) for e in cases[1]]
            f.writelines(f'{" ".join(mn)}\n')
            for mat in cases[2:]:
                for row in mat:
                    data = [str(e) for e in row]
                    f.writelines(f'{" ".join(data)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))