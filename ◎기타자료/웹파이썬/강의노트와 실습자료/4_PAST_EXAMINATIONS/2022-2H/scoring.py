############################################################
# (A) ANSWER START

class MyClass:

    numberOfObject = 0

    def __init__(self, givenId):
        self.id = givenId
        MyClass.numberOfObject += 1
        self.wordDictionary = {}

    def getId(self):
        return self.id

    def setId(self, givenId):
        if type(givenId) == type(1) or type(givenId) == type(1.0):
            self.id = "XXXX"
        else:
            self.id = givenId

    def getNumberOfObject(self):
        return MyClass.numberOfObject

    def storeWordlistAsDictionary(self, givenWordlist):
        givenWordlist.sort()
        for item in givenWordlist:
            if item in self.wordDictionary:
                self.wordDictionary[item] += 1
            else:
                self.wordDictionary[item] = 1
        return self.wordDictionary

    def getWordCount(self, givenKey):
        if givenKey in self.wordDictionary:
            return (givenKey, self.wordDictionary[givenKey])
        else:
            return False

    def getWordList(self):
        if self.wordDictionary.__len__() != 0:
            tmpList = []
            for item in self.wordDictionary:
                tmpList.append(item)
            return sorted(tmpList)
        else:
            return False


class MyDerivedClass(MyClass):

    def __init__(self, givenId="****"):
        super().__init__(givenId)

    def __str__(self):
        rep = ""
        length = self.wordDictionary.__len__()
        count = 0
        for item in self.wordDictionary:
            rep += "{}".format(item)
            count += 1
            if count < length:
                rep += ','
        return ("<" + rep + ">")

    def __gt__(self, target):
        if self.getWordList().__len__() > target.getWordList().__len__():
            return True
        else:
            return False

    def __add__(self, target):
        tmpDictionary = {}
        for item in self.wordDictionary:
            tmpDictionary[item] = self.wordDictionary[item]  # or use copy()
        for item in target.wordDictionary:
            if item in tmpDictionary:
                tmpDictionary[item] += target.wordDictionary[item]
            else:
                tmpDictionary[item] = target.wordDictionary[item]
        tmpObject = MyDerivedClass("0000")
        tmpObject.wordDictionary = tmpDictionary
        return tmpObject

# (A) ANSWER END
############################################################

############################################################
# (B) STANDARD ANSWER START

class StandardMyClass:

    numberOfObject = 0

    def __init__(self, givenId):
        self.id = givenId
        StandardMyClass.numberOfObject += 1
        self.wordDictionary = {}

    def getId(self):
        return self.id

    def setId(self, givenId):
        if type(givenId) == type(1) or type(givenId) == type(1.0):
            self.id = "XXXX"
        else:
            self.id = givenId

    def getNumberOfObject(self):
        return StandardMyClass.numberOfObject

    def storeWordlistAsDictionary(self, givenWordlist):
        givenWordlist.sort()
        for item in givenWordlist:
            if item in self.wordDictionary:
                self.wordDictionary[item] += 1
            else:
                self.wordDictionary[item] = 1
        return self.wordDictionary

    def getWordCount(self, givenKey):
        if givenKey in self.wordDictionary:
            return (givenKey, self.wordDictionary[givenKey])
        else:
            return False

    def getWordList(self):
        if self.wordDictionary.__len__() != 0:
            tmpList = []
            for item in self.wordDictionary:
                tmpList.append(item)
            return sorted(tmpList)
        else:
            return False


class StandardMyDerivedClass(StandardMyClass):

    def __init__(self, givenId="****"):
        super().__init__(givenId)

    def __str__(self):
        rep = ""
        length = self.wordDictionary.__len__()
        count = 0
        for item in self.wordDictionary:
            rep += "{}".format(item)
            count += 1
            if count < length:
                rep += ','
        return ("<" + rep + ">")

    def __gt__(self, target):
        if self.getWordList().__len__() > target.getWordList().__len__():
            return True
        else:
            return False

    def __add__(self, target):
        tmpDictionary = {}
        for item in self.wordDictionary:
            tmpDictionary[item] = self.wordDictionary[item]  # or use copy()
        for item in target.wordDictionary:
            if item in tmpDictionary:
                tmpDictionary[item] += target.wordDictionary[item]
            else:
                tmpDictionary[item] = target.wordDictionary[item]
        tmpObject = StandardMyDerivedClass("0000")
        tmpObject.wordDictionary = tmpDictionary
        return tmpObject

