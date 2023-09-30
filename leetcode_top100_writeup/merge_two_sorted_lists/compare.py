import os
import time
import shutil
import subprocess
from resource import getrusage, RUSAGE_CHILDREN 
from config import cfg

def compare():
    num_testcase = cfg['N']
    sols = cfg['sols']
    testcase_path = './testcase'
    for sol in sols:
        runtimes = []
        memories = []
        sol_exec_path = f'./build/{sol}/{sol}'
        output_folder = f'{sol}_output'
        os.makedirs(output_folder, exist_ok=True)
        for i in range(num_testcase):
            start_time = time.time()
            p = subprocess.Popen(f'./{sol_exec_path} < {testcase_path}/{i}.in > {output_folder}/{i}.out', shell=True)
            p.wait()
            end_time = time.time()
            memories.append(getrusage(RUSAGE_CHILDREN).ru_maxrss / 10**6 * 1024)
            runtimes.append(round((end_time - start_time) * 1000))
        
        print('\n{:^10s}{:^10s}{:^10s}'.format('Testcase', 'Result', 'Runtime'))
        print('=' * 30)

        wa_count = 0
        results = []
        for i in range(num_testcase):
            with open(f'{testcase_path}/{i}.out', 'r') as f:
                ans_gt = f.read().splitlines()

            with open(f'{output_folder}/{i}.out', 'r') as f:
                ans = f.read().splitlines()

            if ans != ans_gt:
                result = 'WA'
                wa_count += 1
            else:
                result = 'AC'

            results.append(result)
            print('{:^10s}{:^10s}{:^10s}'.format('#' + str(i), result, str(runtimes[i]) + 'ms'))

        print('\n========={:^10s}========='.format('Result'))
        print('{:<9s}:   {:>3s} %'.format('AC Rate', str(round((1 - wa_count / num_testcase) * 100))))
        print('{:<9s}:   {:>3s} ms'.format('Runtime', str(round(sum(runtimes) / num_testcase))))
        print('{:<9s}:   {:>3s} KB'.format('Memory', str(round(sum(memories) / num_testcase))))
        print('\n')

        # shutil.rmtree(output_folder)

if __name__ == '__main__':
    compare()