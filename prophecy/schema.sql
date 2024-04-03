CREATE TABLE IF NOT EXISTS students2(
    id INTEGER NOT NULL,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE IF NOT EXISTS houses(
    h_id INTEGER NOT NULL,
    house TEXT NOT NULL,
    head TEXT NOT NULL,
    PRIMARY KEY(h_id,house)
);

CREATE TABLE IF NOT EXISTS assignments(
    student_id INTEGER NOT NULL,
    house_id INTEGER NOT NULL,
    FOREIGN KEY(student_id) REFERENCES students2(id),
    FOREIGN KEY(house_id) REFERENCES houses(h_id),
    PRIMARY KEY(student_id, house_id)
);

