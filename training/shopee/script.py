import os
import pandas as pd
import json
from tqdm import tqdm
from sklearn import preprocessing
le = preprocessing.LabelEncoder()

with open("contacts.json", "r") as f:
    contacts = json.load(f)
df = pd.DataFrame(contacts)
groups = list(range(len(df)))

target_cols = ["Email", "Phone", "OrderId"]
for col in target_cols:
    df[col] = le.fit_transform(df[col])

parent = list(range(len(df)))


def find(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = find(parent[x])
        return parent[x]


def union(x, y):
    parent[find(x)] = find(y)


df_email = df[df['Email'] != 0]
df_phone = df[df['Phone'] != 0]
df_order = df[df['OrderId'] != 0]

df_email_sort = df_email.sort_values(by=['Email'])
for i in tqdm(range(len(df_email_sort) - 1)):
    if df_email_sort.iloc[i].Email == df_email_sort.iloc[i + 1].Email:
        union(df_email_sort.iloc[i].Id, df_email_sort.iloc[i+1].Id)
df_phone_sort = df_phone.sort_values(by=['Phone'])

for i in tqdm(range(len(df_phone_sort) - 1)):
    if df_phone_sort.iloc[i].Phone == df_phone_sort.iloc[i + 1].Phone:
        union(df_phone_sort.iloc[i].Id, df_phone_sort.iloc[i+1].Id)

df_order_sort = df_order.sort_values(by=['OrderId'])
for i in tqdm(range(len(df_order_sort) - 1)):
    if df_order_sort.iloc[i].OrderId == df_order_sort.iloc[i + 1].OrderId:
        union(df_order_sort.iloc[i].Id, df_order_sort.iloc[i+1].Id)

for i in tqdm(range(len(df))):
    find(i)

df["parent"] = parent
new_df = df.sort_values("parent")

map_ = {k: [] for k in parent}
for i in range(len(parent)):
    map_[parent[i]].append(i)

contacts = df["Contacts"].values
res = list(range(len(df)))
for _, children in tqdm(map_.items()):
    children = sorted(children)
    tmp = sum([contacts[child] for child in children])
    for child in children:
        res[child] = f'{"-".join([str(x) for x in children])}, {tmp}'

df["ticket_trace/contact"] = res
submit = df[["Id", "ticket_trace/contact"]]
submit.columns = ["ticket_id", "ticket_trace/contact"]
submit.to_csv("submission.csv", index=False)
