/* You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.
   You are given an array of employees employees where:
          * employees[i].id is the ID of the ith employee.
          * employees[i].importance is the importance value of the ith employee.
          * employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.
   Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.

          Example 1:
                Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
                Output: 11
                Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
                They both have an importance value of 3.
                Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.

          Example 2:
                Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
                Output: -3
                Explanation: Employee 5 has an importance value of -3 and has no direct subordinates.
                Thus, the total importance value of employee 5 is -3.
*/



class Solution {
public:
    
    int ImpSum = 0;
    
    void AddSum(vector<Employee*> employees, int id)
    {
        for(int i = 0; i < employees.size(); i++)
        {
            if(employees[i]->id == id)
            {
                ImpSum += employees[i]->importance;
            
                if(employees[i]->subordinates.size() == 0)
                {
                    return;
                }
                for(int j = 0; j < employees[i]->subordinates.size(); j++)
                {
                    AddSum(employees , employees[i]->subordinates[j]);
                }
            }
        }
    }
        
    int getImportance(vector<Employee*> employees, int id)
    {
        AddSum(employees , id);
        
        return ImpSum;
    }
};



