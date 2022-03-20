# Steps to evaluate an expression

## Parsing
1. Remove any space - *if there are any*
1. Traverse the expression string to look for the following in order
    - Parentheses
        - Any operations inside parentheses should take precedence
        - Calls the parsing function continuously until the base of the nested parentheses is reached.
        ```java
        // For this epression string:
        ((((a + b))))
        
        parser() {
            parser() {
                parser() {
                    parser() {
                        // Do next step here.
                        a + b
                    }
                }
            }
        }
        ```
    - Operators
        - Store a map of the indices to operators
1.  

## Calculating







### List of the operators
| Operator | ASCII Code |
|:--------:|:----------:|
| + | 43 |
| - | 45 |
| * | 42 |
| / | 47 |
| % | 37 |
| ^ | 94 |

These commands will be added in the future

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