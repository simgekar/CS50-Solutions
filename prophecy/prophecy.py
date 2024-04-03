# Assignments table did not work like I want,
import csv
from cs50 import SQL
db = SQL("sqlite:///roster.db")

with open("students.csv","r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        # Add students to students2 table
        db.execute(
            "INSERT OR IGNORE INTO students2 (id,student_name) VALUES (?,?)" ,
            row["id"],
            row["student_name"]
        )
        houses = list()
        if row["house"] not in houses:
            houses.append(row["house"])

        db.execute(
            "INSERT OR IGNORE INTO houses (h_id,house,head) VALUES (?,?,?)",
            (houses.index(row["house"])+1),
            row["house"],
            row["head"]
        )

        db.execute(
            "INSERT OR IGNORE INTO assignments (student_id, house_id) VALUES (?,?)",
            row["id"],
            houses.index(row["house"])+1
        )




