import os
import random
from config import cfg

random.seed(cfg['seed'])

def gen():
    call_lower = int(cfg['call_lower'])
    call_upper = int(cfg['call_upper'])
    val_lower = int(cfg['val_lower'])
    val_upper = int(cfg['val_upper'])

    calls_len = random.randint(call_lower, call_upper)
    calls_list = ['getMin', 'push', 'pop', 'top']

    test_case = []
    top = 0
    for i in range(calls_len):
        if i == 0:
            test_case.append('MinStack')
            continue

        if top != 0:
            cmd = random.sample(['getMin', 'push', 'pop', 'top'], 1)[0]

            if cmd == 'push':
                top += 1
                val = random.randint(val_lower, val_upper)
                test_case.append(f'push {val}')
            elif cmd == 'pop':
                top -= 1
                test_case.append('pop')
            else:
                test_case.append(f'{cmd}')
        else:
            cmd = 'push'
            top += 1
            val = random.randint(val_lower, val_upper)
            test_case.append(f'push {val}')
    
    return test_case


class MinStack:
    def __init__(self):
        self.stack = []
        self.minStack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        val = min(val, self.minStack[-1] if self.minStack else val)
        self.minStack.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.minStack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minStack[-1]


def sol(in_path, out_path):
    with open(in_path, 'r') as f:
        s = MinStack()
        output = []
        for line in f.readlines():
            data = line.strip().split()

            if len(data) == 2:
                s.push(int(data[1]))
                output.append('')
            else:
                if data[0] == 'MinStack':
                    output.append('')
                elif data[0] == 'getMin':
                    val = s.getMin()
                    output.append(f'{val}')
                elif data[0] == 'pop':
                    s.pop()
                    output.append('')
                elif data[0] == 'top':
                    val = s.top()
                    output.append(f'{val}')


    with open(out_path, 'w') as f:
        for out in output:
            f.writelines(f'{out}\n')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            cases = gen()
            for case in cases:
                f.writelines(f'{case}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))