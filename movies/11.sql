/*
write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in,
starting with the highest rated
*/
--we are going to join movies, stars ve people tables

SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
JOIN ratings ON movies.id = ratings.movie_id
WHERE name = 'Chadwick Boseman' ORDER BY rating DESC LIMIT 5;


