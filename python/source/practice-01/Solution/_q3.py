
import sqlite3

conn = sqlite3.connect("Wage.sqlite")
cur = conn.cursor()

init_script = """
    DROP TABLE IF EXISTS Grade;
    CREATE TABLE Grade(Name TEXT, Course TEXT, NumOfAs INTEGER, Price FLOAT, Total FLOAT, Tax FLOAT)
"""
cur.executescript(init_script)


fhandle = open("Database.txt")

insert_script = """INSERT INTO Grade (
    Name, Course, NumOfAs, Price, Total, Tax
) VALUES (?, ?, ?, ?, ?, ?)"""


def calc(num, price):
    total = num*price
    tax = 0
    if total >= 2000000:
        tax = 0.1*total
    return (total, tax)


line_no = 0
for line in fhandle:
    if line_no < 2:
        line_no += 1
        continue

    data = line.strip().split()

    if len(data) == 4:
        name, course, num_of_as, price = data[0], data[1], int(
            data[2]), float(data[3])
        (total, tax) = calc(num_of_as, price)

        cur.execute(insert_script, (name, course,
                    num_of_as, price, total, tax))

query = "SELECT * FROM Grade ORDER BY NumOfAs ASC"
cur.execute(query)
data = cur.fetchall()


# print result
def format_output(arr):
    result = ""
    for word in arr:
        result += str(word).ljust(12)
    return result


print("Wage list:")
print(format_output(("Name", "Course", "NumOfAs", "Price", "Total", "Tax")))
for datum in data:
    print(format_output(datum))
