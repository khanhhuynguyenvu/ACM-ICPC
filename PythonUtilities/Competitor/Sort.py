array = [5, 3, 12, 4, 1, 100]
# Sort ascending
print(sorted(array))
# Sort descending
print(sorted(array, key=lambda x: -x))
array = [{'Apl': 12}, {'Jb': 22}, {'Sam': 14}]
print(sorted(array, key=lambda x: list(x.values())[0]))
# for i in array:
#     x = list(i.values())[0]
#     print(x)
# Sort value and return as index
a = [5, 3, 12, 4, 1, 100]
print(sorted(range(len(a)), key=lambda x: a[x]))


