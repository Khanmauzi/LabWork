SELECT productnumber,AVG(QUANTITY)
FROM sales
WHERE SALESPERSONNUMBER=137
GROUP BY productnumber
ORDER BY productnumber;