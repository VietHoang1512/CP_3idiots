import pandas as pd 
import numpy as np 

submission = pd.read_csv("submission.csv")
key = pd.read_csv("output.csv")

print(submission.equals(key))