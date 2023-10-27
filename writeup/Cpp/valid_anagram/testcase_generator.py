import os
import random
from config import cfg

NUM_ENGLISH_LETTER = 26
random.seed(cfg['seed'])

def gen():
    anagram_prob = float(cfg['anagram_prob'])
    str_lower = int(cfg['str_lower'])
    str_upper = int(cfg['str_upper'])

    if random.random() < anagram_prob:
        data = ''
        for i in range(NUM_ENGLISH_LETTER):
            data += chr(97 + i) * random.randint(str_lower, str_upper // NUM_ENGLISH_LETTER)
        
        str_list = list(data)
        random.shuffle(str_list)
        s = ''.join(str_list)

        random.shuffle(str_list)
        t = ''.join(str_list)
    else:
        data = ''
        length_prob = float(cfg['length_prob'])
        if random.random() < length_prob:
            s_len, t_len = random.sample(range(str_lower, str_upper), 2)
            
            for i in range(NUM_ENGLISH_LETTER):
                data += chr(97 + i) * random.randint(str_lower, 2 if s_len // NUM_ENGLISH_LETTER == 0 else s_len // NUM_ENGLISH_LETTER)
            
            str_list = list(data)
            random.shuffle(str_list)
            s = ''.join(str_list)

            data = ''
            for i in range(NUM_ENGLISH_LETTER):
                data += chr(97 + i) * random.randint(str_lower, 2 if t_len // NUM_ENGLISH_LETTER == 0 else t_len // NUM_ENGLISH_LETTER)
            
            str_list = list(data)
            random.shuffle(str_list)
            t = ''.join(str_list)
        else:
            s_len = random.randint(str_lower, str_upper // NUM_ENGLISH_LETTER)
            for i in range(NUM_ENGLISH_LETTER):
                data += chr(97 + i) * random.randint(str_lower, 2 if s_len // NUM_ENGLISH_LETTER == 0 else s_len // NUM_ENGLISH_LETTER)
            
            str_list = list(data)
            random.shuffle(str_list)
            s = ''.join(str_list)
            
            str_list = list(data)
            random.shuffle(str_list)
            t = ''.join(str_list)

    return s, t

def sol(in_path, out_path):
    flag = False
    with open(in_path, 'r') as f:
        s, t = f.read().splitlines()
        
        if len(s) == len(t):
            countS, countT = {}, {}

            for i in range(len(s)):
                countS[s[i]] = 1 + countS.get(s[i], 0)
                countT[t[i]] = 1 + countT.get(t[i], 0)
            
            if countS == countT:
                flag = True
        
    with open(out_path, 'w') as f:
        if flag:
            f.writelines('true')
        else:
            f.writelines('false')

if __name__ == '__main__':
    os.makedirs(cfg['save_path'], exist_ok=True)
    save_path = cfg['save_path']

    num_testcase = cfg['N']
    for i in range(num_testcase):
        with open(os.path.join(save_path, f'{i}.in'), 'w') as f:
            s, t = gen()
            
            f.writelines(f'{s}\n')
            f.writelines(f'{t}\n')

        sol(os.path.join(save_path, f'{i}.in'), os.path.join(save_path, f'{i}.out'))