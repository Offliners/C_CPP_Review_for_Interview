import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])

    node_len = random.randint(node_lower, node_upper) // 2
    
    test_case = []
    for _ in range(node_len):
        test_case.append(random.randint(value_lower, value_upper))
    
    if random.random() < float(cfg['prob_palindrome']):
        test_case += test_case[::-1]
    else:
        for _ in range(node_len + 1, node_len * 2):
            test_case.append(random.randint(value_lower, value_upper))

    return test_case

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = list(map(int, f.readlines()[0].strip().split()))

    head = ListNode()
    cur = head
    for n in data:
        temp = ListNode(n)
        cur.next = temp
        cur = cur.next
    
    head = head.next
    fast = head
    slow = head

    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next

    prev = None
    flag = True
    while slow:
        tmp = slow.next
        slow.next = prev
        prev = slow
        slow = tmp

    left, right = head, prev
    while right:
        if left.val != right.val:
            flag = False
            break
        left = left.next
        right = right.next
        
    with open(out_path, 'w') as f:
        if flag:
            f.writelines('true\n')
        else:
            f.writelines('false\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            case = gen()
            case = [str(e) for e in case]
            f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))