import numpy as np

def CountingSort(nums):
    """CountingSort"""
    N = 100
    count = np.zeros(N);
    for k in nums:
        count[k] += 1
    rst = list()
    i = 0
    while i < N:
        if count[i] > 0:
            count[i] -= 1
            rst.append(i)
        else:
            i += 1
    return rst


def CountingSortByDict(nums):
    """CountingSort by Dict"""
    N = 100
    countdict = dict()
    for k in nums:
        try:
            countdict[k] += 1
        except KeyError:
            countdict[k] = 1
    rst = list()
    i = 0
    while i < N:
        if i in countdict and countdict[i] > 0:
            rst.append(i)
            countdict[i] -= 1
        else:
            i += 1
    return rst



if __name__ == '__main__':
    nums = [1,2,5,6,2,1,32,7,20,6,99,33]
    print(nums)
    print(CountingSort(nums))
    print(CountingSortByDict(nums))
