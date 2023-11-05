import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])
    k_lower = int(cfg['k_lower'])
    k_upper = int(cfg['k_upper'])

    k = random.randint(k_lower, k_upper)
    node_len = random.randint(node_lower, node_upper)
    test_case = [[k]]
    data = []
    for _ in range(node_len):
        data.append(random.randint(value_lower, value_upper))

    test_case.append(data)
    return test_case


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        data = f.readlines()
        k = int(data[0].strip())
        nums = list(map(int, data[1].strip().split()))

    head = ListNode()
    cur = head
    for n in nums:
        temp = ListNode(n)
        cur.next = temp
        cur = cur.next
        
    head = head.next 
    if not head or not head.next or k == 0:
        new_head = head
    else:
        old_head = head

        curr, size = head, 0
        while curr:
            curr, size = curr.next, size + 1

        if k % size != 0:
            k %= size
            slow = fast = head
            while fast and fast.next:
                if k <= 0:
                    slow = slow.next
                fast = fast.next
                k -= 1

            new_tail, new_head, old_tail = slow, slow.next, fast
            new_tail.next, old_tail.next = None, old_head
        else:
            new_head = head
        
    ans = []
    while new_head:
        ans.append(new_head.val)
        new_head = new_head.next
        
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
                case = [str(e) for e in case]
                f.writelines(f'{" ".join(case)}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))