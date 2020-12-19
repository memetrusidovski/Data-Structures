sort = [3,44,38,5,47,15,36,26,27,2,46,4,19,50,48]

swap = True
index = len(sort)

while(swap):
    swap = False
    for i in range(index - 1):
        if sort[i] > sort[i+1]:
            sort[i], sort[i+1] = sort[i+1], sort[i]
            swap = True


print(sort)