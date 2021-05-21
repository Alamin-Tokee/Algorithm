Approach 1 (Using subtraction)
Complexity:
Time:O(n) worst case
Space:O(1)

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == b)  
       return a;
   
    return (a > b)? gcd(a-b, b): gcd(a, b-a);
} 