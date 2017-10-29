#! /usr/bin/lua

function sub(a,b)
	if a>b then
		return a-b
	else
		return b-a
	end
end

func={['add']=function(a,b) return a+b end,['sub']=sub}

print(func["sub"](1,2))


