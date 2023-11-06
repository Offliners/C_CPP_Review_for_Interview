import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])

    len_link_list_1 = random.randint(node_lower, node_upper)
    len_link_list_2 = random.randint(node_lower, node_upper)

    test_case = []

    link_list_1 = []
    for i in range(len_link_list_1):
        if i != len_link_list_1 - 1:
            link_list_1.append(random.randint(value_lower, value_upper))
        else:
            link_list_1.append(random.randint(1, value_upper))

    test_case.append(link_list_1)

    link_list_2 = []
    for _ in range(len_link_list_2):
        if i != len_link_list_2 - 1:
            link_list_2.append(random.randint(value_lower, value_upper))
        else:
            link_list_2.append(random.randint(1, value_upper))

    test_case.append(link_list_2)

    return test_case

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    data_1 = [int(e) for e in data[0].split(' ')] 
    l1 = ListNode(0)
    cur = l1
    for i in data_1:
        cur.next = ListNode(i)
        cur = cur.next

    l1 = l1.next

    data_2 = [int(e) for e in data[1].split(' ')] 
    l2 = ListNode(0)
    cur = l2
    for i in data_2:
        cur.next = ListNode(i)
        cur = cur.next

    l2 = l2.next
    
    dummy = ListNode()
    cur = dummy
    carry = 0
    while l1 or l2 or carry:
        v1 = l1.val if l1 else 0
        v2 = l2.val if l2 else 0

        val = v1 + v2 + carry
        carry = val // 10
        val = val % 10
        cur.next = ListNode(val)

        cur = cur.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None

    res = []
    ans = ListNode()
    ans = dummy.next
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