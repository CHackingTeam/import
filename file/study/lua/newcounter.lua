function newcounter()
    local i=0
    return function()
        i=i+1
        return i
    end
end

c1=newcounter()
print(c1())
print(c1())

