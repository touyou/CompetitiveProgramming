ciph = "fsdz{Fdhvdu_flskhu_lv_fodvvlfdo_flskhu}"
ciph_list = list(ciph)

for i in range(len(ciph_list)):
    if ciph_list[i] != '{' and ciph_list[i] != '}':
        ciph_list[i] = chr(ord(ciph_list[i]) - 3)

print("".join(ciph_list))
