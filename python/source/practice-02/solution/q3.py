import sqlite3
from prettytable import PrettyTable

conn = sqlite3.connect("grades.sqlite")
cur = conn.cursor()

init_script = """
    DROP TABLE IF EXISTS Student;
    
    CREATE TABLE Student(
        Name TEXT,
        term int,
        grade float,
        Scholar TEXT
    );
"""
cur.executescript(init_script)

data_raw = open('Data.txt')
line_no = 0
for line in data_raw:
    if line_no < 2:
        line_no += 1
        continue

    line = line.strip().split()
    name = line[0]
    term = int(line[1])
    grade = float(line[2])
    check_grade = line[2]
    check_grade = check_grade[0]
    check_grade = int(check_grade)
    if check_grade>= 8:
        scholar = "A"
    elif check_grade >= 7:
        scholar = "B"
    else:
        scholar = ''

    cur.execute("""INSERT INTO Student(Name, term, grade ,Scholar) VALUES (?,?,?,?)""", (name, term, grade, scholar)
    )
    conn.commit()

table = PrettyTable(["Name", "term", "grade" ,"Scholar"])
query = "SELECT * FROM Student ORDER BY grade DESC"
cur.execute(query)
data = cur.fetchall()
for server in data:
    table.add_row(server)
print(table)
cur.close()
