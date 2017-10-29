#! /usr/bin/lua

set_={}
function set(l)
    for _,i in ipairs(l) do
        set_[i]=true
    end
end

set({"return","bool","char","int"})


