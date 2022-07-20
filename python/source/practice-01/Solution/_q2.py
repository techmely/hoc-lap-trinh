filename = input("Enter file: ")

if not len(filename.strip()):
    filename = "List.txt"
fhandle = open(filename)

count, total = 0, 0

for line in fhandle:
    nums = line.strip().split()
    for num in nums:
        try:
            n = int(num)
            if n % 2 == 0:
                count, total = count+1, total+n
        except:
            continue

print("Avg = ", total/count if count else 0)
