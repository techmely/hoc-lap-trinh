class Anagram:
    def __init__(self, string1: str, string2: str):
        self.string1 = string1
        self.string2 = string2

ana1 = Anagram('heart', 'earth')
ana2 = Anagram('python', 'typhon')
ana3 = Anagram('Foot', 'tooth')

def check(ana):
    dict_list1 = dict()
    dict_list2 = dict()
    for i in ana.string1:
        i.lower()
        dict_list1[i] = dict_list1.get(i, 0) + 1
    for j in ana.string2:
        j.lower()
        dict_list2[j] = dict_list2.get(j, 0) + 1
    t1 = sorted(dict_list1.items())
    t2 = sorted(dict_list2.items())
    print(f"Anagram('{ana.string1}','{ana.string2}') -> {t1 == t2}")

check(ana1)
check(ana2)
check(ana3)