from Banana import exploder, to_string

file = open("words_grande.txt","r") # open file and get handler 
dict_list = file.read().split() # make a list from the file 
file.close() 

for i in range(len(dict_list)): # loop over dict list, make list of tuples which consist of a 
                                # word, and a version that has been sorted 

    res = exploder(dict_list[i]) # turn word into list of chars 
    res.sort()                   # sort list 
    res = to_string(res)         # turn list back into string 
    dict_list[i] = (res,dict_list[i]) # add word and sorted word to list of tuples 

dict_list.sort() # sort list of tuples according to sorted word, so we can use binary search 

print(dict_list)