# Steps to evaluate an expression

1. Remove any space - *if there are any*
1. Traverse the expression string to look for the following in order - *P.E.M.D.A.S*
    - Parentheses
        > Any operations inside parentheses should take precedence
        - Call the parsing function continuously until the base of the nested parentheses is reached.
        ```java
        // For this epression string:
        c(a + b)
        
        parser() {
            c * parser() {
                // Do next step here.
                return calculate(a + b)
            }
        }
        ```
    - Operators
        - Store a map of the indices to operators
        - Start with the `/ * ^` then `+ -`
1.  

## List of the operators
| Operator | ASCII Code |
|:--------:|:----------:|
| + | 43 |
| - | 45 |
| * | 42 |
| / | 47 |
| % | 37 |
| ^ | 94 |


Soon to add the following functions
```
sqrt()
log()
sin()
sin-1()
cos()
cos-1()
tan()
tan-1()
```