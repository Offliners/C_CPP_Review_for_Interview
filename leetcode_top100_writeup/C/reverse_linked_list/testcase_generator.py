import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])

    len_test_case = random.randint(node_lower, node_upper)

    test_case = [[len_test_case]]
    data = []
    for _ in range(len_test_case):
        data.append(random.randint(value_lower, value_upper))

    test_case.append(data)
    return test_case

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    data = data[1].split(' ')
    data = [int(e) for e in data] 

    i = 0
    head = ListNode()
    temp = head
    for i in range(len(data) - 1):
        temp.val = data[i]
        temp.next = ListNode()
        temp = temp.next
    
    temp.val = data[-1]

    prev, curr = None, head
    while curr:
        temp = curr.next
        curr.next = prev
        prev = curr
        curr = temp
    
    res = []
    ans = ListNode()
    ans = prev
    while ans:
        res.append(ans.val)
        ans = ans.next

    with open(out_path, 'w') as f:
        res = [str(e) for e in res]
        f.writelines(f'{" ".join(res)}\n')

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