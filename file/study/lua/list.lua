#! /usr/bin/lua 

cout=1
list=nil

for line in io.lines() do
	if cout>5 then
		break
	end
	list={next=list,values=line}
	cout=cout+1
end
print(list.values)
while list do
	print (list.values)
	list=list.next
end

