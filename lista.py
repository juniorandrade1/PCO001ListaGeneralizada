import time
start = time.time()
arquivo = open('in', 'r')
lista = [];
for linha in arquivo:
    lista.append(linha.split(' '))
arquivo.close()
print (lista)
end = time.time()
print(end - start)