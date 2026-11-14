# Write your MySQL query statement below
SELECT E1.name as name,E2.bonus as bonus FROM Employee E1 LEFT JOIN Bonus E2 ON E1.empId=E2.empId WHERE E2.bonus IS NULL OR E2.bonus<1000;