import matplotlib.pyplot as plt
import getfile
import time
import json
import numpy as np
def convert(n): 
    return time.strftime("%H:%M:%S", time.gmtime(n*2))
while 1:
    f = getfile.get_list()
    loc = f[int(input('Enter File No. : '))]
    f= open(loc,"r")
    Rdata = f.read()
    Rdata = Rdata.split('\n')
    f.close()
    data_dict = {}
    for i in Rdata:
        if '{"t":' in i:
            dct = json.loads(i)
            ke = list(dct.keys())
            stat = list(data_dict.keys())
            if len(stat) >0:
                for j in ke:
                    data_dict[j].append(dct[j])
                    # print(j,dct[j])
            else:
                for j in ke:
                    data_dict[j]=[dct[j]]

    # print(data_dict)
    bg=[]
    data_keys = list(data_dict.keys())
    f, axes = plt.subplots(3)
    for x in data_keys:
        if x== 'Time':continue
        bg.append(float(max(data_dict[x])))
        axes[0].plot(data_dict[x],label=x)
    axes[0].set_title("Line")
    axes[0].plot([],label='total time:'+str(convert(len(data_dict[data_keys[0]]))))
    axes[0].legend()
    bar_x = data_keys[0:-1]
    bar_y = bg
    print(bar_x,bar_y)
    axes[1].set_title("Bar")
    axes[1].bar(bar_x,bar_y)
    axes[2].set_title("Pie")
    axes[2].pie(bar_y, labels = bar_x,shadow = True)
    figManager = plt.get_current_fig_manager()
    # figManager.window.showMaximized()
    figManager.window.state('zoomed')
    # print(dir(figManager))
    plt.show()   

