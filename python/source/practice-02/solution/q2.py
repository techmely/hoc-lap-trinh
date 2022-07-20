fname = input("Enter file name: ")
if len(fname) < 1:
    fname = 'mbox-short.txt'
fh = open(fname)
count = 0
su = 0.0

for line in fh:
    if not line.startswith("X-DSPAM-Confidence:"):
        continue
    su = su + float(line[20:])
    count = count +1

s = su/count
print("Average spam confidence:", s)