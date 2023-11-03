import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])

    node_len = random.randint(node_lower, node_upper)
    test_case = []
    for _ in range(node_len):
        test_case.append(random.randint(value_lower, value_upper))

    return test_case


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeSort(head):
    if not head or not head.next:
        return head
    slow = head
    fast = head.next
    while fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
    head2 = slow.next
    slow.next = None
    h1 = mergeSort(head)
    h2 = mergeSort(head2)
    return merge(h1, h2)
        

def merge(curr1, curr2):
    prev1 = ListNode(0)
    prev1.next = curr1
    record = prev1
    prev2 = ListNode(0)
    prev2.next = curr2
    while True:
        while curr1 and curr2 and curr1.val <= curr2.val:
            prev1 = curr1
            curr1 = curr1.next
        if not curr1:
            prev1.next = curr2
            return record.next
        else:
            prev1.next = curr2
            tmp = curr2.next
            curr2.next = curr1
            prev1 = curr2
            curr2 = tmp
            prev2.next = curr2
            if not curr2:
                return record.next


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
    ans = mergeSort(head)

    ans_arr = []
    while ans:
        ans_arr.append(ans.val)
        ans = ans.next
        
    with open(out_path, 'w') as f:
        ans_arr = [str(e) for e in ans_arr]
        f.writelines(f'{" ".join(ans_arr)}\n')

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