SELECT movies.title, ratings.rating from movies
JOIN ratings ON movies.id = ratings.movie_id
WHERE year = 2010 ORDER BY ratings.rating DESC, movies.title;

