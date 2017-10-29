
print "enter your expression...."
local l=io.read()
local func=assert(loadstring("return " .. l))
print(func())

