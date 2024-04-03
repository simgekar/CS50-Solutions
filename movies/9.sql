SELECT  DISTINCT name FROM people
JOIN movies ON movie_id = movies.id
JOIN stars ON people.id = person_id
WHERE year =2004 ORDER BY people.birth;
