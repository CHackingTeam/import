names={"peter","paul","mary"}
grades={mary=10,paul=7,peter=8}

table.sort(names,function(n1,n2) return grades[n1]>grades[n2] end)

for vule in ipairs(names) do print(names[vule]) end


