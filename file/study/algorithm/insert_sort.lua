
a={1,5,7,2,3,9}


function insert_sort_ch(i,j)
    local s;
    for v=j-1,i,-1 do
        s=a[v]
        a[v]=a[v+1]
        a[v+1]=s
    end
end
function insert_sort()
 for j=2,#a do
    local i=j-1
    while i>0 do
        if a[j]<a[i] then
            insert_sort_ch(i+1,j)
            break
        end
        if i==1 then
            insert_sort_ch(1,j)
            break
        end
        i=i-1
    end
 end
end


insert_sort()
for v,x in ipairs(a) do
    print(v,x)
end




         

        



