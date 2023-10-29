cfg = {
    # num of testcase
    'N' : 100,

    # Random seed
    'seed' : 0,

    # Boundary of matrix.length
    'm_lower' : 1,
    'm_upper' : 300,

    # Boundary of matrix[i].length
    'n_lower' : 1,
    'n_upper' : 300,

    # Boundary of matrix[i][j]
    'value_lower' : -1e9,
    'value_upper' : 1e9,

    # Boundary of target
    'target_lower' : -1e9,
    'target_upper' : 1e9,

    # Probability of target occurance
    'prob_target' : 0.3,

    # testcase output path
    'save_path' : './testcase',

    # solution methods
    'sols' : ['sol_1', 'sol_2']
}