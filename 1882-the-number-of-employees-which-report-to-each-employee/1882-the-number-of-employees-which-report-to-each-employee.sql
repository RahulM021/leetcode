# Write your MySQL query statement below
select e1.employee_id,e1.name,count(*) as reports_count,ROUND(avg(e2.age)) as average_age
from Employees e1 INNER JOIN Employees e2 on e1.employee_id=e2.reports_to
group by e2.reports_to
order by e1.employee_id
