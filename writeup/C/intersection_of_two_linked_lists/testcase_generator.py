import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    node_lower = int(cfg['node_lower'])
    node_upper = int(cfg['node_upper'])
    value_lower = int(cfg['value_lower'])
    value_upper = int(cfg['value_upper'])

    link_list_A_len = random.randint(node_lower, node_upper)
    link_list_B_len = random.randint(node_lower, node_upper)

    if random.random() < float(cfg['prob_intersection']):
        if link_list_A_len > link_list_B_len:
            skipB = random.randint(node_lower, link_list_B_len)
            intersection_len = link_list_B_len - skipB
            skipA = link_list_A_len - intersection_len
        else:
            skipA = random.randint(node_lower, link_list_A_len)
            intersection_len = link_list_A_len - skipA
            skipB = link_list_B_len - intersection_len

        intersection_list = [random.randint(value_lower, value_upper) for _ in range(intersection_len)]
        A = [random.randint(value_lower, value_upper) for _ in range(skipA)]
        A += intersection_list
        B = [random.randint(value_lower, value_upper) for _ in range(skipB)]
        B += intersection_list
    else:
        skipA = link_list_A_len
        skipB = link_list_B_len

        A = [random.randint(value_lower, value_upper) for _ in range(skipA)]
        B = [random.randint(value_lower, value_upper) for _ in range(skipB)]

    test_case = [[skipA], [len(A)], A, [skipB], [len(B)], B]

    return test_case

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def sol(in_path, out_path):
    data = []
    with open(in_path, 'r') as f:
        data = f.readlines()

    skipA = int(data[0].strip())
    dataA = list(map(int, data[2].strip().split()))
    headA = ListNode(0)
    cur = headA
    for i in range(len(dataA)):
        temp = ListNode(dataA[i])
        cur.next = temp
        cur = cur.next

        if i == skipA:
            intersection_node = temp
    
    headA = headA.next

    skipB = int(data[3].strip())
    dataB = list(map(int, data[5].strip().split()))
    headB = ListNode(0)
    cur = headB
    for i in range(len(dataB)):
        temp = ListNode(dataB[i])
        cur.next = temp
        cur = cur.next

        if i == skipB:
            cur.next = intersection_node
            break

    headB = headB.next

    l1, l2 = headA, headB
    while l1 != l2:
        l1 = l1.next if l1 else headB
        l2 = l2.next if l2 else headA

    with open(out_path, 'w') as f:
        if l1:
            f.writelines(f'Intersected at \'{l1.val}\'\n')
        else:
            f.writelines(f'No intersection\n')

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