# (B) STANDARD ANSWER END
############################################################

############################################################
# (C) SCORING START


totalScore = 0


def printAnswers(yourAnser, rightAnswer):
    print("     Your Answer  : (", yourAnser,
          ") -->> Right Answer : (", rightAnswer, ")")


# Header
print("\n-[ start ]----------------------")

# Question 1
try:
    myObject1 = MyClass("1234")
    standardMyObject1 = StandardMyClass("1234")

    if standardMyObject1.getId() == myObject1.getId():
        totalScore += 7
        print("[01] Question - Correct [+7].")
        #printAnswers(myObject1.getId(), standardMyObject1.getId())
    else:
        print("[01] Question - Fail.")
        printAnswers(myObject1.getId(), standardMyObject1.getId())
except:
    print("[01] Question - Exception.")

# Question 2
try:
    myObject1 = MyClass("0000")
    myObject1.setId(1)
    result = [myObject1.getId()]
    myObject1.setId(1.0)
    result.append(myObject1.getId())
    myObject1.setId("5678")
    result.append(myObject1.getId())

    standardMyObject1 = StandardMyClass("0000")
    standardMyObject1.setId(1)
    standardResult = [standardMyObject1.getId()]
    standardMyObject1.setId(1.0)
    standardResult.append(standardMyObject1.getId())
    standardMyObject1.setId("5678")
    standardResult.append(standardMyObject1.getId())

    if result == standardResult:
        totalScore += 7
        print("[02] Question - Correct [+7].")
        #printAnswers(result, standardResult)
    else:
        print("[02] Question - Fail.")
        printAnswers(result, standardResult)
except:
    print("[02] Question - Exception.")

# Question 3
try:
    myObject1 = MyClass("0000")
    standardMyObject1 = StandardMyClass("0000")

    if myObject1.getNumberOfObject() == standardMyObject1.getNumberOfObject():
        totalScore += 7
        print("[03] Question - Correct [+7].")
        #printAnswers(myObject1.getNumberOfObject(),
        #             standardMyObject1.getNumberOfObject())
    else:
        print("[03] Question - Fail.")
        printAnswers(myObject1.getNumberOfObject(),
                     standardMyObject1.getNumberOfObject())
except:
    print("[03] Question - Exception.")

# Question 4
try:
    givenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    standardGivenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]

    myObject1 = MyClass("1004")
    standardMyObject1 = StandardMyClass("1004")

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    if result == standardResult:
        totalScore += 7
        print("[04] Question - Correct [+7].")
        #printAnswers(result, standardResult)
    else:
        print("[04] Question - Fail.")
        printAnswers(result, standardResult)
except:
    print("[04] Question - Exception.")

# Question 5
try:
    givenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    standardGivenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]

    myObject1 = MyClass("1004")
    standardMyObject1 = StandardMyClass("1004")

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    result = myObject1.getWordCount("apple")
    standardResult = standardMyObject1.getWordCount("apple")

    if result == standardResult:
        myObject1 = MyClass("1004")
        standardMyObject1 = StandardMyClass("1004")

        result = myObject1.getWordCount("apple")
        standardResult = standardMyObject1.getWordCount("apple")

        if result == standardResult:
            totalScore += 7
            print("[05] Question - Correct [+7].")
            #printAnswers(result, standardResult)
        else:
            print("[05] Question - Fail.")
            printAnswers(result, standardResult)
    else:
        print("[05] Question - Fail..")
        printAnswers(result, standardResult)
except:
    print("[05] Question - Exception.")

# Question 6
try:
    givenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    standardGivenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]

    myObject1 = MyClass("1004")
    standardMyObject1 = StandardMyClass("1004")

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    result = myObject1.getWordList()
    standardResult = standardMyObject1.getWordList()

    if result == standardResult:
        myObject1 = MyClass("1004")
        standardMyObject1 = StandardMyClass("1004")

        result = myObject1.getWordList()
        standardResult = standardMyObject1.getWordList()

        if result == standardResult:
            totalScore += 7
            print("[06] Question - Correct [+7].")
            #printAnswers(result, standardResult)
        else:
            print("[06] Question - Fail.")
            printAnswers(result, standardResult)
    else:
        print("[05] Question - Fail..")
        printAnswers(result, standardResult)
except:
    print("[06] Question - Exception.")

