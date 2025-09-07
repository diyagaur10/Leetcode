# Write your MySQL query statement below
SELECT  product_name , SUM(unit) AS unit
FROM Products
LEFT JOIN Orders
ON Products.product_id =  Orders.product_id
WHERE Orders.order_date <= '2020-02-29' AND Orders.order_date >= '2020-02-01'
GROUP BY Orders.product_id
HAVING SUM(unit ) >= 100 