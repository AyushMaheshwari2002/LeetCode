/*  Table: Person
        +-------------+---------+
        | Column Name | Type    |
        +-------------+---------+
        | id          | int     |
        | email       | varchar |
        +-------------+---------+
        id is the primary key column for this table.
        Each row of this table contains an email. The emails will not contain uppercase letters.

    Write an SQL query to report all the duplicate emails.
    Return the result table in any order.
    The query result format is in the following example.

            Example 1:
                    Input: 
                    Person table:
                    +----+---------+
                    | id | email   |
                    +----+---------+
                    | 1  | a@b.com |
                    | 2  | c@d.com |
                    | 3  | a@b.com |
                    +----+---------+
                    Output: 
                    +---------+
                    | Email   |
                    +---------+
                    | a@b.com |
                    +---------+
                    Explanation: a@b.com is repeated two times.
*/



SELECT Email FROM Person
GROUP BY Email           #GROUP BY clause is used to group rows that have the same values.
HAVING COUNT(*) > 1;     #COUNT(*) function counts the total rows in the table, including the NULL values.



        