# Question 7
try:
    givenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    standardGivenWordlist = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]

    myObject1 = MyDerivedClass("1004")
    standardMyObject1 = StandardMyDerivedClass("1004")

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    result = myObject1.storeWordlistAsDictionary(givenWordlist)
    standardResult = standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist)

    result = str(myObject1)
    standardResult = str(standardMyObject1)

    if result == standardResult:
        totalScore += 7
        print("[07] Question - Correct [+7].")
        #printAnswers(result, standardResult)
    else:
        print("[07] Question - Fail.")
        printAnswers(result, standardResult)
except:
    print("[07] Question - Exception.")

# Question 8
try:
    givenWordlist1 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    givenWordlist2 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple", "banana"]

    standardGivenWordlist1 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    standardGivenWordlist2 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple", "banana"]

    myObject1 = MyDerivedClass("1004")
    myObject1.storeWordlistAsDictionary(standardGivenWordlist1)

    myObject2 = MyDerivedClass("1005")
    myObject2.storeWordlistAsDictionary(standardGivenWordlist2)

    standardMyObject1 = StandardMyDerivedClass("1004")
    standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist1)

    standardMyObject2 = StandardMyDerivedClass("1005")
    standardMyObject2.storeWordlistAsDictionary(standardGivenWordlist2)

    result = myObject1 > myObject2
    standardResult = standardMyObject1 > standardMyObject2

    if result == standardResult:
        totalScore += 7
        print("[08] Question - Correct [+7].")
        #printAnswers(result, standardResult)
    else:
        print("[08] Question - Fail.")
        printAnswers(result, standardResult)
except:
    print("[08] Question - Exception.")

# Question 9
try:
    givenWordlist1 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    givenWordlist2 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple", "banana"]

    standardGivenWordlist1 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple"]
    standardGivenWordlist2 = ["pear", "apple", "pear", "apple", "apple", "pear", "apple", "banana"]

    myObject1 = MyDerivedClass("1004")
    myObject1.storeWordlistAsDictionary(givenWordlist1)

    myObject2 = MyDerivedClass("1005")
    myObject2.storeWordlistAsDictionary(givenWordlist2)

    myObject3 = myObject1 + myObject2
    result = myObject3.getWordList()

    standardMyObject1 = StandardMyDerivedClass("1004")
    standardMyObject1.storeWordlistAsDictionary(standardGivenWordlist1)

    standardMyObject2 = StandardMyDerivedClass("1005")
    standardMyObject2.storeWordlistAsDictionary(standardGivenWordlist2)

    standardMyObject3 = standardMyObject1 + standardMyObject2
    standardResult = standardMyObject3.getWordList()

    if result == standardResult:
        checkResult = myObject1.getWordList()
        checkStandardResult = standardMyObject1.getWordList()

        if checkResult == checkStandardResult:

            checkResult = myObject1.getWordCount('apple')
            checkStandardResult = standardMyObject1.getWordCount('apple')

            if checkResult == checkStandardResult:

                if myObject3.getWordCount('apple') == standardMyObject3.getWordCount('apple'):
                    totalScore += 7
                    print("[09] Question - Correct [+7].")
                    #printAnswers(result, standardResult)
                    #printAnswers(myObject3.getWordCount('apple'),
                    #             standardMyObject3.getWordCount('apple'))
                    #printAnswers(checkResult, checkStandardResult)
                else:
                    print("[09] Question - Fail.")
                    printAnswers(myObject3.getWordCount('apple'), standardMyObject3.getWordCount('apple'))
            else:
                print("[09] Question - Fail..")
                printAnswers(checkResult, checkStandardResult)
        else:
            print("[09] Question - Fail...")
            printAnswers(checkResult, checkStandardResult)
    else:
        print("[09] Question - Fail....")
        printAnswers(result, standardResult)
except:
    print("[09] Question - Exception.")

# Question 10
try:
    myObject1 = MyDerivedClass()
    standardMyObject1 = StandardMyDerivedClass()

    result = myObject1.getId()
    standardResult = standardMyObject1.getId()

    if result == standardResult:
        totalScore += 7
        print("[10] Question - Correct [+7].")
        #printAnswers(result, standardResult)
    else:
        print("[10] Question - Fail.")
        printAnswers(result, standardResult)
except:
    print("[10] Question - Exception.")

# Total
print("-[ end   ]----------------------\n")
#print("[**] Total Score : ", totalScore, "(MAX: 70)")
print("[**] Total Score : ", totalScore)

# (C) SCORING END
############################################################
