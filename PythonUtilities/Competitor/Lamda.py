numbers = [1, 2, 3, 4, 4]
new_numbers = map(lambda x: 9 if x==4 else x, numbers)
print(list(new_numbers))

# Filter and map

# ar_a = list(reversed(a))
# tmp_x = next(filter(lambda x: x != 9, ar_a.copy()), 9)
# res_a = list(map(lambda x: '9' if x == tmp_x else str(x), ar_a.copy()))
# tmp_x = next(filter(lambda x: x != 1 and x != 0, ar_a), 0)
# repl = '1' if tmp_x == ar_a[0] else '0'
# res_b = list(map(lambda x: repl if x == tmp_x else str(x), ar_a))
# # print(res_a, res_b)
# return abs(int(''.join(res_a)) - int(''.join(res_b)))
