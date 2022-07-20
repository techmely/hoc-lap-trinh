# Practical exam: 120 minutes

1. (3 points) The greatest common divisor (GCD) refers to the greatest positive integer that is a common divisor for a given pair of positive integers. Write a program that repeatedly prompts a user for numbers until the user enters two positive interger numbers. Once two valid numbers are entered, the program finds the GCD of the entered numbers and print out the result. If the user enters anything other than a valid number catch it with a try/except and put out an appropriate message and ignore the number. For example, enter -1, bob and 10, 15 and match the output below.

Enter a positive integer number: **-1**

The number must be positive.

Enter a positive integer number: **bob**

The number must be a positive number.

**10**

**15**

**GCD of 10 , 15 is 5**

2. (3 points) Given an list of integer numbers in the text file “List.txt”. Write a program to read through the file and compute the average of even numbers. For example, enter a file name “List.txt” or leave it blank and match the output below.

Enter file:**List.txt**

**Avg = 5.0**

3. (4 points) Write a program to manage wage of grading assignments including name, course, number of assignments, price per assignment, total and tax. The program reads data from the file “Database.txt” and save to the database file Wage.sqlite using the following table schema.

Grade (Nam, Course, NumOfAs, Price, Total, Tax)

Where:

Total = NumOfAs \* Price

Tax = 10% of Total if Total >= 2000000, otherwise, Tax =0.

The program prints the wage of grading Python and sorted in ascending order by NumOfAs. The output should be as follows:

Wage list:

| Name | Course | NumOfAs | Price   | Total     | Tax      |
| ---- | ------ | ------- | ------- | --------- | -------- |
| Anh  | Python | 30      | 15000.0 | 450000.0  | 0.0      |
| Tuan | Python | 160     | 15000.0 | 2400000.0 | 240000.0 |
