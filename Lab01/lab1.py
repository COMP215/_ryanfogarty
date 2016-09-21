#1. random strings with lengths
#2. writecode that takes in a data file of strings, have it produce sorted lexographic order and store it
#3. promgram that uses both programs that will create three distinct random collections of strings and sorts them such that it takesatleast five min to run code. 


import random
def randomStrings(numOfStrings):
    letters = ['a', 'b', 'c', 'd','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    theFile1 = open('lab1a','w')
    theFile2 = open('lab1b','w')
    theFile3 = open('lab1c','w')
    for a in range(numOfStrings):
        newstring = ""
        random.seed()
        randomNumber = random.randrange(1,len(letters))
        for x in range(1,randomNumber):
            randomNum2 = random.randrange(1,randomNumber)
            newstring = newstring + letters[randomNum2]
        #print(newstring, "Length is :", (randomNumber - 1))
        theFile1.write(newstring)
        theFile1.write("\n")
        for x in range(1,randomNumber):
            randomNum2 = random.randrange(1,randomNumber)
            newstring = newstring + letters[randomNum2]
        #print(newstring, "Length is :", (randomNumber - 1))
        theFile2.write(newstring)
        theFile2.write("\n") 
        for x in range(1,randomNumber):
            randomNum2 = random.randrange(1,randomNumber)
            newstring = newstring + letters[randomNum2]
            #print(newstring, "Length is :", (randomNumber - 1))
        theFile3.write(newstring)
        theFile3.write("\n")        
        
        
def sortStrings():
    inStringsA = open('lab1a','r')
    inStringsB = open('lab1b','r')
    inStringsC = open('lab1c','r')
    
    listOfStringsA = []
    for strings in inStringsA:
        listOfStringsA.append(strings)
    a = sorted(listOfStringsA)
    
    listOfStringsB = []
    for strings in inStringsB:
        listOfStringsB.append(strings)
    b = sorted(listOfStringsB)
    
    listOfStringsC = []
    for strings in inStringsC:
        listOfStringsC.append(strings)
    c = sorted(listOfStringsC)
    
    outStringsA = open('lab1a','w')
    outStringsB = open('lab1b','w')
    outStringsC = open('lab1c','w')
    
    for strings in a:
        outStringsA.write(strings)
    for strings in b:
        outStringsB.write(strings)
    for strings in c:  
        outStringsC.write(strings)
        

        
        
    
def runSimulation():
    
    import time
    timeout = time.time() + 60*5   # 5 minutes from now
    while True:
        list1 = randomStrings(10)
        sortStrings()
        if time.time() > timeout:
            break
             
    
    
def main():
    #randomStrings(6)
    #sortStrings()
    runSimulation()
    
main()
