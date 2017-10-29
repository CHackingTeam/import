function foo(str)
    if type(str)~="string" then
        error("string expected:",1)
    end
end

foo({x=1})

