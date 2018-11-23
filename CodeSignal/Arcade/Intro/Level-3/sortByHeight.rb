def sortByHeight a
  b = a.select{|n| n != -1}.sort
  a.map {|n| n == -1 ? -1 : b.shift}
end

# puts sortByHeight([-1, 150, 190, 170, -1, -1, 160, 180]).inspect
