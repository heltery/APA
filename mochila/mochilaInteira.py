#---------------- IMPORTANDO AS BIBLIOTECAS---------------
import sys
import timeit
import numpy as np


#---------------- LENDO O ARQUIVO DE INSTANCIAS ---------------
if len(sys.argv) != 2:
    arq = open("instancias/mochila2500.txt.txt","r")	#Lê o arquivo
else:
    arq = open("instancias/"+sys.argv[1],"r")
mat_nx2 = []
for j in arq:
	mat_nx2.append(map(int,j.split()))

#---------------- INICIALIZAÇÃO DA MATRIZ ---------------

def Init_mat(lines,columns):						
	mat = np.zeros((lines,columns),dtype=int)
	return mat

#---------------- FUNÇÃO DE DEFINIÇÃO DA MOCHILA ---------------

def MaxMochila(mat_nx2):
    mat = Init_mat(mat_nx2[0][0]+1,mat_nx2[0][1]+1) 
    for j in range(1,mat_nx2[0][0]+1):
        for w in range(1,mat_nx2[0][1]+1):
            if(mat_nx2[j][0] > w):  				
                mat[j][w] = mat[j-1][w] 
            else:
                col = [w-mat_nx2[j][0] if w-mat_nx2[j][0]>0 else 0]
                mat[j][w] = max(mat[j-1][w] , mat[j-1][col] + mat_nx2[j][1])
    return(mat)


def GetMochila(mat,mat_nx2):
    col = len(mat[0])-1
    elements = []
    for row in range(len(mat)-1,-1,-1):
        if(mat[row][col] != mat[row-1][col]):
            elements.append(row)
            col = abs(col-mat_nx2[row][0])
    return(elements)


#---------------- CHAMADAS ---------------
mat = MaxMochila(mat_nx2)

print("Valor Arrecadado na Mochila:{}\nItens Escolhidos:{}".format(mat[-1][-1],GetMochila(mat,mat_nx2))) #Printa mat