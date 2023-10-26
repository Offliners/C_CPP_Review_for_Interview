import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])
    sep_token = int(cfg['split_token'])

    len_link_list_1 = random.randint(node_lower, node_upper)
    len_link_list_2 = random.randint(node_lower, node_upper)

    test_case = []

    link_list_1 = []
    for i in range(len_link_list_1):
        link_list_1.append(random.randint(value_lower, value_upper))

    test_case.append(sorted(link_list_1))
    test_case.append([sep_token])

    link_list_2 = []
    for _ in range(len_link_list_2):
        link_list_2.append(random.randint(value_lower, value_upper))


    test_case.append(sorted(link_list_2))
    test_case.append([sep_token])

    return test_case

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    data_1 = data[0].strip().split(' ')
    if len(data_1) > 1 or data_1[0] != '':
        data_1 = [int(e) for e in data_1]
        i = 0
        list1 = ListNode()
        val_1 = list1
        for i in range(len(data_1) - 1):
            val_1.val = data_1[i]
            val_1.next = ListNode()
            val_1 = val_1.next
        
        val_1.val = data_1[-1] 
    else:
        data_1 = []
        list1 = None

    data_2 = data[2].strip().split(' ')
    if len(data_2) > 1 or data_2[0] != '':
        data_2 = [int(e) for e in data_2]
        i = 0
        list2 = ListNode()
        val_2 = list2
        for i in range(len(data_2) - 1):
            val_2.val = data_2[i]
            val_2.next = ListNode()
            val_2 = val_2.next
        
        val_2.val = data_2[-1] 
    else:
        data_2 = []
        list2 = None
    
    dummy = node = ListNode()

    while list1 and list2:
        if list1.val < list2.val:
            node.next = list1
            list1 = list1.next
        else:
            node.next = list2
            list2 = list2.next
        node = node.next

    node.next = list1 or list2

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