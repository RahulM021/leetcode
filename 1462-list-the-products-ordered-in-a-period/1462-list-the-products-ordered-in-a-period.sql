# Write your MySQL query statement below
select p.product_name as product_name,sum(o.unit) as unit
from Products p inner join Orders o on p.product_id=o.product_id
where o.order_date like '2020-02-__'
group by o.product_id
having sum(o.unit)>=100