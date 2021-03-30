import random as rd 
from itertools import chain, combinations

def all_subsets(combo_string : str, length : int) -> list:
    a = combinations(combo_string, length)  
    y = [' '.join(i) for i in a] 
    return y

def binary_search(numbers: list, key: str) -> str:
    low = 0                    #initial search range
    high = len(numbers) - 1

    while high >= low:
        mid = (high + low) // 2 #check "middle" element
        stringer = numbers[mid]
        mate = stringer[0]
        if mate < key:
            low = mid + 1       #if its too low, raise the middle
        elif mate > key:
            high = mid - 1      #if its too high, remove right sife from search engine
        else:
            return mid          #if it is not too low or high then it must be equal
    return -1 # not found

def exploder(stringer: str) -> list:
    lister = [0] * len(stringer)
    for i in range(len(stringer)):
        lister[i] = stringer[i]
    return lister        

def to_string(lister: list) -> str:
    stringer = ""
    for i in range(len(lister)):
        stringer += lister[i]
    return stringer

def bananagram_sim(num : int) -> str:
    lister = ["j","j","k","k","q","q","x","x","z","z","b","b","b","c","c","c","f","f","f","h","h","h","m","m","m"
              "p","p","p","v","v","v","w","w","w","y","y","y","g","g","g","g",
              "l","l","l","l","l"
              "d","d","d","d","d","d","s","s","s","s","s","s","u","u","u","u","u","u"
              "n","n","n","n","n","n","n","n",
              "t","t","t","t","t","t","t","t","t",
              "r","r","r","r","r","r","r","r","r",
              "o","o","o","o","o","o","o","o","o","o","o",
              "i","i","i","i","i","i","i","i","i","i","i",
              "a","a","a","a","a","a","a","a","a","a","a","a","a",
              "e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e","e",]
    stringer = []
    for i in range(num): # get a num amount of random letters 
        stringer.append(lister[rd.randint(0,len(lister))])

    return stringer


def bananaater():
    letter_list = bananagram_sim(15) # use this for simulating a psuedorandom hand

    # length = int(input("Enter number of variables: "))
    # letter_list = [0] * length 

    # for i in range(length):
    #     letter_list[i] = input("Enter letter " + str(i + 1) + ": ")

   # print("Letter list: " + str(letter_list))

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
    
    query_word = letter_list # copy over letter list so we can make a string out of it 
    query_word.sort() # sort first 
    query_word = to_string(query_word) # make a word 

    # print("word is: " + query_word)

    res = binary_search(dict_list,query_word) # search for word 

    if res != -1: 
        print("It worked! : " + str(dict_list[res])) 
        return
    else: 
        remaining_letters = to_string(letter_list)
        word_list = []
        counter = int(len(remaining_letters))

        while(remaining_letters):
            query_word = remaining_letters
            print("query word is",query_word)
            subsets = all_subsets(query_word,counter)
            
            #print(subsets)
            subsets_no_dup = []
            for i in subsets:
                if i not in subsets_no_dup:
                    subsets_no_dup.append(i)
            #print(subsets_no_dup)
            for elem in subsets_no_dup:
                elem = exploder(elem)
                elem.sort()
                elem = to_string(elem)
                elem = elem.strip()
                #print("elem:",elem)
                res = binary_search(dict_list,elem)
                #print("res:",res)
                if res > -1:
                    word_list.append(dict_list[res][1])
                    print("elem is",elem)
                    remaining_letters = remaining_letters.replace(elem,"")
                    print("remaining letters is",remaining_letters)
                    break
            if(counter < 1):
                print("error, you will need to draw more")
                break
            counter-=1
    print(word_list)

if __name__ == "__main__":
    bananaater()