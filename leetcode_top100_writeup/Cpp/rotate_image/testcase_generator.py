import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    mat_lower = int(cfg['mat_lower'])
    mat_upper = int(cfg['mat_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])

    mat_size = random.randint(mat_lower, mat_upper)

    mat = []
    for _ in range(mat_size):
        row = []
        for _ in range(mat_size):
            row.append(random.randint(value_lower, value_upper))

        mat.append(row)
    
    return mat

def sol(in_path, out_path):
    matrix = []
    with open(in_path, 'r') as f:
        for line in f.readlines():
            row = line.strip().split()
            matrix.append(row)    

    l, r = 0, len(matrix) - 1
    while l < r:
        for i in range(r - l):
            top, bottom = l, r
            topLeft = matrix[top][l + i]
            matrix[top][l + i] = matrix[bottom - i][l]
            matrix[bottom - i][l] = matrix[bottom][r - i]
            matrix[bottom][r - i] = matrix[top + i][r]
            matrix[top + i][r] = topLeft
        
        r -= 1
        l += 1
        
    with open(out_path, 'w') as f:
        for row in matrix:
            data = [str(e) for e in row]
            f.writelines(f'{" ".join(data)}\n')

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