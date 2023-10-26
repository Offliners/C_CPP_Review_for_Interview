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
    if random.random() < float(cfg['prob_cycle']):
        pos = random.randint(0, link_list_len - 2)
    else:
        pos = -1

    test_case = [[pos]]
    data = []
    for _ in range(link_list_len):
        data.append(random.randint(value_lower, value_upper))

    test_case.append(data)
    return test_case

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    pos = int(data[0].strip())
    data = list(map(int, data[1].strip().split()))

    head = ListNode(0)
    temp = head
    cycle_exist = False
    for i in range(len(data)):
        temp.next = ListNode(data[i])

        if i == pos:
            node = temp.next
            cycle_exist = True
        
        temp = temp.next

    if cycle_exist:
        temp.next = node

    slow = head
    fast = head
    find_cycle = False
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            find_cycle = True
            slow = head
            while slow != fast:
                slow = slow.next
                fast = fast.next
            
            temp = head.next
            count = 0
            while temp:
                if temp.next == slow.next:
                    break
                
                count += 1
                temp = temp.next

            break

    with open(out_path, 'w') as f:
        if not find_cycle:
            f.writelines(f'no cycle\n')
        else:
            f.writelines(f'tail connects to node index {count}\n')

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