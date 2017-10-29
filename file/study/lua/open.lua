print "input file name.."
f=io.read()
if not f then 
    print("not file  name..")
    return 
end
fname,msg=io.open(f,"r")
if not fname then print("open error"..msg) end



