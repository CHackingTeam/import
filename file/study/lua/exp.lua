#!/usr/bin/lua

PRI_table={
    ["-"]=1,["+"]=1,
    ["*"]=2,["/"]=2,
    ["("]=3,[")"]=3}
SYMBOL={
    '-','+','*','/'}
count_function={
    ["-"]=function(x1,x2) return x1-x2 end,
    ["+"]=function(x1,x2) return x1+x2 end,
    ["*"]=function(x1,x2) return x1*x2 end,
    ["/"]=function(x1,x2) return x1/x2 end
}

count_stack={}
count_stack_size=0
symbol_stack={}
symbol_stack_size=0
srand_table={}
express=""

function init()
    count_stack_size=0
    count_stack={}
    symbol_stack_size=0
    symbol_stack={}
    express=""
end

function rand_(l)
    local i=1
    local exp=""
    while i<=l do
        if i%2==0 then
           exp=exp .. SYMBOL[math.random(1,4)]
        else
           exp=exp .. tostring(math.random(1,9))
        end
        i=i+1
    end
    return exp
end

function rand_exp()
    local i=0
    local len
    local exp_
    while true do
       len=math.random(3,9)
        if len%2==0 then
           len=len+1
        end
        exp_=rand_(len)
        srand_table[i]=exp_
        i=i+1
        if i>10000000 then
           return 
        end
    end
end

function gs(x)
    if symbol_stack_size>0 and PRI_table[x]<=PRI_table[symbol_stack[symbol_stack_size]] then
       express=express .. symbol_stack[symbol_stack_size]
       symbol_stack_size=symbol_stack_size-1
       gs(x)
    else
       symbol_stack_size=symbol_stack_size+1
       symbol_stack[symbol_stack_size]=x
    end
end

function install(x)
    symbol_stack_size=symbol_stack_size+1
    symbol_stack[symbol_stack_size]=x
end

function find(x,table)
    for index,v in ipairs(table) do
        if x==v then
            return true
        end
    end
    return false
end

function count(n1_,n2_,cr)
    n1=tonumber(n1_)
    n2=tonumber(n2_)
    c=count_function[cr](n1,n2)
    return tostring(c)
end

function  exp_suffix(exp)
    local i=1
    while true do
       x=string.sub(exp,i,i)
       if  i%2==1  then
            express=express .. x
       else
           if not symbol_stack[1] or PRI_table[symbol_stack[symbol_stack_size]]<PRI_table[x] then
              install(x)
            else
              gs(x)
           end
       end
       i=i+1
       if string.len(exp)<i then
           break
       end
    end
    i=symbol_stack_size
    while true do
       if i<=0 then
          break
       end
       express=express .. symbol_stack[i]
       i=i-1
    end
   return express
end

function exp_count(express)
    local i=1
    while true do
        x=string.sub(express,i,i)
        if find(x,SYMBOL) then
           number1=count_stack[count_stack_size-1]
           number2=count_stack[count_stack_size]
           newber=count(number1,number2,x)
           count_stack_size=count_stack_size-1
           count_stack[count_stack_size]=newber
        else
           count_stack_size=count_stack_size+1
           count_stack[count_stack_size]=x
        end
        i=i+1
        if i>string.len(express) then
           break
        end
   end
end


rand_exp()
for x,v in ipairs(srand_table) do
    init()
    expr=exp_suffix(v)
    exp_count(expr)
    print(x,v,expr,count_stack[1])
end

--print(exp_suffix("6-3"))





