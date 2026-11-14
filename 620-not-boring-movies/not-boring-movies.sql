# Write your MySQL query statement below
SELECT * FROM Cinema WHERE id IN (
    SELECT id FROM Cinema where id%2!=0
) AND description!='boring'
ORDER BY rating DESC;