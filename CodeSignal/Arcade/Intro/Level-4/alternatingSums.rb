def alternatingSums a
    x = y = 0
    a.each_with_index { |v,i|
        if i % 2 != 0 then
            y += v
        else
            x += v            
        end
    }
    [x, y]
end

puts alternatingSums([1,2,7,4,8,6]).inspect
