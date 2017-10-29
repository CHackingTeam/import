function foo(n)    
     --foo(n-1) 
     return foo(n-1)+1
end


foo(1000000000)

