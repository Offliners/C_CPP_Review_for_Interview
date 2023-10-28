import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    val_lower = int(cfg['val_lower'])
    val_upper = int(cfg['val_upper'])

    node_length = random.randint(node_lower, node_upper)
    n = random.randint(node_lower, node_length)

    test_cases = [[n]]
    data = []
    for _ in range(node_length):
        data.append(random.randint(val_lower, val_upper))
    
    test_cases.append(data)
    return test_cases

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        n = int(data[0].strip())
        nums = list(map(int, data[1].strip().split()))

        head = ListNode()
        cur = head
        for i in nums:
            temp = ListNode(i)
            cur.next = temp
            cur = cur.next
    
    head = head.next
    dummy = ListNode(0, head)
    left = dummy
    right = head

    while n > 0:
        right = right.next
        n -= 1

    while right:
        left = left.next
        right = right.next

    left.next = left.next.next

    ans = []
    temp = dummy.next
    while temp:
        ans.append(temp.val)
        temp = temp.next
        
    with open(out_path, 'w') as f:
        ans = [str(e) for e  in ans]
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