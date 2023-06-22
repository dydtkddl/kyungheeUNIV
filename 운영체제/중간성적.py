import matplotlib.pyplot as plt
import numpy as np

txt = '''12
7
2
9
7
8
2
6
0
4
21
7
3
5
14
26
19
6
0
19
26
14
7
17
14
16
27
7
8
16
5
9
7
18
0
13
8
17
19
17
23
6'''
txt = [float(a.strip()) for a in txt.split('\n')]
txt = sorted(txt , reverse=True)
print(np.mean(txt))
print(np.sqrt(txt))
print(len(txt))
print(txt.index(17))