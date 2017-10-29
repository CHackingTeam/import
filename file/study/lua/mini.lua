#! /usr/bin/lua 

a={}
c=1
for i in io.lines() do
    if c==6 then
		break
	end
	a[c]=tonumber(i)
	c=c+1
end

function min(a)
	local mi=1
	local m=a[mi]
	for i,v in ipairs(a) do
		if v>m then
			mi=i
			m=v
		end
	end
	return mi,m
end
c,d=min(a)
print(c,d)

	

    
