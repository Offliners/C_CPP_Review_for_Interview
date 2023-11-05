import os
import random
import queue
from config import cfg

random.seed(cfg['seed'])

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def generate_random_binary_tree(size, lower, upper): 
    if size == 0: 
        return None

    left_size = random.randint(0, size - 1) 
    right_size = size - 1 - left_size 

    left_subtree = generate_random_binary_tree(left_size, lower, upper) 
    right_subtree = generate_random_binary_tree(right_size, lower, upper) 

    root = TreeNode(random.randint(lower, upper)) 

    root.left = left_subtree 
    root.right = right_subtree 

    return root 


def flatten_tree(data, node, null_token, level=0): 
    if node is not None:
        data.append(node.val)
        flatten_tree(data, node.right, null_token, level + 1) 
        flatten_tree(data, node.left, null_token, level + 1) 
    else:
        data.append(null_token)


def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    val_lower = int(cfg['val_lower'])
    val_upper = int(cfg['val_upper'])

    tree_length = random.randint(node_lower, node_upper)

    root = generate_random_binary_tree(tree_length, val_lower, val_upper)
    test_case = []
    flatten_tree(test_case, root, int(cfg['null_token']))

    return test_case


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = list(map(int, f.readlines()[0].strip().split()))

    null_token = int(cfg['null_token'])
    if data[0] != null_token:
        q = queue.Queue()
        root = TreeNode(data[0])
        cur = root
        i = 1
        while i < len(data):
            if data[i] != null_token:
                left_node = TreeNode(data[i])
                cur.left = left_node
                q.put(left_node)
            
            if i + 1 >= len(data) - 1:
                break

            i += 1
            if data[i] != null_token:
                right_node = TreeNode(data[i])
                cur.right = right_node
                q.put(right_node)
            
            cur = q.get()
            i += 1
    else:
        root = None

    stack = [root]
    visit = [False]
    res = []

    while stack:
        cur, v = stack.pop(), visit.pop()
        if cur:
            if v:
                res.append(cur.val)
            else:
                stack.append(cur)
                visit.append(True)
                stack.append(cur.right)
                visit.append(False)
                stack.append(cur.left)
                visit.append(False)
    
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