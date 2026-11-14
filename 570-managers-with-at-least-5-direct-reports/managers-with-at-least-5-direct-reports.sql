# Write your MySQL query statement below
SELECT e2.name FROM Employee E1 JOIN Employee E2 ON E2.id=E1.managerId GROUP BY e2.id HAVING COUNT(e2.id)>=5;