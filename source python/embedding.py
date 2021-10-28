import tensorflow as tf
from tensorflow.keras import layers,Model,Input
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from scipy.cluster.hierarchy import dendrogram, linkage
import os






file=open('C:/Users/pedov/Gui_for_dev/gui/number_of_nodes.txt')
number_of_nodes=int(file.read())

file2=open('C:/Users/pedov/Gui_for_dev/gui/nodes.txt')
names=[]
names2=[]
for line in file2:
    names.append(line)
for x in names :
    x=x.replace('\n','')
    
    names2.append(x)
datas=pd.read_csv('C:/Users/pedov/Gui_for_dev/gui/sortie.csv')

X=datas.iloc[:,0]
Y=datas.iloc[:,1]
model=tf.keras.Sequential()
#model.add(layers.Dense(10))
model.add(layers.Dense(128,activation='linear'))
model.add(layers.Dense(number_of_nodes,activation='softmax'))





model.compile(loss=tf.keras.losses.CategoricalCrossentropy())

lists=np.eye(number_of_nodes,number_of_nodes,dtype=int)
#treee=[]
#for c in range(0,number_of_nodes):
#    treee.append(lists[c].tolist())
#treee

li=[]
li2=[]
for ite in X :
    li.append(lists[int(ite)])
    
for ite2 in Y :
    li2.append(lists[int(ite2)])
X_train=np.array(li2)
Y_train=np.array(li)


model.fit(x=X_train,y=Y_train,epochs=5)

input_layer=model.variables

tensor_array=input_layer[0]

nodes_embedded=[]
for i in range(0,number_of_nodes):
    nodes_embedded.append(tensor_array[i].numpy().tolist())



arr=np.array(nodes_embedded)
arr2=np.array(nodes_embedded)
fin=arr.reshape(number_of_nodes,128)
fichier=open("vectors_.txt",mode='w')
np.savetxt(fichier,fin,fmt='%2.4f')
fichier.close()

Z = linkage(fin,method='ward',metric='euclidean')
figuressss=plt.figure(figsize=[27,15])
dendrogram(Z,labels=names2,orientation='top',color_threshold=0,ax=figuressss.add_subplot(1,1,1))
figuressss.savefig(fname='C:/Users/pedov/Gui_for_dev/gui/figure_finale_raisonable.jpg',quality=95,dpi=200)#,quality=95,dpi=2000,orientation='landscape'












