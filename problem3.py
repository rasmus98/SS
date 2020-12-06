import numpy as np
n = int(10e6)
rate = 0.01
specificity = 0.993
sensitivity = 0.998
allergic = np.random.rand(n)<rate
positive = np.where(allergic,sensitivity,1-specificity)>np.random.rand(n)

print("3a:")
print("P(T=1)=",np.mean(positive))
print("P(T=-1)=",np.mean(~positive))
print("3b:")
print("P(A=0|T=1)=",np.mean(~allergic[~positive]))
print("3c:")
print("P(A=1|T=1)=",np.mean(allergic[positive]))