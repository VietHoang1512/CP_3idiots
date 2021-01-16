import os


test_case_dir = r"D:\VH\CP_3idiots\final_exam\4\python\input"
for fn in os.listdir(test_case_dir):
    print("*"*20)
    fp = os.path.join(test_case_dir, fn)
    with open(fp, 'r') as f:
        inp = f.read().strip().split("\n")
    nQ = inp[0].split()
    n = int(nQ[0])
    Q = int(nQ[1])
    





# with open("INP.TXT", "r") as f:
#     inp = f.read()
# f = open("OUT.TXT", "w")
# f.write(inp)
