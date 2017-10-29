
function dofile_(filename)
    local f=assert(loadfile(filename))
    return f()
end

dofile_("N.lua")


