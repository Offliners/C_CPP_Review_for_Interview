import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])

    link_list_len = random.randint(node_lower, node_upper)

    test_case = []
    for _ in range(link_list_len):
        test_case.append(random.randint(value_lower, value_upper))

    return test_case

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    data = list(map(int, data[0].strip().split()))
    
    head = ListNode(0)
    if len(data) > 1:
        cur = head
        for n in data:
            cur.next = ListNode(n)
            cur = cur.next
    else:
        head.next = None

    head = head.next
    if not head or not head.next:
        return head
    else:
        slow = fast = head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next

    ans = []
    while slow:
        ans.append(slow.val)
        slow = slow.next

    with open(out_path, 'w') as f:
        ans = [str(e) for e in ans]
        f.writelines(f'{" ".join(ans)}\n')

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