import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    val_lower = int(cfg['val_lower'])
    val_upper = int(cfg['val_upper'])

    tree_length = random.randint(node_lower, node_upper)

    tree = []

    if tree_length == 0:
        tree.append(int(cfg['null_token']))
        return tree

    for i in range(tree_length):
        if random.random() < float(cfg['prob_null']) and i != 0:
            tree.append(int(cfg['null_token']))
        else:
            tree.append(random.randint(val_lower, val_upper))

    return tree

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = list(map(int, f.readlines()[0].strip().split()))

    null_token = int(cfg['null_token'])
    if data[0] != null_token:
        root = TreeNode(val=data[0])
        cur = root
        i = 1
        while i < len(data):
            left_node = TreeNode(data[i])

            if data[i] == null_token:
                left_node = None

            cur.left = left_node
            if i + 1 > len(data) - 1:           
                break

            i += 1
            right_node = TreeNode(data[i])

            if data[i] == null_token:
                right_node = None

            cur.right = right_node

            i += 1
            if cur.left:
                cur = cur.left
            elif cur.right:
                cur = cur.right
            else:
                break
    else:
        root = None

    res, stack = [], []
    cur = root
    while cur or stack:
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        res.append(cur.val)
        cur = cur.right
    
    ans = [str(e) for e in res]
    with open(out_path, 'w') as f:
        f.writelines(f'{" ".join(ans)}\n')

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