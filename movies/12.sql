 --write a SQL query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred

SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name ='Bradley Cooper' AND movies.title IN
(SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE name ='Jennifer Lawrence');
