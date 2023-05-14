# [ANSWER START]








# [ANSWER END]

#
# 시험 문제
# 
# 답안은 위의 [ANSWER START]와 [ANSWER END] 사이에 작성함
# 아래의 STEP.1~7을 수행하여 RESULTS의 결과를 출력하는 MyInteger 클래스와 MyDerivedInteger 클래스를 개발함
# MyDerivedInteger 클래스는 MyInteger 클래스를 base 클래스로 함
# 수행 결과는 아래 RESULTS와 동일해야 함 (결과값, 대소문자, 철자, 빈공간 등 모든 정보가 동일해야 함)
#

''' STEP.1
'''

variable_01 = MyInteger(1)
print('#01: {} ==>> {}'.format(variable_01, type(variable_01)))

variable_02 = MyInteger(2.0)
print('#02: {} ==>> {}'.format(variable_02, type(variable_02)))

variable_03 = MyInteger('3')
print('#03: {} ==>> {}'.format(variable_03, type(variable_03)))

variable_04 = MyInteger([4,5,6])
print('#04: {} ==>> {}'.format(variable_04, type(variable_04)))

''' STEP.2
'''

variable_05 = variable_01 + '10'
print('#05: {} ==>> {}'.format(variable_05, type(variable_05)))

variable_06 = variable_05 + 100
print('#06: {} ==>> {}'.format(variable_06, type(variable_06)))

variable_07 = variable_06 + 1000.0
print('#07: {} ==>> {}'.format(variable_07, type(variable_07)))

variable_08 = variable_07 + [10000, 100000]
print('#08: {} ==>> {}'.format(variable_08, type(variable_08)))

''' STEP.3
'''

variable_09 = variable_08._get_MyInteger()
print('#09: {} ==>> {}'.format(variable_09, type(variable_09)))

''' STEP.4
'''

variable_10 = MyDerivedInteger(1)
print('#10: {} ==>> {}'.format(variable_10, type(variable_10)))

variable_11 = MyDerivedInteger(2.0)
print('#11: {} ==>> {}'.format(variable_11, type(variable_11)))

variable_12 = MyDerivedInteger('3')
print('#12: {} ==>> {}'.format(variable_12, type(variable_12)))

variable_13 = MyDerivedInteger([4,5,6])
print('#13: {} ==>> {}'.format(variable_13, type(variable_13)))

''' STEP.5
'''

variable_14 = variable_12 + '10'
print('#14: {} ==>> {}'.format(variable_14, type(variable_14)))

variable_15 = variable_14 + 100.0
print('#15: {} ==>> {}'.format(variable_15, type(variable_15)))

variable_16 = variable_15 + 1000
print('#16: {} ==>> {}'.format(variable_16, type(variable_16)))

variable_17 = variable_16 + [10000, 100000]
print('#17: {} ==>> {}'.format(variable_17, type(variable_17)))

variable_18 = variable_17 + MyInteger('10000')
print('#18: {} ==>> {}'.format(variable_18, type(variable_18)))

''' STEP.6
'''

variable_19 = variable_18._get_MyInteger()
print('#19: {} ==>> {}'.format(variable_19, type(variable_19)))

''' STEP.7
'''

variable_20 = variable_12._get_Original()
print('#20: {} ==>> {}'.format(variable_20, type(variable_20)))

print('#21: {} {} {}'.format(variable_01 == 1, variable_02 == 2, variable_03 == 3))
print('#22: {} {} {}'.format(variable_10 == 1, variable_11 == 2, variable_12 == 3))
print('#23: {} {} {}'.format(variable_10 == 1, variable_11 == 2.0, variable_12 == '3'))

''' RESULTS

#01: 1 ==>> <class '__main__.MyInteger'>
#02: 2 ==>> <class '__main__.MyInteger'>
#03: 3 ==>> <class '__main__.MyInteger'>
#04: 0 ==>> <class '__main__.MyInteger'>
#05: 11 ==>> <class '__main__.MyInteger'>
#06: 111 ==>> <class '__main__.MyInteger'>
#07: 1111 ==>> <class '__main__.MyInteger'>
#08: 1111 ==>> <class '__main__.MyInteger'>
#09: 1111 ==>> <class '__main__.MyInteger'>
#10: <1:<class 'int'>,1:<class 'int'>> ==>> <class '__main__.MyDerivedInteger'>
#11: <2:<class 'int'>,2.0:<class 'float'>> ==>> <class '__main__.MyDerivedInteger'>
#12: <3:<class 'int'>,3:<class 'str'>> ==>> <class '__main__.MyDerivedInteger'>
#13: <0:<class 'int'>,[4, 5, 6]:<class 'list'>> ==>> <class '__main__.MyDerivedInteger'>
#14: <13:<class 'int'>,13:<class 'int'>> ==>> <class '__main__.MyDerivedInteger'>
#15: <113:<class 'int'>,113:<class 'int'>> ==>> <class '__main__.MyDerivedInteger'>
#16: <1113:<class 'int'>,1113:<class 'int'>> ==>> <class '__main__.MyDerivedInteger'>
#17: <1113:<class 'int'>,1113:<class 'int'>> ==>> <class '__main__.MyDerivedInteger'>
#18: <11113:<class 'int'>,11113:<class 'int'>> ==>> <class '__main__.MyDerivedInteger'>
#19: <11113:<class 'int'>,11113:<class 'int'>> ==>> <class '__main__.MyDerivedInteger'>
#20: 3 ==>> <class 'str'>
#21: True True True
#22: True True False
#23: True True True
'''