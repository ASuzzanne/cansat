import os
def get_list():
    files = os.listdir('.')
    n = 0
    ls = []
    for i in files :
        if "error" in i:continue
        if '.txt' in i:
            print(n,':',i)
            ls.append(i)
            n = n+1
    return ls