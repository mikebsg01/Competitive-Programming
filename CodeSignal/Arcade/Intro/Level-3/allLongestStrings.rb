def allLongestStrings a
  m = a.max_by(&:size).size
  a.select{|s| s.size == m}
end

# puts allLongestStrings(["aba", "aa", "ad", "vcd", "aba"]).inspect
