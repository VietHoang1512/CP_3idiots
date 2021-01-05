import os
import numpy as np

n_test_case = 20
option = list("fs")
mod = int(1e9+7)

test_case_dir = r"D:\VH\CP_3idiots\applied_algorithm\test_case"
for test_case in range(n_test_case):
    test_case_dir_ = os.path.join(test_case_dir, str(test_case))
    os.makedirs(test_case_dir_, exist_ok=True)
    n = np.random.randint(1, 50)
    elems = [str(n)] + list(np.random.choice(option, size=n))
    dp = np.zeros((int(6e3), int(6e3)),dtype=int)
    dp[1][0] = 1

    for i in range(1,n+1):
        if elems[i]=='f':
            for j in range(n):
                dp[i + 1][j + 1] = dp[i][j]
        else:
            sum_ = 0
            for j in range(n-1, -1,-1):
                sum_ = (sum_ + dp[i][j]) % mod
                dp[i + 1][j] = sum_
    sum_ = 0
    for j in range(n):
        sum_ = (sum_ + dp[n][j]) % mod
    inp_fp = os.path.join(test_case_dir_, "hoang.inp")
    out_fp = os.path.join(test_case_dir_, "hoang.out")
    with open(inp_fp, "w") as f:
        f.write("\n".join(elems))
    with open(out_fp, "w") as f:
        f.write(str(sum_))        