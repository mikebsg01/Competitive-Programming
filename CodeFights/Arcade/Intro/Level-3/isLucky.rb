def isLucky n
  s = 0
  n.to_s.chars.each_with_index{|c, i| s += i >= (n.to_s.size/2) ? -1*c.to_i : c.to_i}
  s == 0
end

# puts isLucky(1230), isLucky(239017)
